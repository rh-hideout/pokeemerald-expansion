"""
Local development server for the Expansion Data Parser.

Serves static files (index.html, pokemon_data.js) and handles
POST /api/edit requests to write changes back to source files.

Usage:
    python3 serve.py              # default port 8090
    python3 serve.py 9000         # custom port
"""
import json
import sys
from http.server import HTTPServer, SimpleHTTPRequestHandler
from pathlib import Path

from pokemon_data_parser import load_config, generate_pokemon_data
from pokemon_data_writer import apply_edit

SCRIPT_DIR = Path(__file__).parent
config = load_config()

# Resolve repo root from config
repo_root = Path(config.get("repo_root", "../.."))
if not repo_root.is_absolute():
    repo_root = (SCRIPT_DIR / repo_root).resolve()


class Handler(SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        # Serve from repo root so sprite paths (graphics/pokemon/...) resolve
        try:
            super().__init__(*args, directory=str(repo_root), **kwargs)
        except BrokenPipeError:
            pass  # Browser closed connection early — harmless

    def translate_path(self, path):
        """Serve tool files (index.html, pokemon_data.js) from SCRIPT_DIR,
        everything else (sprites etc.) from repo_root."""
        # Strip query string and fragment
        clean = path.split('?', 1)[0].split('#', 1)[0]
        if clean in ('/', '/index.html', '/pokemon_data.js'):
            fname = 'index.html' if clean == '/' else clean.lstrip('/')
            return str(SCRIPT_DIR / fname)
        if clean == '/favicon.ico':
            # Avoid noisy 404s
            return str(SCRIPT_DIR / 'favicon.ico')
        return super().translate_path(path)

    def do_POST(self):
        if self.path == '/api/edit':
            self._handle_edit()
        elif self.path == '/api/regenerate':
            self._handle_regenerate()
        else:
            self.send_error(404)

    def _read_json_body(self):
        length = int(self.headers.get('Content-Length', 0))
        body = self.rfile.read(length)
        return json.loads(body) if body else {}

    def _send_json(self, data, status=200):
        body = json.dumps(data).encode()
        self.send_response(status)
        self.send_header('Content-Type', 'application/json')
        self.send_header('Content-Length', len(body))
        self.end_headers()
        self.wfile.write(body)

    def _handle_edit(self):
        try:
            edit = self._read_json_body()
            result = apply_edit(repo_root, edit)
            self._send_json(result, 200 if result.get('ok') else 400)
        except Exception as e:
            self._send_json({'ok': False, 'error': str(e)}, 500)

    def _handle_regenerate(self):
        try:
            output_path = SCRIPT_DIR / config.get("output", "pokemon_data.js")
            twop_path = None
            if config.get("twop_data"):
                twop_path = Path(config["twop_data"])
                if not twop_path.is_absolute():
                    twop_path = (SCRIPT_DIR / twop_path).resolve()

            generate_pokemon_data(repo_root, output_path, twop_path=twop_path)
            self._send_json({'ok': True, 'message': 'Regenerated pokemon_data.js'})
        except Exception as e:
            self._send_json({'ok': False, 'error': str(e)}, 500)

    def log_message(self, format, *args):
        # Quiet logging — only show POST requests
        try:
            if args and 'POST' in str(args[0]):
                super().log_message(format, *args)
        except TypeError:
            pass


def main():
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8090
    server = HTTPServer(('', port), Handler)
    print(f"Expansion Data Parser server")
    print(f"  Repo: {repo_root}")
    print(f"  URL:  http://localhost:{port}")
    print(f"  Edit mode available via POST /api/edit")
    print(f"  Press Ctrl+C to stop")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nStopped.")


if __name__ == '__main__':
    main()

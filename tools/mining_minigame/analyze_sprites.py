import json
import os
import sys

xcoord_table = [
    0,2,4,6,
    0,2,4,6,
    0,2,4,6,
    0,2,4,6
]

ycoord_table = [
    0,0,0,0,
    2,2,2,2,
    4,4,4,4,
    6,6,6,6
]

def read_4bpp_file(file_path):
    data_32bit_chunks = []

    try:
        with open(file_path, 'rb') as file:
            # Read the entire file content
            byte_data = file.read()

            # Iterate over the data in 4-byte (32-bit) chunks
            for i in range(0, len(byte_data), 4):
                # Combine up to 4 bytes into a 32-bit integer
                chunk = byte_data[i:i+4]
                # Convert bytes to an integer (big-endian)
                chunk_value = int.from_bytes(chunk, byteorder='big')
                data_32bit_chunks.append(chunk_value)

    except FileNotFoundError:
        print(f"Error: File not found at {file_path}")
    except Exception as e:
        print(f"An error occurred: {e}")

    return data_32bit_chunks

def IsTileTransparent(tile, data):
    first_tile_starting_idx = (xcoord_table[tile] + ycoord_table[tile] * 8) * 8
    second_tile_starting_idx = (xcoord_table[tile] + (ycoord_table[tile] + 1) * 8) * 8

    for row in range(first_tile_starting_idx, first_tile_starting_idx + 16):
        if data[row] > 0:
            return 1

    for row in range(second_tile_starting_idx, second_tile_starting_idx + 16):
        if data[row] > 0:
            return 1

    return 0

def turn_analysed_data_into_string(data, enum):
    result = "        "
    isTileToDigUp = "FALSE"

    for i in data:
        if i == 1:
            isTileToDigUp = "TRUE"
        elif i == 0:
            isTileToDigUp = "FALSE"
        result = result + isTileToDigUp + ", "

    result = result[:-1]
    result = "    [" + enum + "] = " + "{\n" + result + "\n" + "    },\n"
    return result

def get_id_by_path(data, filename, whichtype):
    for item in data[whichtype]:
        if item["path"] == filename:
            return item["id"]
    print(f"No ID found for the path '{filename}'.")
    quit()

def get_item_id(mining_id):
    item_name = mining_id.replace("MININGID_", "", 1)
    if item_name.startswith("DREAM_"):
        item_name = item_name[len("DREAM_"):]

    return {
        "EVER_STONE": "ITEM_EVERSTONE",
        "REVIVE_MAX": "ITEM_MAX_REVIVE",
        "ODD_KEY_STONE": "ITEM_ODD_KEYSTONE",
    }.get(item_name, "ITEM_" + item_name)

def get_tag(mining_id):
    name = mining_id.replace("MININGID_", "", 1)
    if name.startswith("STONE_"):
        return "MINING_TAG_STONE_" + name[len("STONE_"):].upper()
    name = {
        "HEART_SCALE": "HEARTSCALE",
        "HARD_STONE": "HARDSTONE",
    }.get(name, name)
    return "MINING_TAG_ITEM_" + name

def get_object_name(mining_id):
    return mining_id.replace("MININGID_", "", 1).lower()

def generate_object_data(json_data):
    lines = [
        "struct MiningObject",
        "{",
        "    enum Item itemId;",
        "    u16 tag;",
        "    const struct CompressedSpriteSheet *sheet;",
        "    const struct SpritePalette *palette;",
        "    const struct SpriteTemplate *template;",
        "};",
        "",
    ]

    objects = []
    for object_type in ("items", "stones"):
        for item in json_data[object_type]:
            mining_id = item["id"]
            name = get_object_name(mining_id)
            tag = get_tag(mining_id)
            gfx_path = item["path"].replace("./", "", 1).replace(".4bpp", ".png")
            if object_type == "stones":
                palette_path = "graphics/mining_minigame/stones/stones.pal"
                item_id = "ITEM_NONE"
            else:
                palette_path = "graphics/mining_minigame/items/fossil.pal" if name in ("skull_fossil", "armor_fossil") else gfx_path
                item_id = get_item_id(mining_id)

            lines.extend([
                f'static const u32 sMiningGfx_{name}[] = INCGFX_U32("{gfx_path}", ".4bpp.smol");',
                f'static const u16 sMiningPalette_{name}[] = INCGFX_U16("{palette_path}", ".gbapal");',
                "",
            ])
            objects.append((mining_id, name, tag, item_id))

    lines.extend(["static const struct CompressedSpriteSheet sMiningSheets[] =", "{"])
    for mining_id, name, tag, _ in objects:
        lines.append(f"    [{mining_id}] = {{sMiningGfx_{name}, 2048, {tag}}},")
    lines.extend(["};", "", "static const struct SpritePalette sMiningPalettes[] =", "{"])
    for mining_id, name, tag, _ in objects:
        lines.append(f"    [{mining_id}] = {{sMiningPalette_{name}, {tag}}},")
    lines.extend(["};", "", "static const struct SpriteTemplate sMiningTemplates[] =", "{"])
    for mining_id, name, tag, _ in objects:
        lines.extend([
            f"    [{mining_id}] =",
            "    {",
            f"        .tileTag = {tag},",
            f"        .paletteTag = {tag},",
            "        .oam = &sOamItem64x64,",
            "        .anims = gDummySpriteAnimTable,",
            "        .images = NULL,",
            "        .affineAnims = gDummySpriteAffineAnimTable,",
            "        .callback = SpriteCallbackDummy,",
            "    },",
        ])
    lines.extend([
        "};",
        "",
        "static const struct MiningObject sMiningObjects[] =",
        "{",
        "    [MININGID_NONE] =",
        "    {",
        "        .itemId = ITEM_NONE,",
        "        .tag = 0,",
        "        .sheet = NULL,",
        "        .palette = NULL,",
        "        .template = NULL,",
        "    },",
    ])
    for mining_id, name, tag, item_id in objects:
        lines.extend([
            f"    [{mining_id}] =",
            "    {",
            f"        .itemId = {item_id},",
            f"        .tag = {tag},",
            f"        .sheet = &sMiningSheets[{mining_id}],",
            f"        .palette = &sMiningPalettes[{mining_id}],",
            f"        .template = &sMiningTemplates[{mining_id}],",
            "    },",
        ])
    lines.extend(["};", ""])
    return "\n".join(lines)

def main():
    json_path = "./src/data/mining_minigame/object_tables.json"
    gfx_items = "./graphics/mining_minigame/items/"
    gfx_stones = "./graphics/mining_minigame/stones/"
    analysed_sprite_data = []
    contents = """// DO NOT MODIFY THIS FILE'S CONTENT! THE CONTENT OF THIS FILE IS AUTOGENERATED (tools/mining_minigame/analyze_sprites.py)! ONLY MODIFY THIS FILE IF YOU KNOW WHAT YOU ARE DOING!

static const u32 sSpriteTileTable[][16] = {
"""

    with open(json_path, "rb") as f:
        json_data = json.load(f)

    all_items = json_data["items"] + json_data["stones"]

    for item in all_items:
        image_binary = item["path"].replace(".png", ".4bpp")
        if not os.path.isfile(image_binary):
            print("Could not find " + image_binary + "file")
            sys.exit(1)
        data = read_4bpp_file(image_binary)
        for tile in range(0, 16):
            analysed_sprite_data.append(IsTileTransparent(tile, data))
        contents = contents + turn_analysed_data_into_string(analysed_sprite_data, "MINING_ENTITY_" + item["id"])
        analysed_sprite_data = []

    contents = contents + "};\n"

    with open('./src/data/mining_minigame/tile_data.h', 'w+') as file:
        file.write(contents)


if __name__ == "__main__":
    main()

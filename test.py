from preprocessor import Preprocessor
p = Preprocessor()
p.include("src/data/pokemon/species_info.h")
print(p.source())  # shows expanded preprocessed code

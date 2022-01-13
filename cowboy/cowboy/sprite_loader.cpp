#include "sprite_loader.h"

SpriteLoader SpriteLoader::instance;

SpriteLoader::SpriteLoader() {}

SpriteLoader &SpriteLoader::Get() { return instance; }

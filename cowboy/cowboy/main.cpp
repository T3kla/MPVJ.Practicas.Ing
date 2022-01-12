#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include "litegfx.h"
#include "stb_image.h"

#include "engine.h"
#include "world.h"

int main() {
  auto world = World();
  Engine::Run();
}

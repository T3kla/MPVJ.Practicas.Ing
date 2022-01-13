#pragma once

#include "litegfx.h"
#include "stb_image.h"

class SpriteLoader {
  friend class Engine;

private:                                       // SINGLETON
  SpriteLoader();                              //
  static SpriteLoader instance;                //
public:                                        //
  SpriteLoader(const SpriteLoader &) = delete; //
  static SpriteLoader &Get();                  //

private:
public:
  static void LoadSprites(); // TODO: load into arrays per animation
};

// // SpriteSheet Loading
// int w, h, c;
// pixels = stbi_load(file, &w, &h, &c, 4);
// if (!pixels)
// throw "Error loading image";

// // Texture Allocation
// texture = ltex_alloc(w, h, 0);
//
// // Texture Dump
// ltex_setpixels(texture, pixels);
//
// // Sprite Creation
// wall.reserve(16);
// for (size_t x = 0; x < 5; x++)
//     for (size_t y = 0; y < 3; y++) {
//         wall.emplace_back(new Sprite(
//             texture, { defSize / 2.f + defSize * x, defSize / 2.f + defSize *
//             y }, { defSize, defSize }, { 0.2f, 0.f }, { 0.4f, 1.f },
//             BLEND_SOLID));
//     }
//
// torch = new Sprite{ texture,     {0.f, 0.f},  {400.f, 400.f},
//                    {0.6f, 0.f}, {0.8f, 1.f}, BLEND_ALPHA };
//
// fire = new Sprite{ texture,    {0.f, 0.f},  {400.f, 400.f}, {0.8f, 0.f},
//                   {1.f, 1.f}, BLEND_ALPHA, {0.5f, 0.6f} };
//
// light = new Sprite{ texture,     {0.f, 0.f},  {5000.f, 5000.f},
//                    {0.4f, 0.f}, {0.6f, 1.f}, BLEND_MUL };
//
// fence.reserve(16);
// for (size_t x = 0; x < 5; x++)
//     for (size_t y = 0; y < 3; y++) {
//         fence.emplace_back(new Sprite(
//             texture, { defSize / 2.f + defSize * x, defSize / 2.f + defSize *
//             y }, { defSize, defSize }, { 0.f, 0.f }, { 0.2f, 1.f },
//             BLEND_ALPHA));
//     }
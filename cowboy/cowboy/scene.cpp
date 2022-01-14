#include "scene.h"

#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "engine_render.h"
#include "sprite_loader.h"
#include "stasis.h"

#include "oval_renderer.h"
#include "rect_renderer.h"
#include "sprite_renderer.h"
#include "sys_player.h"
#include "transform.h"

#include "vec.h"

#include <entt/entt.hpp>

Scene::Scene() {}
Scene::~Scene() {}

void Scene::Awake() {
  EngineRender::SetTitle(title);

  auto &reg = Engine::GetRegistry();

  // Player Instantiation
  const auto playerEntID = reg.create();
  player = Entity(playerEntID, &reg);
  reg.emplace<Transform>(playerEntID, &player, true, Vec2(100.f, 100.f),
                         Vec2(1.f, 1.f), 0.f);
  reg.emplace<SpriteRenderer>(
      playerEntID, &player, true, &SpriteLoader::sprPlayer, Vec2(0.f, 0.f),
      -90.f, Vec2(100.f, 100.f), Vec2(0.5f, 0.5f), 0, BLEND_ALPHA);
  reg.emplace<Camera>(playerEntID, &player, true, true, 1.f);

  auto pc = new SysPlayer();
  pc->entity = &player;
  pc->enable = true;

  // Suelo Random
  const auto floorID = reg.create();
  floor[0] = Entity(floorID, &reg);
  reg.emplace<Transform>(floorID, &floor[0], true, Vec2(0.f, 0.f),
                         Vec2(1.f, 1.f), 0.f);
  reg.emplace<SpriteRenderer>(
      floorID, &floor[0], true, &SpriteLoader::sprFloor01, Vec2(0.f, 0.f), 0.f,
      Vec2(100.f, 100.f), Vec2(0.5f, 0.5f), 0, BLEND_SOLID);
}

void Scene::Start() {}

void Scene::Update() {}

void Scene::Fixed() {}

void Scene::Quit() {}

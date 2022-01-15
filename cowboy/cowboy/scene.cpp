#include "scene.h"

#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "engine_render.h"
#include "sprite_loader.h"
#include "stasis.h"

#include "camera.h"
#include "gameobject.h"
#include "oval_renderer.h"
#include "player.h"
#include "rect_renderer.h"
#include "rigidbody.h"
#include "sprite_renderer.h"
#include "transform.h"

#include "sys_physics.h"
#include "sys_player.h"

#include <chrono>
#include <random>

#include "vec.h"

#include <entt/entt.hpp>

using RandRangeInt = std::uniform_int_distribution<int>;
using RandEngine = std::default_random_engine;

void InstantiatePlayer();
void InstantiateFloor();

constexpr float FLOORSIZE = 500.f;

Scene::Scene() {}
Scene::~Scene() {}

void Scene::Awake() {
  EngineRender::SetTitle(title);

  InstantiatePlayer();
  InstantiateFloor();

  auto pc = new SysPlayer();
  auto ph = new SysPhysics();
}

void Scene::Start() {}

void Scene::Update() {}

void Scene::Fixed() {}

void Scene::Quit() {}

void InstantiatePlayer() {
  auto &reg = Engine::GetRegistry();

  const auto playerEntID = reg.create();

  reg.emplace<Transform>(playerEntID, true, Vec2::Zero(), Vec2::One(), 0.f);
  reg.emplace<GameObject>(playerEntID, true, true);
  reg.emplace<Rigidbody>(playerEntID, true, Vec2::Zero(), 0.1f);
  reg.emplace<Player>(playerEntID, true, 400.f, 0.001f, 0.5f, 0.f);
  reg.emplace<SpriteRenderer>(playerEntID, true, &SpriteLoader::sprPlayer,
                              Vec2(0.f, 0.f), -90.f, Vec2(100.f, 100.f),
                              Vec2(0.5f, 0.5f), 0, BLEND_ALPHA);
  reg.emplace<Camera>(playerEntID, true, true, 1.f);
}

void InstantiateFloor() {
  auto &reg = Engine::GetRegistry();

  auto now = std::chrono::system_clock::now();
  RandEngine rand((unsigned int)now.time_since_epoch().count());
  RandRangeInt randTx(0, 4);

  for (int x = -16; x <= 16; x++)
    for (int y = -16; y <= 16; y++) {

      const auto floorID = reg.create();

      Vec2 size = Vec2(FLOORSIZE, FLOORSIZE);
      Vec2 pos = Vec2(FLOORSIZE * x, FLOORSIZE * y);

      Sprite *tx;
      int random = randTx(rand);

      if (random == 0)
        tx = &SpriteLoader::sprFloor01;
      else if (random == 1)
        tx = &SpriteLoader::sprFloor02;
      else if (random == 2)
        tx = &SpriteLoader::sprFloor03;
      else if (random == 3)
        tx = &SpriteLoader::sprFloor04;

      reg.emplace<Transform>(floorID, true, pos, Vec2::One(), 0.f);
      reg.emplace<SpriteRenderer>(floorID, true, tx, Vec2::Zero(), 0.f, size,
                                  Vec2(0.5f, 0.5f), 0, BLEND_SOLID);
    }
}

#include "scene.h"

#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "engine_render.h"
#include "stasis.h"

#include "oval_renderer.h"
#include "player_controller.h"
#include "rect_renderer.h"
#include "sprite_renderer.h"
#include "transform.h"

#include "vec.h"

#include <entt/entt.hpp>

Scene::Scene() { EngineGame::Subscribe(this); }
Scene::~Scene() { EngineGame::UnSubscribe(this); }

void Scene::Awake() {
  EngineRender::SetTitle(title);

  auto &reg = Engine::GetRegistry();

  // Player Instantiation
  const auto playerEntID = reg.create();
  player = Entity(playerEntID, &reg);
  reg.emplace<Transform>(playerEntID, &player, true, Vec2(100.f, 100.f),
                         Vec2(1.f, 1.f), 0.f);
  reg.emplace<RectRenderer>(playerEntID, &player, true, Vec2(0.f, 0.f),
                            Vec2(100.f, 50.f), Color(1.f, 0.f, 0.f, 1.f));
  reg.emplace<Camera>(playerEntID, &player, true, true, 1.f);
  // reg.emplace<Behaviour>(playerEntID, &player, true);
}

void Scene::Start() {}

void Scene::Update() {}

void Scene::Fixed() {}

void Scene::Quit() {}

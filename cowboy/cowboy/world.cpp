#include "world.h"

#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "engine_render.h"
#include "stasis.h"

#include "oval_renderer.h"
#include "rect_renderer.h"
#include "sprite_renderer.h"
#include "transform.h"

#include "vec.h"

#include <entt/entt.hpp>

World::World() { EngineGame::Subscribe(this); }
World::~World() { EngineGame::UnSubscribe(this); }

void World::Awake() {
  EngineRender::SetTitle(title);

  auto &reg = Engine::GetRegistry();
  const auto entity = reg.create();

  Vec2 position = {0.f, 0.f};
  Vec2 scale = {1.f, 1.f};
  float rotation = 0.f;
  reg.emplace<Transform>(entity, position, scale, rotation);

  Vec2 offsetPosition = {0.f, 0.f};
  Vec2 offsetScale = {100.f, 100.f};
  Color color = {1.f, 0.f, 0.f, 1.f};
  reg.emplace<RectRenderer>(entity, offsetPosition, offsetScale, color);

  rect1 = entity;
}

void World::Start() {}

void World::Update() {
  int w, h;
  EngineRender::GetWindowSize(w, h);
  auto screenCenter = Vec2((float)w / 2.f, (float)h / 2.f);
  auto mousePos = EngineInput::GetMousePos();
  auto &reg = Engine::GetRegistry();

  // Rect1 in the middle of the screen
  reg.get<Transform>(rect1).position = screenCenter;

  // Rect2 following the mouse
  // rect2.SetPos(mousePos);

  //// Oval1 rotating counterclockwise around rect2
  // auto ang1 = 32.f * (float)STP * 0.001f;
  // rot1 = Vec2::RotateAround(ang1, rot1, Vec2::Zero());
  // oval1.SetPos(rot1 * dis + rect2.GetPos());

  //// Oval2 rotating clockwise around rect2 (for fun)
  // auto ang2 = -32.f * (float)STP * 0.001f;
  // auto rot2 =
  //     Vec2::RotateAround(ang2, oval2.GetPos() - rect2.GetPos(), Vec2::Zero())
  //         .Normalized();
  // oval2.SetPos(rot2 * dis + rect2.GetPos());

  //// Title
  // auto scr2mouse = (mousePos - screenCenter).Magnitude();
  // auto rect3ang = rot1.AngleDeg();
  // snprintf(title, strlen(title),
  //          "Mouse to center: %.0fpx   Oval at angle: %.0fdeg", scr2mouse,
  //          rect3ang);
}

void World::Fixed() {}

void World::Quit() {}

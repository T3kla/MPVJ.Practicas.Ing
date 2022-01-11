#include "world.h"
#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "engine_render.h"
#include "stasis.h"
#include "vec.h"

World::World() { EngineGame::Subscribe(this); }
World::~World() { EngineGame::UnSubscribe(this); }

void World::Awake() {}

void World::Start() {
  EngineRender::SetBgColor({0.1f, 0.1f, 0.1f, 1.f});
  EngineRender::SetTitleUpdate(true);
  EngineRender::SetTitle(title);
}

void World::Update() {}

void World::Fixed() {
  int w, h;
  EngineRender::GetWindowSize(w, h);
  auto screenCenter = Vec2((float)w / 2.f, (float)h / 2.f);
  auto mousePos = EngineInput::GetMousePos();

  // Rect1 in the middle of the screen
  rect1.SetPos(screenCenter);

  // Rect2 following the mouse
  rect2.SetPos(mousePos);

  // Oval1 rotating counterclockwise around rect2
  auto ang1 = 32.f * (float)STP * 0.001f;
  rot1 = Vec2::RotateAround(ang1, rot1, Vec2::Zero());
  oval1.SetPos(rot1 * dis + rect2.GetPos());

  // Oval2 rotating clockwise around rect2 (for fun)
  auto ang2 = -32.f * (float)STP * 0.001f;
  auto rot2 =
      Vec2::RotateAround(ang2, oval2.GetPos() - rect2.GetPos(), Vec2::Zero())
          .Normalized();
  oval2.SetPos(rot2 * dis + rect2.GetPos());

  // Title
  auto scr2mouse = (mousePos - screenCenter).Magnitude();
  auto rect3ang = rot1.AngleDeg();
  snprintf(title, strlen(title),
           "Mouse to center: %.0fpx   Oval at angle: %.0fdeg", scr2mouse,
           rect3ang);
}

void World::Quit() {}

#pragma once

#include "engine_render.h"
#include "gameobject.h"
#include "oval.h"
#include "rect.h"

class World : public GameObject {
private:
  char title[TITLE_LEN] = "Cowboy";

  Rect rect1{{0.f, 0.f}, {75.f, 75.f}, {1.f, 0.f, 0.f, 1.f}};
  Rect rect2{{0.f, 0.f}, {75.f, 75.f}, {0.f, 1.f, 0.f, 1.f}};
  Oval oval1{{0.f, 0.f}, {50.f, 50.f}, {0.f, 0.f, 1.f, 1.f}};
  Oval oval2{{0.f, 0.f}, {25.f, 25.f}, {0.f, 0.5f, 1.f, 1.f}};

  Vec2 rot1 = {1.f, 0.f};
  float dis = 100.f;

public:
  World();
  ~World();

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

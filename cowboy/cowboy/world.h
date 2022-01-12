#pragma once

#include "behaviour.h"
#include <entt/entt.hpp>

class World : public Behaviour {
private:
  char title[256] = "Cowboy";

  entt::entity rect1;
  // entt::entity rect2;
  // entt::entity oval1;
  // entt::entity oval2;

  // Vec2 rot1 = {1.f, 0.f};
  // float dis = 100.f;

public:
  World();
  ~World();

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

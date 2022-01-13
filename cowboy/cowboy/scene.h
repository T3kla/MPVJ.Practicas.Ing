#pragma once

#include "behaviour.h"
#include "entity.h"
#include <entt/entt.hpp>

class Scene : public Behaviour {
private:
  char title[256] = "Cowboy";

  Entity player;
  Entity enemies[64];
  Entity floor[64];

public:
  Scene();
  ~Scene();

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

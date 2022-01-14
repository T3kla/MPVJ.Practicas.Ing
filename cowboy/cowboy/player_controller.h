#pragma once

#include "behaviour.h"

struct PlayerController : public Behaviour {
  float speed = 200.f;

  PlayerController();
  virtual ~PlayerController() override;

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

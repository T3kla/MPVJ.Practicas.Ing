#pragma once

#include "behaviour.h"

struct PlayerController : public Behaviour {
  PlayerController();
  ~PlayerController();
  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

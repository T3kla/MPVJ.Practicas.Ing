#pragma once

#include "behaviour.h"

struct SysPlayer : public Behaviour {
  float speed = 200.f;

  SysPlayer();
  virtual ~SysPlayer() override;

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

#pragma once

#include "behaviour.h"

struct SysEnemy : public Behaviour {
  SysEnemy();
  virtual ~SysEnemy() override;

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};
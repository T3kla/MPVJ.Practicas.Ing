#pragma once

#include "behaviour.h"

struct SysBullet : public Behaviour {
  SysBullet();
  virtual ~SysBullet() override;

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

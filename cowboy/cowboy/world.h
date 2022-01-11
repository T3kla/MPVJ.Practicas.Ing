#pragma once

#include "gameobject.h"
#include "oval.h"
#include "rect.h"

class World : public GameObject {
private:
  char title[256] = "Cowboy";

public:
  World();
  ~World();

  virtual void Awake() override;
  virtual void Start() override;
  virtual void Update() override;
  virtual void Fixed() override;
  virtual void Quit() override;
};

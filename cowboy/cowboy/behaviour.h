#pragma once

class Entity;

struct Behaviour {
  Entity *entity = nullptr;
  bool enable = true;

  Behaviour();
  virtual ~Behaviour();

  virtual void Awake() {};
  virtual void Start() {};
  virtual void Update() {};
  virtual void Fixed() {};
  virtual void Quit() {};
};

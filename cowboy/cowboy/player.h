#pragma once

class Entity;

struct Player {
  Entity *entity = nullptr;
  bool enable = true;

  // Movement
  float maxSpeed = 200.f;
  float acceleration = 200.f;

  // Shooting
  float shootRate = 0.5f;
  float shootCD = 0.f;
};

#pragma once

struct Player {
  bool enable = true;

  // Movement
  float maxSpeed = 0.f;
  float acceleration = 0.f;

  // Shooting
  float shootRate = 0.f;
  float shootCD = 0.f;
};

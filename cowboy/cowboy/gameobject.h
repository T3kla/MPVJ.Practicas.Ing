#pragma once

struct GameObject {
  bool isActive = false;
  GameObject(bool isActive = false) : isActive(isActive) {}
};

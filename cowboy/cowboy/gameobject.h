#pragma once

class Entity;

struct GameObject {
  Entity *entity = nullptr;
  bool enable = true;

  bool isActive = false;
};

#pragma once

#include "color.h"

class Drawable {
public:
  Color color;
  virtual void Draw() const = 0;
};

#pragma once

class Color {
public:
  float r = 1.f;
  float g = 1.f;
  float b = 1.f;
  float a = 1.f;

  Color(float r = 1.f, float g = 1.f, float b = 1.f, float a = 1.f)
      : r(r), g(g), b(b), a(a) {}
};

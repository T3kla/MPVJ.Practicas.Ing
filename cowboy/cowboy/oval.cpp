#include "oval.h"
#include "engine_render.h"
#include "litegfx.h"

Oval::Oval(const Vec2 &pos, const Vec2 &size, const Color &color)
    : pos(pos), size(size), color(color) {
  EngineRender::Subscribe(this);
}

Oval::~Oval() { EngineRender::UnSubscribe(this); }

Vec2 Oval::GetPos() { return pos; }
void Oval::SetPos(const Vec2 &pos) { this->pos = pos; }

Vec2 Oval::GetSize() { return size; }
void Oval::SetSize(const Vec2 &size) { this->size = size; }

Color Oval::GetColor() { return color; }
void Oval::SetColor(const Color &color) { this->color = color; }

void Oval::Draw() const {
  lgfx_setcolor(color.r, color.g, color.b, color.a);
  lgfx_drawoval(pos.x - size.x / 2.f, pos.y - size.y / 2.f, size.x, size.y);
}

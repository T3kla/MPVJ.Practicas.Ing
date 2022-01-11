#include "rect.h"
#include "engine_render.h"
#include "litegfx.h"

Rect::Rect(const Vec2 &pos, const Vec2 &size, const Color &color)
    : pos(pos), size(size), color(color) {
  EngineRender::Get().Subscribe(this);
}

Rect::~Rect() { EngineRender::Get().UnSubscribe(this); }

Vec2 Rect::GetPos() { return pos; }
void Rect::SetPos(const Vec2 &pos) { this->pos = pos; }

Vec2 Rect::GetSize() { return size; }
void Rect::SetSize(const Vec2 &size) { this->size = size; }

Color Rect::GetColor() { return color; }
void Rect::SetColor(const Color &color) { this->color = color; }

void Rect::Draw() const {
  lgfx_setcolor(color.r, color.g, color.b, color.a);
  lgfx_drawrect(pos.x - size.x / 2.f, pos.y - size.y / 2.f, size.x, size.y);
}

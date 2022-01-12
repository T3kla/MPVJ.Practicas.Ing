#include "engine_render.h"
#include "engine.h"
#include "litegfx.h"
#include "oval_renderer.h"
#include "rect_renderer.h"
#include "sprite_renderer.h"
#include "stasis.h"
#include "transform.h"
#include "vec.h"

EngineRender EngineRender::instance;

EngineRender::EngineRender() {}

EngineRender &EngineRender::Get() { return instance; }

void OnWindowResize(GLFWwindow *window, int w, int h) {
  EngineRender::SetWindowSize(w, h);
  lgfx_setup2d(w, h);
}

void EngineRender::Awake() {
  if (glfwInit() == 0)
    std::cout << "Panic!" << std::endl;

  // Create window
  instance.window = glfwCreateWindow(
      instance.windowWidth, instance.windowHeight, "", nullptr, nullptr);
  glfwMakeContextCurrent(instance.window);

  glfwSetInputMode(instance.window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  glfwSetWindowSizeCallback(instance.window, OnWindowResize);
  lgfx_setup2d(instance.windowWidth, instance.windowHeight);
}

void EngineRender::Start() {}

void EngineRender::Update() {
  // Update title
  if (instance.titleUpdate)
    if (instance.title != nullptr)
      glfwSetWindowTitle(instance.window, instance.title);
}

void EngineRender::Fixed() {
  // Redraw
  lgfx_clearcolorbuffer(instance.bgColor.r, instance.bgColor.g,
                        instance.bgColor.b);

  // Render Rects
  auto rects = Engine::GetRegistry().view<Transform, RectRenderer>();
  for (auto [entity, tf, rr] : rects.each()) {
    lgfx_setcolor(rr.color.r, rr.color.g, rr.color.b, rr.color.a);
    Vec2 fPos = tf.position + rr.offsetPosition;
    Vec2 fScl = tf.scale + rr.offsetScale;
    lgfx_drawrect(fPos.x - fScl.x / 2.f, fPos.y - fScl.y / 2.f, fScl.x, fScl.y);
  }

  // Render Ovals
  auto ovals = Engine::GetRegistry().view<Transform, OvalRenderer>();
  for (auto [entity, tf, rr] : ovals.each()) {
    lgfx_setcolor(rr.color.r, rr.color.g, rr.color.b, rr.color.a);
    Vec2 fPos = tf.position + rr.offsetPosition;
    Vec2 fScl = tf.scale + rr.offsetScale;
    lgfx_drawoval(fPos.x - fScl.x / 2.f, fPos.y - fScl.y / 2.f, fScl.x, fScl.y);
  }

  // Render Sprites
  auto sprites = Engine::GetRegistry().view<Transform, SpriteRenderer>();
  for (auto [entity, tf, sr] : sprites.each()) {
    if (!sr.texture)
      continue;
    lgfx_setblend(sr.blend);
    Vec2 fPos = tf.position + sr.offsetPosition;
    Vec2 fRot = tf.rotation + sr.offsetRotation;
    ltex_drawrotsized((ltex_t *)sr.texture, fPos.x, fPos.y, sr.offsetRotation,
                      sr.pivot.x, sr.pivot.y, sr.size.x, sr.size.y, sr.uv0.x,
                      sr.uv0.y, sr.uv1.x, sr.uv1.y);
  }

  // Swap Buffers
  glfwSwapBuffers(instance.window);
}

void EngineRender::Quit() {}

GLFWwindow *EngineRender::GetWindow() { return instance.window; }

void EngineRender::SetWindow(GLFWwindow *window) { instance.window = window; }

void EngineRender::GetWindowSize(int &width, int &height) {
  width = instance.windowWidth;
  height = instance.windowHeight;
}

void EngineRender::SetWindowSize(const int &width, const int &height) {
  instance.windowWidth = width;
  instance.windowHeight = height;
}

const Color &EngineRender::GetBgColor() { return instance.bgColor; }
void EngineRender::SetBgColor(const Color &color) { instance.bgColor = color; }

const char *EngineRender::GetTitle() { return instance.title; }
void EngineRender::SetTitle(char *text) {
  instance.title = text;
  if (instance.title != nullptr)
    glfwSetWindowTitle(instance.window, instance.title);
}

const bool EngineRender::GetTitleUpdate() { return instance.titleUpdate; }
void EngineRender::SetTitleUpdate(bool value) { instance.titleUpdate = value; }

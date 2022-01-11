#include "engine_render.h"
#include "engine.h"
#include "stasis.h"
#include "vec.h"

EngineRender EngineRender::instance;

EngineRender::EngineRender() {}

EngineRender &EngineRender::Get() { return instance; }

void EngineRender::Awake() {}

void EngineRender::Start() {}

void EngineRender::Update() {}

void EngineRender::Fixed() {}

void EngineRender::Quit() {}

void EngineRender::Subscribe(Drawable *drawable) {
  // Duplication guard
  auto it =
      std::find(instance.drawables.begin(), instance.drawables.end(), drawable);
  if (it != instance.drawables.end())
    return;

  instance.drawables.emplace_back(drawable);
}

void EngineRender::UnSubscribe(const Drawable *drawable) {
  // Not found guard
  auto it =
      std::find(instance.drawables.begin(), instance.drawables.end(), drawable);
  if (it == instance.drawables.end())
    return;

  instance.drawables.erase(it);
}

const std::vector<Drawable *> *EngineRender::GetDrawables() {
  return &instance.drawables;
}

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

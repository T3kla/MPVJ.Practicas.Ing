// #define LITE_GFX_IMPLEMENTATION

#include "engine_render.h"
#include "engine.h"
#include "litegfx.h"
#include "stasis.h"
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

  instance.window = glfwCreateWindow(
      instance.windowWidth, instance.windowHeight, "", nullptr, nullptr);

  glfwMakeContextCurrent(instance.window);

  glfwSetInputMode(instance.window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  glfwSetWindowSizeCallback(instance.window, OnWindowResize);
  lgfx_setup2d(instance.windowWidth, instance.windowHeight);
}

void EngineRender::Start() {}

void EngineRender::Update() {
  // Render loop
  lgfx_clearcolorbuffer(instance.bgColor.r, instance.bgColor.g,
                        instance.bgColor.b);

  for (auto &&drawable : instance.drawables)
    drawable->Draw();

  glfwSwapBuffers(instance.window);

  // Update title
  if (instance.titleUpdate)
    if (instance.title != nullptr)
      glfwSetWindowTitle(instance.window, instance.title);
}

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

const bool EngineRender::GetTitleUpdate() { return instance.titleUpdate; }
void EngineRender::SetTitleUpdate(bool value) { instance.titleUpdate = value; }

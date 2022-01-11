#include "engine_input.h"
#include "engine_render.h"
#include "glfw3.h"
#include "stasis.h"
#include "vec.h"
#include <iostream>

EngineInput EngineInput::instance;

EngineInput::EngineInput() {}

EngineInput &EngineInput::Get() { return instance; };

void EngineInput::Awake() {}

void EngineInput::Start() {}

void EngineInput::Update() {
  glfwPollEvents();

  // Update mouse pos
  auto *window = EngineRender::GetWindow();
  double mouse_pos_x, mouse_pos_y;
  glfwGetCursorPos(window, &mouse_pos_x, &mouse_pos_y);
  instance.mousePos = {(float)mouse_pos_x, (float)mouse_pos_y};
  instance.mouseDelta = instance.mousePos - instance.mouseOldPos;
  instance.mouseOldPos = instance.mousePos;

  // Exit
  if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
    glfwSetWindowShouldClose(window, 1);
}

void EngineInput::Fixed() {}

void EngineInput::Quit() {}

Vec2 EngineInput::GetMousePos() { return instance.mousePos; }
Vec2 EngineInput::GetMouseDelta() { return instance.mouseDelta; }
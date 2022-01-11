#pragma once

#include "drawable.h"
#include "glfw3.h"
#include <vector>

constexpr size_t TITLE_LEN = 256;

class EngineRender {
  friend class Engine;

private:                                       // SINGLETON
  EngineRender();                              //
  static EngineRender instance;                //
public:                                        //
  EngineRender(const EngineRender &) = delete; //
  static EngineRender &Get();                  //

  // Game Loop stuff
private:
  static void Awake();
  static void Start();
  static void Update();
  static void Fixed();
  static void Quit();

  // Drawables stuff
private:
  std::vector<Drawable *> drawables = std::vector<Drawable *>();

public:
  static void Subscribe(Drawable *drawable);
  static void UnSubscribe(const Drawable *drawable);
  static const std::vector<Drawable *> *GetDrawables();

  // GLFW stuff
private:
  char *title = nullptr;
  GLFWwindow *window = nullptr;
  int windowWidth = 0, windowHeight = 0;
  Color bgColor = {0.f, 0.f, 0.f, 0.f};

public:
  static GLFWwindow *GetWindow();
  static void SetWindow(GLFWwindow *window);

  static void GetWindowSize(int &width, int &height);
  static void SetWindowSize(const int &width, const int &height);

  static const Color &GetBgColor();
  static void SetBgColor(const Color &color);

  static const char *GetTitle();
  static void SetTitle(char *text);
};

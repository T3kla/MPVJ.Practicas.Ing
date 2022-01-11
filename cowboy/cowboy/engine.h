#pragma once

#include "glfw3.h"

constexpr double FPS = 30.;
constexpr double STP = 1000. / FPS;

class Engine {
private:                           // SINGLETON
  Engine();                        //
  static Engine instance;          //
public:                            //
  Engine(const Engine &) = delete; //
  static Engine &Get();            //

public:
  static void Run();

  static float GetUpdateFPS();
  static float GetFixedFPS();
};

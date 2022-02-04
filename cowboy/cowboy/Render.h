#pragma once

class Render
{
  private:
    Render(){};
    static Render Instance;

  public:
    Render(const Render &) = delete;

    static void Run();
};

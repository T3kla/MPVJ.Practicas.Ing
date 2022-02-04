#pragma once

class Input
{
  private:
    Input(){};
    static Input Instance;

    static char CurrentInput;

  public:
    Input(const Input &) = delete;

    static void Run();
    static char GetInput();
};

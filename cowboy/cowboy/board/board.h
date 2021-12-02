#pragma once

#include "../typedef.h"

class board
{
  private:                         // SINGLETON
    board();                       //
    static board instance;         //
  public:                          //
    board(const board &) = delete; //
    static board &get();           //

  private:
    // char buffer[];

  public:
    static constexpr u16 WIDTH = 800;
    static constexpr u16 HEIGTH = 800;
};

#pragma once

#include "../typedef.h"
#include <tuple>

class drawable
{
  private:
    i16 pos = 0;
    i16 width = 1;

  public:
    virtual void draw() = 0;

    virtual i16 get_pos()
    {
        return pos;
    };

    virtual i16 get_width()
    {
        return width;
    };
};

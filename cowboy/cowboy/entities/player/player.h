#pragma once

#include "../../interfaces/drawable.h"
#include "../../typedef.h"

class player : drawable
{
  private:
  public:
    player();
    ~player();

    virtual void draw() override;
    virtual i16 get_pos() override;
    virtual i16 get_width() override;
};

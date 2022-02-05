#pragma once

#include "EEntityType.h"

class Entity
{
  public:
    Entity(EEntityType Type = EEntityType::None, int Position = 0);
    ~Entity();

    bool GetIsActive();
    void SetIsActive(bool Value);

    int GetPosition();
    void SetPosition(int Value);

    EEntityType GetEntityType();
    void SetEntityType(EEntityType Value);

  private:
    bool Active = false;
    int Position = 0;
    EEntityType Type = EEntityType::None;
};

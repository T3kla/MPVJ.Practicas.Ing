#pragma once

#include "EEntityType.h"

class Entity
{
  public:
    Entity(E_EntityType Type = E_EntityType::None, int Position = 0);
    ~Entity();

    bool GetIsActive();
    void SetIsActive(bool Value);

    int GetPosition();
    void SetPosition(int Value);

    E_EntityType GetEntityType();
    void SetEntityType(E_EntityType Value);

  private:
    bool Active = false;
    int Position = 0;
    E_EntityType Type = E_EntityType::None;
};

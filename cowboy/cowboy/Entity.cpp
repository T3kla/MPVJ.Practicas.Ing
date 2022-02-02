#include "Entity.h"

Entity::Entity(E_EntityType Type, int Position)
{
    this->Active = false;
    this->Type = Type;
    this->Position = Position;
}

Entity::~Entity()
{
}

bool Entity::GetIsActive()
{
    return Active;
}

void Entity::SetIsActive(bool Value)
{
    Active = Value;
}

int Entity::GetPosition()
{
    return Position;
}

void Entity::SetPosition(int Value)
{
    Position = Value;
}

E_EntityType Entity::GetEntityType()
{
    return Type;
}

void Entity::SetEntityType(E_EntityType Value)
{
    this->Type = Value;
}

#include "Entity.h"

Entity::Entity(EEntityType Type, int Position)
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

bool Entity::GetReverse()
{
    return Reverse;
}

void Entity::SetReverse(bool Value)
{
    Reverse = Value;
}

EEntityType Entity::GetEntityType()
{
    return Type;
}

void Entity::SetEntityType(EEntityType Value)
{
    this->Type = Value;
}

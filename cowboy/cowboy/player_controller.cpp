#include "player_controller.h"

#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "entity.h"
#include "stasis.h"
#include "transform.h"
#include "vec.h"

PlayerController::PlayerController() {}
PlayerController::~PlayerController() {}

void PlayerController::Awake() {}

void PlayerController::Start() {}

void PlayerController::Update() {
  if (!entity)
    return;

  // Input
  if (EngineInput::GetKey(EngineInput::KeyCode::W)) {
    Engine::GetRegistry().get<Transform>(entity->GetID()).position.y -=
        speed * (float)Stasis::GetDeltaScaled() * 0.001f;
  }

  if (EngineInput::GetKey(EngineInput::KeyCode::S)) {
    Engine::GetRegistry().get<Transform>(entity->GetID()).position.y +=
        speed * (float)Stasis::GetDeltaScaled() * 0.001f;
  }

  if (EngineInput::GetKey(EngineInput::KeyCode::A)) {
    Engine::GetRegistry().get<Transform>(entity->GetID()).position.x -=
        speed * (float)Stasis::GetDeltaScaled() * 0.001f;
  }

  if (EngineInput::GetKey(EngineInput::KeyCode::D)) {
    Engine::GetRegistry().get<Transform>(entity->GetID()).position.x +=
        speed * (float)Stasis::GetDeltaScaled() * 0.001f;
  }

  // Look to mouse TODO: test with sprite
  auto &tf = entity->GetReg()->get<Transform>(entity->GetID());
  auto ang = (EngineInput::GetMousePosInWorld() - tf.position).AngleDeg();
  tf.rotation = ang;
}

void PlayerController::Fixed() {}

void PlayerController::Quit() {}

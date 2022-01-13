#include "player_controller.h"

#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "entity.h"
#include "stasis.h"
#include "transform.h"

PlayerController::PlayerController() { EngineGame::Subscribe(this); }
PlayerController::~PlayerController() { EngineGame::UnSubscribe(this); }

void PlayerController::Awake() {}

void PlayerController::Start() {}

void PlayerController::Update() {
  if (EngineInput::GetKey(EngineInput::KeyCode::W)) {
    Engine::GetRegistry().get<Transform>(entity->GetID()).position +=
        1.f * (float)Stasis::GetDeltaScaled();
  }
  if (EngineInput::GetKey(EngineInput::KeyCode::S)) {
    Engine::GetRegistry().get<Transform>(entity->GetID()).position -=
        1.f * (float)Stasis::GetDeltaScaled();
  }
}

void PlayerController::Fixed() {}

void PlayerController::Quit() {}

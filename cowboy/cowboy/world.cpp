#include "world.h"
#include "engine.h"
#include "engine_game.h"
#include "engine_input.h"
#include "engine_render.h"
#include "stasis.h"
#include "vec.h"

World::World() { EngineGame::Subscribe(this); }
World::~World() { EngineGame::UnSubscribe(this); }

void World::Awake() {}

void World::Start() {}

void World::Update() {}

void World::Fixed() {}

void World::Quit() {}

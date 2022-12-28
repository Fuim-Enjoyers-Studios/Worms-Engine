#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"



ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	//create ground
	PhysBody* ground = App->physics->CreateRectangle((0.0f)/2, (0.0f)/2, (30.0f)/2, (5.0f)/2, BodyType::STATIC);
	ground->ctype = ColliderType::GROUND;

	//Create water
	PhysBody* water = App->physics->CreateWaterRectangle((0.0f + 30.0f)/2, (0.0f)/2, (30.0f)/2, (5.0f)/2);

	//Create entity
	PhysBody* ball = App->physics->CreateCircle((2.0f)/2, (0.0f + 5.0f + 2.0f)/2, (0.5f), BodyType::DYNAMIC);
	// Set static properties of the ball
	ball->mass = 10.0f; // [kg]
	ball->surface = 1.0f; // [m^2]
	ball->cd = 0.4f; // [-]
	ball->cl = 1.2f; // [-]
	ball->b = 10.0f; // [...]
	ball->coef_friction = 0.9f; // [-]
	ball->coef_restitution = 0.8f; // [-]

	// Set initial position and velocity of the ball
	ball->velocity.x = 5.0f;
	ball->velocity.y = 10.0f;
	ball->ctype = ColliderType::ENTITY;

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	

	return UPDATE_CONTINUE;
}

#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"



ModuleSceneIntro::ModuleSceneIntro(bool start_enabled) : Module(start_enabled)
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
	App->audio->PlayMusic("Assets/Audio/backgroundMusic.ogg");
	App->renderer->camera.x = App->renderer->camera.y = 0;
	//background = App->textures->Load("Assets/Textures/intro.png");
	
	//creating 1 player
	player1 = (Player*)App->entityManager->CreateEntity(EntityType::PLAYER, "Assets/Textures/spriteplayer1.png", { METERS_TO_PIXELS(1), METERS_TO_PIXELS(3.5f) });

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
	App->audio->PlayMusic("");

	/*p2List_item<Projectile*>* projectileItem = projectiles.getFirst();

	while (projectileItem != NULL)
	{
		delete projectileItem->data;
		projectileItem->data = NULL;
		projectileItem = projectileItem->next;
	}
	projectiles.clear();*/
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	int speed = 10;
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		App->renderer->camera.y += speed;
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		App->renderer->camera.y -= speed;
	}
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		App->renderer->camera.x -= speed;
	}
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		App->renderer->camera.x += speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
	{
		Projectile* projectile = (Projectile*)App->entityManager->CreateEntity(EntityType::PROJECTILE, "Assets/Textures/shotplayer1.png", player1->position);
		projectiles.add(projectile);
	}



	//App->renderer->Blit(background, 0, 0);


	return UPDATE_CONTINUE;
}

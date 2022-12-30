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

	//create ground & water
	ground1 = App->physics->CreateRectangle(-1.0f, 0.0f, 1.0f, 20.0f, BodyType::STATIC);
	ground1->ctype = ColliderType::GROUND;

	ground2 = App->physics->CreateRectangle(0.0f, 0.0f, 15.0f, 2.5f, BodyType::STATIC);
	ground2->ctype = ColliderType::GROUND;

	water = App->physics->CreateWaterRectangle(ground2->w, 0.0f, 15.0f, 2.5f);

	ground3 = App->physics->CreateRectangle(water->position.x + water->w, 0.0f, 15.0f, 2.5f, BodyType::STATIC);
	ground3->ctype = ColliderType::GROUND;

	ground4 = App->physics->CreateRectangle(ground3->position.x + ground3->w, 0.0f, 1.0f, 20.0f, BodyType::STATIC);
	ground4->ctype = ColliderType::GROUND;

	//Create entity
	//creating 1 player
	player1 = (Player*)App->entityManager->CreateEntity(EntityType::PLAYER, "Assets/Textures/spriteplayer1.png", { METERS_TO_PIXELS(1.5), METERS_TO_PIXELS(3.5f) });

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

	//projectile
	if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
	{
		//if player state is shooting
		if (player1->getState() == 5 ) {
			Projectile* projectile = (Projectile*)App->entityManager->CreateEntity(EntityType::PROJECTILE, "Assets/Textures/shotplayer1.png", player1->position);
			projectiles.add(projectile);
		}

	}
	//App->renderer->Blit(background, 0, 0);


	return UPDATE_CONTINUE;
}

#include "Application.h"
#include "Module.h"
#include "Player.h"
#include "Log.h"
#include "p2Point.h"

Player::Player() : Entity(EntityType::PLAYER)
{
	
}

Player::Player(const char* path, iPoint posi) : Entity(EntityType::PLAYER)
{
	texturePath = path;
	position = posi;
}

Player::~Player() {

}

bool Player::Start() {

	//initilize textures
	texture = App->textures->Load(texturePath);
	return true;
}

bool Player::Update()
{
	////L02: DONE 4: modify the position of the player using arrow keys and render the texture
	//if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	//	position.y -= 1;

	//if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	//	position.y += 1;

	//if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	//	position.x -= 1;

	//if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	//	position.x += 1;

	//app->render->DrawTexture(texture, position.x, position.y);

	return true;
}

bool Player::CleanUp()
{

	return true;
}
#include "Application.h"
#include "Module.h"
#include "Player.h"
#include "Log.h"
#include "p2Point.h"

Player::Player() : Entity(EntityType::PLAYER)
{
	IdleAnimation.PushBack({ 0 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 1 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 2 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 3 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 4 * 32,0 * 32,32,32 });
	IdleAnimation.loop = true;
	IdleAnimation.speed = 0.07f;

	WalkRightAnimation.PushBack({ 0 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 1 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 2 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 3 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 4 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 5 * 32,1 * 32,32,32 });
	WalkRightAnimation.loop = true;
	WalkRightAnimation.speed = 0.07f;

	WalkLeftAnimation.PushBack({ 0 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 1 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 2 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 3 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 4 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 5 * 32,2 * 32,32,32 });
	WalkLeftAnimation.loop = true;
	WalkLeftAnimation.speed = 0.07f;

	JumpRightAnimation.PushBack({ 0 * 32,1 * 32,32,32 });
	JumpRightAnimation.PushBack({ 0 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 1 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 2 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 3 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 4 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 5 * 32,3 * 32,32,32 });
	JumpRightAnimation.loop = true;
	JumpRightAnimation.speed = 0.07f;

	JumpLeftAnimation.PushBack({ 0 * 32,2 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 0 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 1 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 2 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 3 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 4 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 5 * 32,4 * 32,32,32 });
	JumpLeftAnimation.loop = true;
	JumpLeftAnimation.speed = 0.07f;

	DeathAnimation.PushBack({ 0 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 1 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 2 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 3 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 4 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 5 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 5 * 32,0 * 32,32,32 });
	DeathAnimation.loop = false;
	DeathAnimation.speed = 0.1f;
}

Player::Player(const char* path, iPoint posi) : Entity(EntityType::PLAYER)
{
	IdleAnimation.PushBack({ 0 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 1 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 2 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 3 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 4 * 32,0 * 32,32,32 });
	IdleAnimation.loop = true;
	IdleAnimation.speed = 0.07f;

	WalkRightAnimation.PushBack({ 0 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 1 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 2 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 3 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 4 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 5 * 32,1 * 32,32,32 });
	WalkRightAnimation.loop = true;
	WalkRightAnimation.speed = 0.07f;

	WalkLeftAnimation.PushBack({ 0 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 1 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 2 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 3 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 4 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 5 * 32,2 * 32,32,32 });
	WalkLeftAnimation.loop = true;
	WalkLeftAnimation.speed = 0.07f;

	JumpRightAnimation.PushBack({ 0 * 32,1 * 32,32,32 });
	JumpRightAnimation.PushBack({ 0 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 1 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 2 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 3 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 4 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 5 * 32,3 * 32,32,32 });
	JumpRightAnimation.loop = true;
	JumpRightAnimation.speed = 0.07f;

	JumpLeftAnimation.PushBack({ 0 * 32,2 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 0 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 1 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 2 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 3 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 4 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 5 * 32,4 * 32,32,32 });
	JumpLeftAnimation.loop = true;
	JumpLeftAnimation.speed = 0.07f;

	DeathAnimation.PushBack({ 0 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 1 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 2 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 3 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 4 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 5 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 5 * 32,0 * 32,32,32 });
	DeathAnimation.loop = false;
	DeathAnimation.speed = 0.1f;


	texturePath = path;
	position = posi;
}

Player::~Player() {

}

bool Player::Start() {

	//initilize textures
	texture = App->textures->Load(texturePath);
	deathSound = App->audio->LoadFx("Assets/Audio/deathSound.wav");
	return true;
}

bool Player::Update()
{
	int speed = 5;
	currentAnimation = &IdleAnimation;
	////L02: DONE 4: modify the position of the player using arrow keys and render the texture
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		position.y -= speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) {
		position.y += speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {
		currentAnimation = &WalkLeftAnimation;
		position.x -= speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
		currentAnimation = &WalkRightAnimation;
		position.x += speed;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		currentAnimation = &DeathAnimation;
		App->audio->PlayFx(deathSound);
	}

	//blit slime
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->renderer->Blit(texture, position.x, position.y, &rect);
	currentAnimation->Update();

	return true;
}

bool Player::CleanUp()
{
	App->textures->Unload(texture);
	return true;
}
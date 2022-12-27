#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	IdleAnimation.PushBack({ 0 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 1 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 2 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 3 * 32,0 * 32,32,32 });
	IdleAnimation.PushBack({ 4 * 32,0 * 32,32,32 });
	IdleAnimation.loop = true;
	IdleAnimation.speed = 1.0f;

	WalkRightAnimation.PushBack({ 0 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 1 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 2 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 3 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 4 * 32,1 * 32,32,32 });
	WalkRightAnimation.PushBack({ 5 * 32,1 * 32,32,32 });
	WalkRightAnimation.loop = true;
	WalkRightAnimation.speed = 1.0f;

	WalkLeftAnimation.PushBack({ 0 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 1 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 2 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 3 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 4 * 32,2 * 32,32,32 });
	WalkLeftAnimation.PushBack({ 5 * 32,2 * 32,32,32 });
	WalkLeftAnimation.loop = true;
	WalkLeftAnimation.speed = 1.0f;

	JumpRightAnimation.PushBack({ 0 * 32,1 * 32,32,32 });
	JumpRightAnimation.PushBack({ 0 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 1 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 2 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 3 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 4 * 32,3 * 32,32,32 });
	JumpRightAnimation.PushBack({ 5 * 32,3 * 32,32,32 });
	JumpRightAnimation.loop = true;
	JumpRightAnimation.speed = 1.0f;

	JumpLeftAnimation.PushBack({ 0 * 32,2 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 0 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 1 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 2 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 3 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 4 * 32,4 * 32,32,32 });
	JumpLeftAnimation.PushBack({ 5 * 32,4 * 32,32,32 });
	JumpLeftAnimation.loop = true;
	JumpLeftAnimation.speed = 1.0f;

	DeathAnimation.PushBack({ 0 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 1 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 2 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 3 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 4 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 5 * 32,5 * 32,32,32 });
	DeathAnimation.PushBack({ 5 * 32,0 * 32,32,32 });
	DeathAnimation.loop = false;
	DeathAnimation.speed = 1.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	return UPDATE_CONTINUE;
}




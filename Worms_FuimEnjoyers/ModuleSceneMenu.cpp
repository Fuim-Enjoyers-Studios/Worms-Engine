#include "Globals.h"
#include "Application.h"
#include "ModuleSceneMenu.h"



ModuleSceneMenu::ModuleSceneMenu(bool start_enabled) : Module(start_enabled)
{

}


ModuleSceneMenu::~ModuleSceneMenu()
{

}

// Load assets
bool ModuleSceneMenu::Start()
{
	App->audio->PlayMusic("Assets/Audio/MenuTheme.wav");
	entrysound = App->audio->LoadFx("Assets/Audio/EntryEnter.wav");
	bgtexture = App->textures->Load("Assets/Textures/quecojones.png");

	return true;
}

bool ModuleSceneMenu::CleanUp()
{
	LOG("Deleting background assets");
	App->textures->Unload(bgtexture);
	App->audio->PlayMusic("");
	bgtexture = nullptr;
	return true;
}

update_status ModuleSceneMenu::Update()
{

	if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN) {
		App->audio->PlayFx(entrysound);
		this->Disable();
		App->scene_intro->Enable();
	}


	return UPDATE_CONTINUE;

}

update_status ModuleSceneMenu::PostUpdate()
{
	App->renderer->Blit(bgtexture,0,0);

	return UPDATE_CONTINUE;
}
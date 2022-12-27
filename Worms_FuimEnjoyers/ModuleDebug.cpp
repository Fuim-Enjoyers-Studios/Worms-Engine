#include "Globals.h"
#include "Application.h"
#include "ModuleDebug.h"



ModuleDebug::ModuleDebug(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleDebug::~ModuleDebug()
{}

// Load assets
bool ModuleDebug::Start()
{
	LOG("Loading DEBUG start");
	bool ret = true;


	return ret;
}

// Load assets
bool ModuleDebug::CleanUp()
{
	LOG("Unloading DEBUG");

	return true;
}

// Update: draw background
update_status ModuleDebug::Update()
{
	

	return UPDATE_CONTINUE;
}

update_status ModuleDebug::PostUpdate()
{


	return UPDATE_CONTINUE;
}

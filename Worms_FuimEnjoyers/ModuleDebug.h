#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleDebug : public Module
{
public:
	ModuleDebug(bool start_enabled = true);
	~ModuleDebug();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

public:


};

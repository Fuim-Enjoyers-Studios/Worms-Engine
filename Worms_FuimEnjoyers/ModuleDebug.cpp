#include "Globals.h"
#include "Application.h"
#include "ModuleDebug.h"



ModuleDebug::ModuleDebug(bool start_enabled) : Module(start_enabled)
{
}

ModuleDebug::~ModuleDebug()
{}

// Load assets
bool ModuleDebug::Start()
{
	LOG("Loading DEBUG start");
	bool ret = true;

	gravityEnabled = true;
	aerodynamicDragEnabled = true;
	hydrodynamicDragEnabled = true;
	hydrodynamicBuoyancyEnabled = true;
	pause = false;
	debug = true;
	debugSpeed = false;
	deltaTime = DeltaTimeScheme::FIXED;


	App->fonts->Load("Assets/Fonts/sprite_font_red.png", "abcdefghijklmnopqrstuvwxyz 0123456789.,;:$#'! /?%&()@ ", 6);

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
{	// Colors
	int color_r, color_g, color_b;
	//DRAW COLLIDERS OF ALL ELEMENTS OF THE WORLD

	p2List_item<PhysBody*>* element = App->physics->world.Elements.getFirst();
	while (element != NULL)
	{
		if (element->data->ctype == ColliderType::GROUND) {
			// Draw ground
			color_r = 0; color_g = 255; color_b = 0;
			App->renderer->DrawQuad(element->data->pixelRect(), color_r, color_g, color_b);
		}
		else if (element->data->ctype == ColliderType::WATER) {
			// Draw water
			color_r = 0; color_g = 0; color_b = 255;
			App->renderer->DrawQuad(element->data->pixelRect(), color_r, color_g, color_b);
		}
		else if (element->data->ctype == ColliderType::ENTITY && debug) {
			// Select color
			if (element->data->ArePhysicsEnabled())
			{
				color_r = 255; color_g = 255; color_b = 255;
			}
			else
			{
				color_r = 255; color_g = 0; color_b = 0;
			}

			// Draw element
			if (element->data->GetShape() == ShapeType::CIRCLE)
			{
				// Convert from physical magnitudes to geometrical pixels
				int pos_x = METERS_TO_PIXELS(element->data->position.x);
				int pos_y = SCREEN_HEIGHT - METERS_TO_PIXELS(element->data->position.y);
				int size_r = METERS_TO_PIXELS(element->data->radius);

				App->renderer->DrawCircle(pos_x, pos_y, size_r, color_r, color_g, color_b);
			}
			else if (element->data->GetShape() == ShapeType::RECTANGLE)
			{
				App->renderer->DrawQuad(element->data->pixelRect(), color_r, color_g, color_b, 255U, false);
			}
		}
		else if (element->data->ctype == ColliderType::SHOT && debug) {
			// Select color
			if (element->data->ArePhysicsEnabled())
			{
				color_r = 255; color_g = 255; color_b = 255;
			}
			else
			{
				color_r = 255; color_g = 0; color_b = 0;
			}

			// Draw element
			if (element->data->GetShape() == ShapeType::CIRCLE)
			{
				// Convert from physical magnitudes to geometrical pixels
				int pos_x = METERS_TO_PIXELS(element->data->position.x);
				int pos_y = SCREEN_HEIGHT - METERS_TO_PIXELS(element->data->position.y);
				int size_r = METERS_TO_PIXELS(element->data->radius);

				App->renderer->DrawCircle(pos_x, pos_y, size_r, color_r, color_g, color_b);
			}
			else if (element->data->GetShape() == ShapeType::RECTANGLE)
			{
				App->renderer->DrawQuad(element->data->pixelRect(), color_r, color_g, color_b, 255U, false);
			}
		}
		else if (element->data->ctype == ColliderType::GRENADE && debug) {
			// Select color
			if (element->data->ArePhysicsEnabled())
			{
				color_r = 255; color_g = 255; color_b = 255;
			}
			else
			{
				color_r = 255; color_g = 0; color_b = 0;
			}

			// Draw element
			if (element->data->GetShape() == ShapeType::CIRCLE)
			{
				// Convert from physical magnitudes to geometrical pixels
				int pos_x = METERS_TO_PIXELS(element->data->position.x);
				int pos_y = SCREEN_HEIGHT - METERS_TO_PIXELS(element->data->position.y);
				int size_r = METERS_TO_PIXELS(element->data->radius);

				App->renderer->DrawCircle(pos_x, pos_y, size_r, color_r, color_g, color_b);
			}
			else if (element->data->GetShape() == ShapeType::RECTANGLE)
			{
				App->renderer->DrawQuad(element->data->pixelRect(), color_r, color_g, color_b, 255U, false);
			}
		}

		element = element->next;
	}
	//debug keys for activating and dactivating things
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN) {
		debug = !debug;
	}
	if (!debug) {
		App->fonts->BlitText(20, 3, 0, "f1 to activate debug menu");
		return UPDATE_CONTINUE;
	}
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN) {
		if (App->scene_intro->actualPlayer->data->getBody()->ArePhysicsEnabled() == true) {
			App->scene_intro->actualPlayer->data->getBody()->DisablePhysics();
		}
		else {
			App->scene_intro->actualPlayer->data->getBody()->EnablePhysics();
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN) {
		if (gravityEnabled) { gravityEnabled = false; }
		else if (!gravityEnabled) { gravityEnabled = true; }
	}
	if (App->input->GetKey(SDL_SCANCODE_F4) == KEY_DOWN) {
		if (aerodynamicDragEnabled) { aerodynamicDragEnabled = false; }
		else if (!aerodynamicDragEnabled) { aerodynamicDragEnabled = true; }
	}
	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) {
		if (hydrodynamicDragEnabled) { hydrodynamicDragEnabled = false; }
		else if (!hydrodynamicDragEnabled) { hydrodynamicDragEnabled = true; }
	}
	if (App->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN) {
		if (hydrodynamicBuoyancyEnabled) { hydrodynamicBuoyancyEnabled = false; }
		else if (!hydrodynamicBuoyancyEnabled) { hydrodynamicBuoyancyEnabled = true; }
	}
	if (App->input->GetKey(SDL_SCANCODE_F7) == KEY_DOWN) {
		if (debugSpeed) { debugSpeed = false; }
		else if (!debugSpeed) { debugSpeed = true; }
	}
	if (App->input->GetKey(SDL_SCANCODE_F8) == KEY_DOWN) {
		deltaTime = DeltaTimeScheme::FIXED;
		App->physics->dt = 1 / 60;
	}
	if (App->input->GetKey(SDL_SCANCODE_F9) == KEY_DOWN) {
		deltaTime = DeltaTimeScheme::VARIABLE;
	}
	if (App->input->GetKey(SDL_SCANCODE_F10) == KEY_DOWN) {
		deltaTime = DeltaTimeScheme::SEMIFIXED;
		App->physics->dt = 1 / 60;
	}
	if (App->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN) {
		if (pause) { pause = false; }
		else if (!pause) { pause = true; }
	}

	//debug text 
	App->fonts->BlitText(20, 3, 0, "f1 to deactivate debug menu");
	if (App->scene_intro->actualPlayer->data->getBody()->ArePhysicsEnabled() == true) {
		App->fonts->BlitText(20, 20, 0, "f2 player physics: enabled");
	}
	else {
		App->fonts->BlitText(20, 20, 0, "f2 player physics: disabled");
	}
	if (gravityEnabled) {
		App->fonts->BlitText(20, 40, 0, "f3 gravity: enabled");
	}
	else {
		App->fonts->BlitText(20, 40, 0, "f3 gravity: disabled");
	}
	if (aerodynamicDragEnabled) {
		App->fonts->BlitText(20, 60, 0, "f4 aerodynamic drag: enabled");
	}
	else {
		App->fonts->BlitText(20, 60, 0, "f4 aerodynamic drag: disabled");
	}
	if (hydrodynamicDragEnabled) {
		App->fonts->BlitText(20, 80, 0, "f5 hydrodynamic drag: enabled");
	}
	else {
		App->fonts->BlitText(20, 80, 0, "f5 hydrodynamic drag: disabled");
	}
	if (hydrodynamicBuoyancyEnabled) {
		App->fonts->BlitText(20, 100, 0, "f6 hydrodynamic buoyancy: enabled");
	}
	else {
		App->fonts->BlitText(20, 100, 0, "f6 hydrodynamic buoyancy: disabled");
	}
	if (debugSpeed) {
		App->fonts->BlitText(20, 120, 0, "f7 debug player speed: enabled");
	}
	else {
		App->fonts->BlitText(20, 120, 0, "f7 debug player speed: disabled");
	}
	if (pause) {
		App->fonts->BlitText(20, 180, 0, "p pause: enabled");
	}
	else {
		App->fonts->BlitText(20, 180, 0, "p pause: disabled");
	}
	

	sprintf_s(radiusText, 4, "%d", App->scene_intro->actualPlayer->data->getRadius());
	App->fonts->BlitText(20, 140, 0, "actual player shooting radius: ");
	App->fonts->BlitText(265, 140,0, radiusText);

	sprintf_s(angleText, 11, "%f", RADTODEG * abs(App->scene_intro->actualPlayer->data->getAngle()));
	App->fonts->BlitText(20, 160, 0, "actual player shooting angle: ");
	App->fonts->BlitText(255, 160, 0, angleText);
	
	return UPDATE_CONTINUE;
}

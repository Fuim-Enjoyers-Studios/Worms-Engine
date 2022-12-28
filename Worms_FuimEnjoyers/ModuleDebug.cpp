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
	// Colors
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
		else if (element->data->ctype == ColliderType::ENTITY) {
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
		else if (element->data->ctype == ColliderType::SHOT) {
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
		else if (element->data->ctype == ColliderType::GRENADE) {
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
	
	return UPDATE_CONTINUE;
}

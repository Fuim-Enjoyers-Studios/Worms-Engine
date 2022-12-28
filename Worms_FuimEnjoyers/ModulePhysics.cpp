#include "Globals.h"
#include "Application.h"
#include "ModulePhysics.h"
#include "math.h"

ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug = true;
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	world.atmosphere.density = 1.0f;
	world.atmosphere.windx = 10.0f;
	world.atmosphere.windy = 5.0f;

	return true;
}

// 
update_status ModulePhysics::PreUpdate()
{
	p2List_item<PhysBody*>* element = world.Elements.getFirst();
	// Process all elements in the world
	while (element != NULL)
	{
		// Skip element if static
		if (element->data->btype == BodyType::STATIC) { continue; }

		// Step #0: Clear old values
		// ----------------------------------------------------------------------------------------

		// Reset total acceleration and total accumulated force of the element
		element->data->force.x = 0.0f;
		element->data->force.y = 0.0f;
		element->data->acceleration.x = 0.0f;
		element->data->acceleration.y = 0.0f;

		// Step #1: Compute forces
		// ----------------------------------------------------------------------------------------

		// Gravity force
		p2Point<float> gforce;
		gforce.x = element->data->mass * 0.0f;
		gforce.y = element->data->mass * -10.0f; //Gravity is constant and downwards
		element->data->force += gforce; // Add this force to element's total force

		// Aerodynamic Drag force (only when not in water)
		if (!is_colliding_with_water(element))
		{
			p2Point<float> dforce;
			dforce.x = 0.0f, dforce.y = 0.0f;
			compute_aerodynamic_drag(dforce, element);
			element->data->force += dforce; // Add this force to element's total force
		}

		// Hydrodynamic forces (only when in water)
		if (is_colliding_with_water(element))
		{
			// Hydrodynamic Drag force
			p2Point<float> dforce;
			dforce.x = 0.0f, dforce.y = 0.0f;
			compute_hydrodynamic_drag(dforce, element, water);
			element->data->force += dforce; // Add this force to ball's total force

			// Hydrodynamic Buoyancy force
			p2Point<float> bforce;
			bforce.x = 0.0f, bforce.y = 0.0f;
			compute_hydrodynamic_buoyancy(bforce, element, water);
			element->data->force += bforce; // Add this force to ball's total force
		}

		// Other forces
		// ...

		// Step #2: 2nd Newton's Law
		// ----------------------------------------------------------------------------------------

		// SUM_Forces = mass * accel --> accel = SUM_Forces / mass
		element->data->acceleration.x = element->data->force.x / element->data->mass;
		element->data->acceleration.y = element->data->force.y / element->data->mass; 

		// Step #3: Integrate --> from accel to new velocity & new position
		// ----------------------------------------------------------------------------------------

		// We will use the 2nd order "Velocity Verlet" method for integration.
		integrator_velocity_verlet(element, dt);

		// Step #4: solve collisions
		// ----------------------------------------------------------------------------------------

		// Solve collision between element and ground
		if (is_colliding_with_ground(element))
		{
			// TP ball to ground surface
			if (element->data->GetShape() == ShapeType::BALL) {
				element->data->position.y = ground.y + ground.h + element->data->radius;
			}
			else if (element->data->GetShape() == ShapeType::RECTANGLE) {
				element->data->position.y = ground.y + ground.h + (element->data->h / 2);
			}

			// Elastic bounce with ground
			element->data->velocity.y = -element->data->velocity.y;

			// FUYM non-elasticity
			element->data->velocity.x *= element->data->coef_friction;
			element->data->velocity.y *= element->data->coef_restitution;
		}
	}

	return UPDATE_CONTINUE;
}

// 
update_status ModulePhysics::PostUpdate()
{
	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(!debug)
		return UPDATE_CONTINUE;

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");

	return true;
}

PhysBody* ModulePhysics::CreateCircle(int pos_x, int pos_y, int rad, BodyType bodyType) {
	PhysBody* body = new PhysBody(ShapeType::BALL, false);
	body->position.x = pos_x;
	body->position.y = pos_y;
	body->radius = rad;
	body->btype = bodyType;

	body->mass = 10.0f;
	body->surface = 1.0f;
	body->cd = 0.4f;
	body->cl = 1.2f;
	body->b = 10.0f;
	body->coef_friction = 0.9f;
	body->coef_restitution = 0.8f;

	body->ctype = ColliderType::UNKNOWN;

	world.Elements.add(body);

	return body;
}

PhysBody* ModulePhysics::CreateRectangle(int pos_x, int pos_y, int w, int h, BodyType bodyType) {
	PhysBody* body = new PhysBody(ShapeType::RECTANGLE, false);
	body->position.x = pos_x;
	body->position.y = pos_y;
	body->w = w;
	body->h = h;
	body->btype = bodyType;

	body->mass = 10.0f;
	body->surface = 1.0f;
	body->cd = 0.4f;
	body->cl = 1.2f;
	body->b = 10.0f;
	body->coef_friction = 0.9f;
	body->coef_restitution = 0.8f;

	body->ctype = ColliderType::UNKNOWN;

	world.Elements.add(body);

	return body;
}

PhysBody* ModulePhysics::CreateWaterRectangle(int pos_x, int pos_y, int w, int h) {
	PhysBody* body = new PhysBody(ShapeType::RECTANGLE, true);
	body->position.x = pos_x;
	body->position.y = pos_y;
	body->w = w;
	body->h = h;
	body->btype = BodyType::STATIC;

	body->density = 50.0f;
	body->velocity.x = -1.0f;
	body->velocity.y = 0.0f;

	body->ctype = ColliderType::WATER;

	world.Elements.add(body);

	return body;
}
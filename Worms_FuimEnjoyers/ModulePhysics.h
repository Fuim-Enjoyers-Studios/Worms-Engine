#pragma once
#include "Module.h"
#include "Globals.h"
#include <vector>


#define PIXELS_PER_METER (40.0f) //  40 pixel -> 1 meter
#define METER_PER_PIXEL (1.0f / PIXELS_PER_METER) // 1 meter / Pixels per meter

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)

// types of bodies
enum BodyType {
	DYNAMIC,
	STATIC
};

enum ShapeType {
	BALL,
	RECTANGLE
};

// types of Colliders
enum class ColliderType {
	ENTITY,
	GROUND,
	WATER,
	SHOT,
	GRENADE,
	UNKNOWN
};

class PhysBody {
public:
	ColliderType ctype;
	BodyType btype;

	//Position
	p2Point<float> position;

	//Velocity
	p2Point<float> velocity;

	//Acceleration
	p2Point<float> acceleration;

	//Force
	p2Point<float> force;

	//Mass
	float mass;

	//Density
	float density;

	//Aerodynamics
	float surface; // Effective wet surface
	float cl; // Aerodynamic Lift coefficient
	float cd; // Aerodynamic Drag coefficient
	float b; // Hydrodynamic Drag coefficient

	// Coefficients of friction and restitution in Bounces
	float coef_friction;
	float coef_restitution;

	//Shape BALL
	float radius;

	//Shape RECTANGLE
	float w, h;

private:
	ShapeType stype;
	bool water = false;

public:

	PhysBody(ShapeType stype, bool water) {
		this->stype = stype;
		this->water = water;
	}

	SDL_Rect pixelRect() {
		SDL_Rect pos_px;
		pos_px.x = METERS_TO_PIXELS(position.x);
		pos_px.y = SCREEN_HEIGHT - METERS_TO_PIXELS(position.y);
		pos_px.w = METERS_TO_PIXELS(w);
		pos_px.h = METERS_TO_PIXELS(-h);
		return pos_px;
	}

	void SetPosition(int x, int y) {
		position.x = x;
		position.y = y;
	}

	void SetMass(int mass) {
		this->mass = mass;
	}

	void SetVelocity(int x, int y) {
		velocity.x = x;
		velocity.y = y;
	}

	void SetAcceleration(int x, int y) {
		acceleration.x = x;
		acceleration.y = y;
	}

	void SetForce(int x, int y) {
		force.x = x;
		force.y = y;
	}

	ShapeType GetShape() {
		return stype;
	}
};

struct Atmosphere
{
	float density;
	float windx;
	float windy;
};

struct World
{
	Atmosphere atmosphere;
	p2List<PhysBody*> Elements;
};

class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	PhysBody* CreateCircle(int pos_x, int pos_y, int rad, BodyType bodyType);
	PhysBody* CreateRectangle(int pos_x, int pos_y, int w, int h, BodyType bodyType);
	PhysBody* CreateWaterRectangle(int pos_x, int pos_y, int w, int h);

	World world;

	//Time between frames
	float dt = 1.0 / 60.0;

private:

	bool debug;
};
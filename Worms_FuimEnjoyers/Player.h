#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include "Animation.h"
//#include "ModulePhysics.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class Player : public Entity
{
public:

	Player(const char* path, iPoint posi);
	
	virtual ~Player();

	bool Start();

	bool Update();

	bool CleanUp();

public:

	PhysBody* getBody()
	{
		return body;
	}

private:
	
	//L02: DONE 1: Declare player parameters
	iPoint pos;
	int w, h;

	iPoint objective;
	iVector projectileVector;

	SDL_Texture* texture;
	const char* texturePath;
	//animation stuff
	Animation* currentAnimation = nullptr;

	Animation IdleAnimation;
	Animation WalkRightAnimation;
	Animation WalkLeftAnimation;
	Animation JumpRightAnimation;
	Animation JumpLeftAnimation;
	Animation DeathAnimation;

	PhysBody* body = nullptr;

	int deathSound;
	int state;
	bool facing;

};

#endif // __PLAYER_H__
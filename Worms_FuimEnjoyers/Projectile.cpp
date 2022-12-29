#include "Application.h"
#include "Module.h"
#include "Projectile.h"
#include "Log.h"
#include "p2Point.h"

Projectile::Projectile(const char* path, iPoint posi) : Entity(EntityType::PROJECTILE)
{
	texturePath = path;
	position = posi;
}

Projectile::~Projectile() {

}

bool Projectile::Start() {

	//initilize textures
	texture = App->textures->Load(texturePath);
	return true;
}

bool Projectile::Update()
{
	if (!App->physics->pause)
	{
		//here write how projectile updates if game is NOT paused
		pos.y += 1;

	}

	App->renderer->Blit(texture, position.x, position.y);
	return true;
}

bool Projectile::CleanUp()
{
	App->textures->Unload(texture);
	return true;
}

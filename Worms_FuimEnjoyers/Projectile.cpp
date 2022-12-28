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
	pos.y += 1;
	App->renderer->Blit(texture, position.x, position.y);
	return true;
}

bool Projectile::CleanUp()
{
	App->textures->Unload(texture);
	return true;
}

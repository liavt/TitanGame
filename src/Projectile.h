#pragma once
#ifndef TITAN_PROJECTILE_H
#define TITAN_PROJECTILE_H

#include <MACE/MACE.h>

class Projectile: public mc::gfx::Entity2D {
public:
	Projectile(const mc::gfx::Entity* en, const float strength);

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p) override;
private:
	float accelY;
	float strength;
};

#endif
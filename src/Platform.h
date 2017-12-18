#pragma once
#ifndef TITAN_PLATFORM_H
#define TITAN_PLATFORM_H

#include <MACE/MACE.h>

class Projectile: public mc::gfx::Entity2D {
public:
	Projectile(const mc::gfx::Entity* en);

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p) override;
private:
	float accelY;
};

#endif
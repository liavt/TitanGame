#pragma once
#ifndef TITAN_CHARACTER_H
#define TITAN_CHARACTER_H

#include <MACE/MACE.h>

#include "Projectile.h"

class Character: public mc::gfx::Entity2D {
public:
	Character();

	void onInit() override;

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p) override;

	void removeHealth(const float h);
private:
	float accelY = 0.0f, energy;

	bool chargingUp = false;

	float health = 1.0f;

	Projectile ball;

	mc::gfx::Text healthDisplay;

	mc::gfx::ProgressBar energyBar = mc::gfx::ProgressBar(0.0f, 1.0f, 0.0f);
};

#endif

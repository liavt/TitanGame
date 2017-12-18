#pragma once

#ifndef TITAN_BOSS_H
#define TITAN_BOSS_H

#include <MACE/MACE.h>

class Boss: public mc::gfx::Entity2D {
public:
	Boss();

	void onInit() override;

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p) override;

	void removeHealth(const float h);

private:
	float health;

	mc::gfx::ProgressBar healthBar = mc::gfx::ProgressBar(0.0f, 1.0f, 1.0f);
};

#endif
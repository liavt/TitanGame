#pragma once

#ifndef TITAN_BOSS_H
#define TITAN_BOSS_H

#include <MACE/MACE.h>

enum class BossState {
	BREAK_START, BREAK, SHOOT_BALL_START, SHOOT_BALL, AIM_BALL_START, AIM_BALL
};

class Boss: public mc::gfx::Entity2D {
public:
	Boss();

	void onInit() override;

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p);

	void removeHealth(const float h);

private:
	float health;

	BossState state = BossState::BREAK_START;

	long ticksClock = 0;

	mc::gfx::ProgressBar healthBar = mc::gfx::ProgressBar(0.0f, 1.0f, 1.0f);
};

#endif
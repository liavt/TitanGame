#pragma once
#ifndef TITAN_BULLET_H
#define TITAN_BULLET_H

#include <MACE/MACE.h>

class Bullet: public mc::gfx::Entity2D {
public:
	void onUpdate() override;
private:
};

class BallBullet: public Bullet {
public:
	void onInit() override;

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p) override;
};

class AimedBullet: public BallBullet {
public:
	void onInit() override;

	void onUpdate() override;
private:
	float accelX, accelY;
};

#endif

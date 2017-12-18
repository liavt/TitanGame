#pragma once
#ifndef TITAN_BULLET_H
#define TITAN_BULLET_H

#include <MACE/MACE.h>

class Bullet: public mc::gfx::Entity2D {
public:
	Bullet();

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p) override;
private:
};

#endif

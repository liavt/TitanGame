#pragma once
#ifndef TITAN_WORLD_H
#define TITAN_WORLD_H

#include <MACE/MACE.h>

class World: public mc::gfx::Entity2D {
public:
	World();

	void onUpdate() override;

	void onRender(mc::gfx::Painter& p) override;
};

#endif
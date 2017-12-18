#include "World.h"

#include <iostream>

using namespace mc;

const Vector4f platforms[] = {
	{ 0.0f, -0.9f, 1.0f, 0.1f },
};

World::World() : mc::gfx::Entity2D() {
	setWidth(1.0f);
	setHeight(1.0f);
}

void World::onUpdate() {
	for (SmartPointer<gfx::Entity> e : getChildren()) {
		//const gfx::Entity::Metrics met = e->getMetrics();
	}
}

void World::onRender(mc::gfx::Painter & p) {
	p.setTexture(Colors::GREEN, gfx::Enums::TextureSlot::FOREGROUND);
	p.setForegroundColor(Colors::GREEN);
	for (Index i = 0; i < os::getArraySize(platforms); ++i) {
		p.fillRect(platforms[i]);
	}
}

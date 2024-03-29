#include "Projectile.h"
#include "Main.h"
#include "Boss.h"

#include <iostream>

using namespace mc;

Projectile::Projectile(const gfx::Entity* en, const float str) : gfx::Entity2D(), accelY((0.2f * str) + 0.01f), strength(str) {
	setWidth(0.05f);
	setHeight(0.05f);
	setX(en->getX());
	setY(en->getY());
}

void Projectile::onUpdate() {
	accelY -= GRAVITY;

	translate(0.01f + (0.07f * strength), accelY);

	const TransformMatrix bossTransform = getBoss().getTransformation();

	const Vector4f bossAABB = Vector4f({ bossTransform.translation.x() * 0.5f + 0.5f, bossTransform.translation.y() * 0.5f + 0.5f, bossTransform.scaler.x(), bossTransform.scaler.y() });
	const Vector4f projAABB = Vector4f({ getX() * 0.5f + 0.5f, getY() * 0.5f + 0.5f, getWidth(), getHeight() });

	if (projAABB.x() < bossAABB.x() + bossAABB.z() &&
		projAABB.x() + projAABB.z() > bossAABB.x() &&
		projAABB.y() < bossAABB.y() + bossAABB.w() &&
		projAABB.w() + projAABB.y() > bossAABB.y()) {
		getBoss().removeHealth(0.05f);
		setProperty(gfx::Entity::DEAD, true);
	}

	if (getX() + getWidth() > BOUND_RIGHT || getY() - getHeight() < BOUND_BOT || getY() + getHeight() > BOUND_TOP) {
		setProperty(gfx::Entity::DEAD, true);
	}
}

void Projectile::onRender(mc::gfx::Painter & p) {
	p.rotate(0.0f, 0.0f, strength);
	p.setTexture(gfx::getCurrentWindow()->getContext()->getOrCreateTextureFromFile("TitanGame-ball", RES_PATH "ball.png"));
	p.disableRenderFeatures(gfx::Enums::RenderFeatures::STORE_ID | gfx::Enums::RenderFeatures::DISCARD_INVISIBLE);
	p.drawQuad(gfx::Enums::Brush::TEXTURE);
}

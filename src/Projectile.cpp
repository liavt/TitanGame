#include "Projectile.h"
#include "Main.h"

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

}

void Projectile::onRender(mc::gfx::Painter & p) {
	p.rotate(0.0f, 0.0f, 0.1f);
	p.setTexture(gfx::getCurrentWindow()->getContext()->getOrCreateTexture("TitanGame-ball", []() {
		return gfx::Texture::createFromFile("D:/Workspace/TitanGame/res/ball.png");
	}), gfx::Enums::TextureSlot::FOREGROUND);
	p.drawQuad(gfx::Enums::Brush::TEXTURE, gfx::Enums::RenderFeatures::TEXTURE);

	const TransformMatrix bossTransform = getBoss().getTransformation();

	const Vector4f bossAABB = Vector4f({ bossTransform.translation.x(), bossTransform.translation.y(), bossTransform.scaler.x(), bossTransform.scaler.y() });
	const Vector4f projAABB = Vector4f({ getX(), getY(), getWidth(), getHeight() });

	if (projAABB.x() < bossAABB.x() + bossAABB.z() &&
		projAABB.x() + projAABB.z() > bossAABB.x() &&
		projAABB.y() < bossAABB.y() + bossAABB.w() &&
		projAABB.w() + projAABB.y() > bossAABB.y()) {
		getBoss().removeHealth(0.05f);
		setProperty(gfx::Entity::DEAD, true);
	}

	if (getX() + getWidth() > 1.0f || getY() - getHeight() < -1.0f || getY() + getHeight() > 1.0f) {
		setProperty(gfx::Entity::DEAD, true);
	}
}

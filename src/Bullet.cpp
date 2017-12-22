#include "Bullet.h"
#include "Main.h"
#include "Character.h"
#include "Boss.h"
#include <cmath>

#include <iostream>

using namespace mc;

void Bullet::onUpdate() {
	gfx::Entity2D::onUpdate();

	const TransformMatrix charTransform = getCharacter().getTransformation();

	const Vector4f projAABB = Vector4f({ (charTransform.translation.x() / 2.0f) + 0.5f, (charTransform.translation.y() / 2.0f) + 0.5f, charTransform.scaler.x(), charTransform.scaler.y() });
	const Vector4f bossAABB = Vector4f({ (getX() / 2.0f) + 0.5f, (getY() / 2.0f) + 0.5f, getWidth(), getHeight() });

	if (projAABB.x() < bossAABB.x() + bossAABB.z() &&
		projAABB.x() + projAABB.z() > bossAABB.x() &&
		projAABB.y() < bossAABB.y() + bossAABB.w() &&
		projAABB.w() + projAABB.y() > bossAABB.y()) {
		getCharacter().removeHealth(0.05f);
		setProperty(gfx::Entity::DEAD, true);
	}

	if (getX() + getWidth() > BOUND_RIGHT || getY() - getHeight() < BOUND_BOT || getY() + getHeight() > BOUND_TOP || getX() - getWidth() < BOUND_LEFT) {
		setProperty(gfx::Entity::DEAD, true);
	}
}

void BallBullet::onInit() {
	setWidth(0.05f);
	setHeight(0.05f);
	setY(-0.75f);
	setX(0.7f);
}

void BallBullet::onUpdate(){
	translate(-0.02f, 0.0f);

	Bullet::onUpdate();
}

void BallBullet::onRender(gfx::Painter& p){
	p.rotate(0.0f, 0.0f, -0.25f);
	p.setTexture(gfx::getCurrentWindow()->getContext()->getOrCreateTextureFromFile("TitanGame-ball", MACE_CONCAT(RES_PATH, "ball.png")));
	p.disableRenderFeatures(gfx::Enums::RenderFeatures::STORE_ID | gfx::Enums::RenderFeatures::DISCARD_INVISIBLE);
	p.drawQuad(gfx::Enums::Brush::TEXTURE);
}

void AimedBullet::onInit() {
	BallBullet::onInit();

	setX(getBoss().getX() - (getBoss().getWidth() / 2.0f));
	setY(getBoss().getY());

	const TransformMatrix& charTransform = getCharacter().getTransformation();
	const TransformMatrix& ourTransform = getTransformation();

	const float distanceX = math::abs(ourTransform.translation.x() - charTransform.translation.x());
	const float distanceY = math::abs(ourTransform.translation.y() - charTransform.translation.y());
	const float tangent = std::atan2(distanceX, distanceY);

	accelX = -0.05f * tangent;
	accelY = -0.05f * (1.5f - tangent);
}

void AimedBullet::onUpdate(){
	translate(accelX, accelY);

	Bullet::onUpdate();
}

#include "Boss.h"

using namespace mc;

Boss::Boss() : mc::gfx::Entity2D(), health(1.0f) {
	setWidth(0.2f);
	setHeight(0.2f);
	setX(0.8f);
	setY(0.4f);
}

void Boss::onInit() {
	healthBar.setForegroundTexture(Colors::GREEN);
	healthBar.setBackgroundTexture(Colors::RED);
	healthBar.setSelectionTexture(gfx::Texture::getGradient());
	healthBar.setWidth(0.2f);
	healthBar.setX(-0.9f);
	addChild(healthBar);
}

void Boss::onUpdate() {
	healthBar.setProgress(health);
}

void Boss::onRender(mc::gfx::Painter & p) {
	p.drawImage(Colors::RED);
}

void Boss::removeHealth(const float h) {
	health -= h;
}

#include "Boss.h"
#include "Bullet.h"
#include "Main.h"

#include <iostream>

using namespace mc;

Boss::Boss() : mc::gfx::Entity2D(), health(1.0f) {
	setWidth(0.13f);
	setHeight(0.13f);
	setX(0.78f);
	setY(0.06f);
}

void Boss::onInit() {
	healthBar.setForegroundTexture(gfx::Texture::createFromFile(RES_PATH "fire.png", gfx::Enums::ImageFormat::RGB, gfx::TextureDesc::Wrap::WRAP));
	healthBar.setBackgroundTexture(Colors::GRAY);
	healthBar.setSelectionTexture(gfx::Texture::createFromFile(RES_PATH "gradient.png", gfx::Enums::ImageFormat::LUMINANCE));
	healthBar.setHeight(0.05f);
	healthBar.setY(0.95f);
	getRoot()->addChild(healthBar);
}

void Boss::onUpdate() {
	healthBar.setProgress(health);
	if (isPlaying()) {
		healthBar.getForegroundTexture().getTransform().y() += 0.01f;

		++ticksClock;
	}

	makeDirty();
}

void Boss::onRender(gfx::Painter& p) {
	p.drawImage(Colors::BLACK);

	switch (state) {
		case BossState::BREAK_START:
			ticksClock = 0;
			state = BossState::BREAK;
			MACE_FALLTHROUGH;
		case BossState::BREAK:
			if (ticksClock > 60) {
				state = BossState::SHOOT_BALL_START;
			}
			break;
		case BossState::SHOOT_BALL_START:
			ticksClock = 0;
			state = BossState::SHOOT_BALL;
			MACE_FALLTHROUGH;
		case BossState::SHOOT_BALL:
			if (ticksClock % 50 == 0) {
				getParent()->addChild(std::shared_ptr<gfx::Entity>(new BallBullet()));
			}
			if (ticksClock > 200) {
				state = BossState::AIM_BALL_START;
			}
			break;
		case BossState::AIM_BALL_START:
			ticksClock = 0;
			state = BossState::AIM_BALL;
			MACE_FALLTHROUGH;
		case BossState::AIM_BALL:
			if (ticksClock % 30 == 0) {
				getParent()->addChild(std::shared_ptr<gfx::Entity>(new AimedBullet()));
			}
			if (ticksClock > 200) {
				state = BossState::BREAK_START;
			}
			break;
	}

	if (health <= 0.0f) {
		getRoot()->addChild(std::shared_ptr<gfx::Entity>(new gfx::Text("YOU WIN", gfx::Fonts::SANS)));
		isPlaying() = false;
	}
}

void Boss::removeHealth(const float h) {
	health -= h;
}

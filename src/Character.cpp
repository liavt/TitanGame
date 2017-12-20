#include "Character.h"	
#include "Projectile.h"
#include "Main.h"

#include <iostream>

#define CHARACTER_SPEED_X 0.03f
#define ACCEL_MAX 0.11f
#define ACCEL_MIN -0.05f

using namespace mc;

Character::Character() : gfx::Entity2D(), ball(this, 0.01f) {
	setWidth(0.2f);
	setHeight(0.2f);
	ball.setProperty(gfx::Entity::DEAD, true);
}

void Character::onInit() {
	energyBar.setBackgroundTexture(Colors::GRAY);
	energyBar.setForegroundTexture(Colors::DARK_BLUE);
	energyBar.setSelectionTexture(gfx::Texture::getGradient());
	energyBar.setHeight(0.7f);
	energyBar.setWidth(0.7f);
	energyBar.setY(1.5f);
	addChild(energyBar);

	healthDisplay = gfx::Text("Meme", gfx::Fonts::SANS);
	healthDisplay.setTexture(Colors::BLACK);
	healthDisplay.setVerticalAlign(gfx::Enums::VerticalAlign::TOP);
	addChild(healthDisplay);
}

void Character::onUpdate() {
	if (gfx::Input::isKeyDown(gfx::Input::W) && getY() - getHeight() == BOUND_BOT) {
		accelY = ACCEL_MAX;
	}


	if (gfx::Input::isKeyDown(gfx::Input::D)) {
		translate(CHARACTER_SPEED_X, 0.0f);
	}

	if (gfx::Input::isKeyDown(gfx::Input::A)) {
		translate(-CHARACTER_SPEED_X, 0.0f);
	}

	accelY -= GRAVITY;

	if (accelY > ACCEL_MAX) {
		accelY = ACCEL_MAX;
	} else if (accelY < ACCEL_MIN) {
		accelY = ACCEL_MIN;
	}

	translate(0.0f, accelY);

	if (getY() - getHeight() < BOUND_BOT) {
		setY(BOUND_BOT + getHeight());
	} else if (getY() + getHeight() > BOUND_TOP) {
		setY(BOUND_TOP - getHeight());
	}

	if (getX() - getWidth() < BOUND_LEFT) {
		setX(BOUND_LEFT + getWidth());
	} else if (getX() + getWidth() > BOUND_RIGHT) {
		setX(BOUND_RIGHT - getWidth());
	}

	if (!ball.getProperty(gfx::Entity::INIT)) {
		if (!chargingUp && gfx::Input::isKeyDown(gfx::Input::SPACE)) {
			chargingUp = true;
		}

		if (chargingUp && gfx::Input::isKeyDown(gfx::Input::SPACE)) {
			if (energy <= 1.0f) {
				energy += 0.025f;
			}
		}

		if (chargingUp && gfx::Input::isKeyReleased(gfx::Input::SPACE)) {
			ball = Projectile(this, energy);
			energy = 0.0f;
			chargingUp = false;
		}
	}

	energyBar.setProgress(energy);
	energyBar.setProperty(gfx::Entity::DISABLED, !chargingUp);

	healthDisplay.setText(std::to_wstring(health));
}

void Character::onRender(gfx::Painter & p) {
	p.push();
	p.setTexture(gfx::getCurrentWindow()->getContext()->getOrCreateTextureFromFile("TitanGame-wheels", MACE_CONCAT(RES_PATH, "wheels.png")));
	p.getTransformation().rotation[2] = getX() * 8.0f;
	p.getTransformation().scaler = { 0.25, 0.25f, 0.0f };
	p.getTransformation().translation = { -0.75f, -0.75f, 0.0f };
	p.drawQuad(gfx::Enums::Brush::TEXTURE);
	p.translate(0.75f, 0.0f);
	p.drawQuad(gfx::Enums::Brush::TEXTURE);
	p.translate(0.75f, 0.0f);
	p.drawQuad(gfx::Enums::Brush::TEXTURE);
	p.pop();

	p.drawImage(gfx::getCurrentWindow()->getContext()->getOrCreateTextureFromFile("TitanGame-robot", MACE_CONCAT(RES_PATH, "robot.png")));

	if (ball.getParent() == nullptr) {
		getRoot()->addChild(ball);
	}
}

void Character::removeHealth(const float h) {
	health -= h;
}

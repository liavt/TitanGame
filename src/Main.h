#pragma once

#ifndef TITAN_MAIN_H
#define TITAN_MAIN_H

class Boss;
class Character;

Boss& getBoss();

Character& getCharacter();

#define GRAVITY 0.01f

#define BOUND_BOT -0.8f
#define BOUND_TOP 1.0f
#define BOUND_LEFT -1.0f
#define BOUND_RIGHT 0.8f

#define RES_PATH "D:/Workspace/TitanGame/res/"

#endif

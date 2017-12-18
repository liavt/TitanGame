#pragma once

#ifndef TITAN_MAIN_H
#define TITAN_MAIN_H

#include "Boss.h"

Boss& getBoss();

#define GRAVITY 0.01f

#define BOUND_BOT -0.8f
#define BOUND_TOP 1.0f
#define BOUND_LEFT -1.0f
#define BOUND_RIGHT 0.8f

#endif

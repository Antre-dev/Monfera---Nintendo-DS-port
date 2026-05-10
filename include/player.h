#pragma once
#include "gamestate.h"

extern int playerX, playerY;
void initPlayer();
void updatePlayer();
void drawPlayer();
void checkNPCInteraction(GameState &state);
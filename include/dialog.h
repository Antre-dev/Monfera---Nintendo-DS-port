#pragma once
#include "gamestate.h"

void startDialog(const char** lines, int count);
void updateDialog(GameState &state);
void drawDialog();
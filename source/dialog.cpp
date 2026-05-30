#
#include <stdio.h>
#include <nds.h>
#include "gamestate.h"

static const char** dialogLines = nullptr;
static int lineCount = 0;
static int currentLine = 0;

void startDialog(const char** lines, int count) {
    dialogLines = lines;
    lineCount = count;
    currentLine = 0;
}
void updateDialog(GameState &state) {
    if (keysDown() & KEY_A) {
        currentLine++;
        if (currentLine >= lineCount) {
            state = STATE_EXPLORE;
            currentLine = 0;
            dialogLines = nullptr;
            consoleClear();
        }
    }
}
void drawDialog() {
    if (dialogLines == nullptr) return;
    consoleClear();
    iprintf("================================ ");
    iprintf("%s", dialogLines[currentLine]);
    iprintf("================================ ");
    if (currentLine == lineCount -1) {
        iprintf(" [A] ok");
    } else {
        iprintf(" [A] next");
    }
}

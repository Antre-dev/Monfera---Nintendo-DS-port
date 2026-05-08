#include <nds.h>
#include <stdio.h>

#include "player.h"

int main(void) {

    consoleDemoInit();

    initPlayer();

    while(1) {

        updatePlayer();

        drawPlayer();

        swiWaitForVBlank();
    }

    return 0;
}
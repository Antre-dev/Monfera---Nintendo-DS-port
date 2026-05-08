#include <nds.h>
#include <stdio.h>

#include "player.h"
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

int main(void)
{
    consoleDemoInit();

    initPlayer();
    mmInitDefaultMem((mm_addr)soundbank_bin);
    mmSelectMode(MM_MODE_A);
    t_mmsoundeffect sfx;
    sfx.id = SFX_MAIN_THEME_SONG_8;
    sfx.rate = 1024;
    sfx.handle = 0;
    sfx.volume = 255;
    sfx.panning = 128;
    mmEffectEx(&sfx);

    while (1)
    {
        updatePlayer();
        drawPlayer();
        swiWaitForVBlank();
    }

    return 0;
}
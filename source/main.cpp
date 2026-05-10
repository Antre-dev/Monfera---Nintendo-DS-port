#include <nds.h>
#include <stdio.h>

#include "player.h"
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include "npc.h"
#include "gamestate.h"
#include "dialog.h"

int main(void)
{
    GameState state = STATE_EXPLORE;
    consoleDemoInit();
    videoSetMode(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_SPRITE);
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    initNPC();
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
        scanKeys();
        if (state == STATE_EXPLORE)
        {
            updatePlayer();
            checkNPCInteraction(state);
        }
        else if (state == STATE_DIALOG)
        {
            updateDialog(state);
        }
        drawPlayer();
        drawNPC();
        drawDialog();
        oamUpdate(&oamMain);
        swiWaitForVBlank();
    }

    return 0;
}
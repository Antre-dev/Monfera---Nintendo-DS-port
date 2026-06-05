#include <nds.h>
#include <stdio.h>

#include "player.h"
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include "npc.h"
#include "gamestate.h"
#include "dialog.h"
#include "house.h"

int main(void)
{
    GameState state = STATE_EXPLORE;
    consoleDemoInit();
    videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankB(VRAM_B_MAIN_SPRITE);
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    initNPC();
    initPlayer();
    initHouse();
    mmInitDefaultMem((mm_addr)soundbank_bin);
    mmLoadEffect(SFX_MAIN_THEME_SONG_8); // load first!
    mm_sound_effect sfx;
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
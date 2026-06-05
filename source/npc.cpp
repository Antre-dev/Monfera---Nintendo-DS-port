#include <nds.h>
#include <stdio.h>

#include "npc.h"
#include "player_sprite_up.h"
#include "player_sprite_down.h"
#include "player_sprite_left.h"
#include "player_sprite_right.h"
#include "player.h"
#include "gamestate.h"
#include "dialog.h"

int npcX = 80;
int npcY = 120;
static u16 *gfxUp, *gfxDown, *gfxLeft, *gfxRight;
static const char* npcDialog[] = {
    "Hey, im dr.Monfera.I created monferas",
    "Go outside and explore the world and then comeback to me!"
};
static const int npcDialogLen = 2;

void initNPC()
{
    gfxDown = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
    gfxUp = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
    gfxRight = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
    gfxLeft = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

    dmaCopy(player_sprite_downTiles, gfxDown, player_sprite_downTilesLen);
    dmaCopy(player_sprite_upTiles, gfxUp, player_sprite_upTilesLen);
    dmaCopy(player_sprite_rightTiles, gfxRight, player_sprite_rightTilesLen);
    dmaCopy(player_sprite_leftTiles, gfxLeft, player_sprite_leftTilesLen);

    dmaCopy(player_sprite_downPal, SPRITE_PALETTE, player_sprite_downPalLen);
}

bool isNearNPC() {
    int dx= playerX - npcX;
    int dy = playerY - npcY;
    return (dx*dx + dy*dy) < (24*24);
}
void checkNPCInteraction(GameState &state) {
    if (isNearNPC() && (keysDown() & KEY_A)) {
        startDialog(npcDialog, npcDialogLen);
        state = STATE_DIALOG;
    }
}

void drawNPC()
{
    u16 *gfx;
    gfx = gfxDown;

    oamSet(
        &oamMain,
        1,
        npcX,
        npcY,
        0,
        0,
        SpriteSize_16x16,
        SpriteColorFormat_256Color,
        gfx,
        -1,
        false, false, false, false, false);

    oamUpdate(&oamMain);
}
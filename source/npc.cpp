#include <nds.h>
#include <stdio.h>

#include "player.h"
#include "player_sprite_up.h"
#include "player_sprite_down.h"
#include "player_sprite_left.h"
#include "player_sprite_right.h"

static int playerX = 100;
static int playerY = 80;

static u16 *gfxUp, *gfxDown, *gfxLeft, *gfxRight;

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

void drawNPC()
{
    u16 *gfx;
    gfx = gfxDown;

    oamSet(
        &oamMain,
        1,
        playerX,
        playerY,
        0,
        0,
        SpriteSize_16x16,
        SpriteColorFormat_256Color,
        gfx,
        -1,
        false, false, false, false, false);

    oamUpdate(&oamMain);
}
#include "house.h"
#include "house_image.h"

static int bg;

void initHouse() {
    bg = bgInit(2, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
    dmaCopy(house_imageBitmap, bgGetGfxPtr(bg), house_imageBitmapLen);
    dmaCopy(house_imagePal, BG_PALETTE, house_imagePalLen);
}
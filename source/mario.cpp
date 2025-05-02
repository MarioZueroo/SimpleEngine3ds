#include "mario.hpp"
#include "main.hpp"
C2D_Sprite idle1;
C2D_Sprite jump;
C2D_Sprite walking1;
C2D_Sprite walking2;
C2D_Sprite walking3;
//DEFINE FROM ORIGINAL SMB GAME
#define mariospeed 98.0f
#define jumpforce 250.0f
#define gravity 460.0f

void mario::marioinit() {
//INITIALIZE MARIO SPRITES
    smallmariosprts = C2D_SpriteSheetLoad("romfs:/gfx/mariosmall.t3x");

    C2D_SpriteFromSheet(&idle1, smallmariosprts, 0);
    C2D_SpriteFromSheet(&jump, smallmariosprts, 1);
    C2D_SpriteFromSheet(&walking1, smallmariosprts, 2);
    C2D_SpriteFromSheet(&walking2, smallmariosprts, 3);
    C2D_SpriteFromSheet(&walking3, smallmariosprts, 4);
    
C2D_SpriteSetScale(&idle1,   1.0f, 1.0f);
C2D_SpriteSetScale(&jump,    1.0f, 1.0f);
C2D_SpriteSetScale(&walking1,1.0f, 1.0f);
C2D_SpriteSetScale(&walking2,1.0f, 1.0f);
C2D_SpriteSetScale(&walking3,1.0f, 1.0f);

C2D_SpriteSetCenter(&idle1,   0.5f, 0.5f);
C2D_SpriteSetCenter(&jump,    0.5f, 0.5f);
C2D_SpriteSetCenter(&walking1,0.5f, 0.5f);
C2D_SpriteSetCenter(&walking2,0.5f, 0.5f);
C2D_SpriteSetCenter(&walking3,0.5f, 0.5f);
   my = SCREEN_HEIGHT / 2; 
   mx = SCREEN_WIDTH / 2;
}
void mario::control() {
    //BASIC CONTROL
    u32 kheld = hidKeysHeld();
    u32 kdown = hidKeysDown();
    
    if ((kheld & KEY_LEFT))
    {
    mirror = true;
    directionx = -1;
    } else if ((kheld & KEY_RIGHT))
    {
    mirror = false;    
    directionx = 1;
    } else {
    directionx = 0;
    } 
    
    if ((kdown & KEY_A) && onfloor) {
        vy = -jumpforce;
        onfloor = false;
        stateplayer = jumping;
    }

   //GRAVITY
    vy += gravity * deltaTime;

    
    
    mx +=  (mariospeed * directionx) * deltaTime;
    my += vy * deltaTime;
}





void mario::update() {
    
control();

//ANIMATION
if (stateplayer == walking) {
    animTimer += deltaTime;
    if (animTimer >= animSpeed) {
        animTimer = 0.0f;
        animFrame = (animFrame + 1) % 3; 
    }
} else {
    animFrame = 0;
    animTimer = 0.0f;
}


//SET MIRROR
C2D_SpriteSetScale(&idle1,   (mirror) ? -1.0f : 1.0f, 1.0f);
C2D_SpriteSetScale(&jump,    (mirror) ? -1.0f : 1.0f, 1.0f);
C2D_SpriteSetScale(&walking1,(mirror) ? -1.0f : 1.0f, 1.0f);
C2D_SpriteSetScale(&walking2,(mirror) ? -1.0f : 1.0f, 1.0f);
C2D_SpriteSetScale(&walking3,(mirror) ? -1.0f : 1.0f, 1.0f);



if ((my > 232 - 16) ) // FAKE FLOOR LOL
{
    onfloor = true;
    directiony = 0;
    my = 232 - 16;
    stateplayer = (directionx != 0) ? walking : idle;
}







C2D_SpriteSetPos(&idle1,   mx,my);
C2D_SpriteSetPos(&jump,    mx,my);
C2D_SpriteSetPos(&walking1,mx,my);
C2D_SpriteSetPos(&walking2,mx,my);
C2D_SpriteSetPos(&walking3,mx,my);

}
void mario::draw() {
//DRAW MARIO SPRITES DEPENDING ON STATE
switch (stateplayer)
{
case idle:

C2D_DrawSprite(&idle1);
break;
case jumping:

C2D_DrawSprite(&jump);
break;
case walking:

switch (animFrame) {
    case 0:
        C2D_DrawSprite(&walking1);
        break;
    case 1:
        C2D_DrawSprite(&walking2);
        break;
    case 2:
        C2D_DrawSprite(&walking3);
        break;
}




    /* code */
    break;

default:
    break;
}

}

void mario::killmario() {
    C2D_SpriteSheetFree(smallmariosprts);
}

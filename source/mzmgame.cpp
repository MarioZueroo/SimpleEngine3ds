
#include "main.hpp"







mario player;

void MZMGame::gameinit(C3D_RenderTarget* top, C3D_RenderTarget* bottom){
    
//initialize the game and services
    gfxInitDefault();
    romfsInit();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
        topTarget = top;
        bottomTarget = bottom;
    
player.marioinit();
initlevel();
}


//will draw on the top screen and bottom screen
void MZMGame::bothrender(){
        
        player.draw(); 
        rendertilemap();
        
}
// WILL DRAW ON THE TOP SCREEN ONLY
void MZMGame::toprender(){
        C2D_TargetClear(topTarget, clr);
        C2D_SceneBegin(topTarget);
        
        
        bothrender();
        
        
        
        
        
        
}


// WILL DRAW ON THE BOTTOM SCREEN ONLY
void MZMGame::bottomrender(){
        C2D_TargetClear(bottomTarget, clr);
        C2D_SceneBegin(bottomTarget);
        
        
        
        bothrender();
        
        
}    








//THE GAME LOOP
void MZMGame::gameloop() {
        gameupdate();
        gamedraw();
        
        
        
}
//GAME UPDATE
void MZMGame::gameupdate() {
        
        
        player.update();
        
}
//GAME DRAW
void MZMGame::gamedraw() {
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        toprender();
bottomrender();
           C2D_Flush();
        C3D_FrameEnd(0);
}
//GAME FINISH
//CLEAN UP THE GAME
void MZMGame::gamefinish() {
        romfsExit();
        player.killmario();
   killlevel();
    mcuHwcExit();
    ptmuExit();
    
    C2D_Fini();
    C3D_Fini();
    gfxExit();
}


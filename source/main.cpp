#include "main.hpp"


#include "mzmgame.hpp"





u64 tempoanterior = 0;
u64 tempoatual = 0;
double deltaTime = 0.0;
touchPosition touch;

MZMGame smb;
int main() {
    // Initialize  bottom and top screen
    C3D_RenderTarget* topScreen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    
    C3D_RenderTarget* bottomScreen = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
        
    smb.gameinit(topScreen, bottomScreen);
    
    

    
    tempoanterior = osGetTime();
    
    
    while (aptMainLoop()) {
      
        //delta time
        tempoatual = osGetTime();
        deltaTime = (tempoatual - tempoanterior)  / 1000.0f; 
        tempoanterior = tempoatual;
        
        hidScanInput();
        
        u32 kdown = hidKeysDown();
        
        
        
        smb.gameloop();
    
    
    
    
    
    
    if (kdown & KEY_START)
    {
        break;
    }
    
    
}
smb.gamefinish();

      

    return 0;
}

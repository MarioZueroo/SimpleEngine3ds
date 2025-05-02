#pragma once

#include "main.hpp"

#include "mzmgame.hpp"
class MZMGame {

    private:
    C3D_RenderTarget* topTarget;
    C3D_RenderTarget* bottomTarget;
    
    
    
    u32 clr = C2D_Color32(147, 144, 254, 0);
    public:

    
    
    void gameinit(C3D_RenderTarget* top, C3D_RenderTarget* bottom);
    void gameloop();
    void gameupdate();
    void gamedraw();
    void gamefinish();


    void bothrender();
    void toprender();
    void bottomrender();
};


#pragma once
#include "main.hpp"

enum state {idle, walking, jumping};
class mario
{
private:
    C2D_SpriteSheet smallmariosprts ;

    Sprite mariogfx;
    int currentindex = 0;
    int index = 0;
    int stateplayer = idle;
    double mx = 0;
    double my = 0;
    double vy = 0;
    bool mirror = false;
    bool onfloor = false;
    double directionx = 0;
    double directiony = 0;

    int animFrame = 0;          
    double animTimer = 0.0f;     
double animSpeed = 0.1f;       

public:


    void update(/* args */);
    void draw();
    void marioinit();
    void control();
    void killmario();
};


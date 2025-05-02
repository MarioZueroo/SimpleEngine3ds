#pragma once

// C/C++ Standard
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <cstring>
#include <tuple>
// 3DS Standard
#include <3ds.h>
#include <citro3d.h>
#include <citro2d.h>


typedef struct {
    C2D_Sprite spr[20];
    double dx, dy; // velocity
} Sprite;
//Shader headers

// Application
#define SCREEN_WIDTH  400
#define SCREEN_WIDTHbottom  320
#define SCREEN_HEIGHT 240
#define MAP_HEIGHT 15
#define MAP_WIDTH 25
#define TILE_SIZE 16

#include "sys/stat.h"
#include "unistd.h"


#include "mzmgame.hpp"
#include "mario.hpp"
#include <memory>
#include <vector>
#include "level.hpp"





extern u64 tempoanterior;
extern u64 tempoatual;
extern double deltaTime;



#include "level.hpp"
#include "main.hpp"

 C2D_SpriteSheet grafico;

C2D_Image tile1;
int tiletype = 0;
int tilemap[MAP_HEIGHT][MAP_WIDTH];
int posx ;
int posy ;

void initlevel(){

//SET THE ROLE TILE WITH THE NUMBER 0
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            for (int x = 0; x < MAP_WIDTH; x++)
            {
                tilemap[y][x] = 0;
    
            }
        }
    
//DRAW THE TILES IN THE LAST COLUMN
        for (int i = 0; i < MAP_WIDTH; i++)
        {
            tilemap[MAP_HEIGHT - 1][i] = 1;
        }
        
        
        grafico = C2D_SpriteSheetLoad("romfs:/gfx/tiles.t3x");

        tile1 = C2D_SpriteSheetGetImage(grafico, 0);
}


void rendertilemap(){
//DRAW THE TILES ON THE SCREEN
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            tiletype = tilemap[y][x];
            posx = x * TILE_SIZE ;
            posy = y * TILE_SIZE ;

switch (tiletype)
{
case 1:
    C2D_DrawImageAt(tile1, posx, posy, 0, NULL, 1.0f, 1.0f);
    break;

default:
    break;
}
        }
    }
}

void killlevel(){
    C2D_SpriteSheetFree(grafico);
    
}
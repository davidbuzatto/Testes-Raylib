/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>

#include "GameWorld.h"
#include "ResourceManager.h"

#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raygui.h"              // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->dummy = 0;

    return gw;

}

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld( GameWorld *gw ) {
    free( gw );
}

/**
 * @brief Reads user input and updates the state of the game.
 */
void inputAndUpdateGameWorld( GameWorld *gw ) {

}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( RAYWHITE );

    int xc = GetScreenWidth()/2;
    int yc = GetScreenHeight()/2;
    int w = 292;
    int s = 40;
    int fs = 120;

    DrawRectangle( xc-w, yc-w, w*2, w*2, BLACK );
    DrawRectangle( xc-w+s, yc-w+s, w*2-s*2, w*2-s*2, RAYWHITE );

    const char* t = "raylib";
    int tw = MeasureText( t, fs );

    DrawText( t, xc + w - s - tw - s, yc + w - s - fs - s, fs, BLACK );

    DrawFPS( 20, 20 );

    EndDrawing();

}
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

#include "raylib/raylib.h"
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    /*gw->animation = createAnimation( 
        rm.textureMap,
        (Vector2) { 0, 0 },
        (Vector2) { 32, 32 },
        3, 1.0f
    );*/

    /*gw->animation = createAnimation( 
        rm.textureMap,
        (Vector2) { 3, 35 },
        (Vector2) { 32, 32 },
        3, 1.0f
    );*/

    /*gw->animation = createAnimation( 
        rm.textureMap,
        (Vector2) { 0, 70 },
        (Vector2) { 32, 40 },
        3, 1.0f
    );*/

    gw->animation = createAnimation( 
        rm.textureMap,
        (Vector2) { 0, 110 },
        (Vector2) { 40, 32 },
        3, 1.0f
    );

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
    float delta = GetFrameTime();
    updateAnimation( &gw->animation, delta );
}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    drawAnimation( &gw->animation, GetMousePosition() );

    EndDrawing();

}
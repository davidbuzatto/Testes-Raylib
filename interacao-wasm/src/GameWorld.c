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

//https://emscripten.org/docs/porting/connecting_cpp_and_javascript/Interacting-with-code.html
#include <emscripten.h>

EM_JS( void, imprimirDados, ( float x, float y, char *texto ), {
    console.log( x, y, UTF8ToString( texto ) );
});

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->pos = (Vector2) { GetScreenWidth() / 2, GetScreenHeight() / 2 };
    gw->vel = (Vector2) { 100.0f, 100.0f };
    gw->raio = 20.0f;

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
    ClearBackground( WHITE );

    float delta = GetFrameTime();

    DrawCircleV( gw->pos, gw->raio, BLUE );
    DrawRectangleLines( 0, 0, GetScreenWidth(), GetScreenHeight(), BLACK );

    gw->pos.x += gw->vel.x * delta;
    gw->pos.y += gw->vel.y * delta;

    if ( gw->pos.x - gw->raio <= 0.0f ) {
        gw->pos.x = gw->raio;
        gw->vel.x = -gw->vel.x;
        imprimirDados( gw->pos.x, gw->pos.y, "esquerda" );
    } else if ( gw->pos.x + gw->raio >= GetScreenWidth() ) {
        gw->pos.x = GetScreenWidth() - gw->raio;
        gw->vel.x = -gw->vel.x;
        imprimirDados( gw->pos.x, gw->pos.y, "direita" );
    }

    if ( gw->pos.y - gw->raio <= 0.0f ) {
        gw->pos.y = gw->raio;
        gw->vel.y = -gw->vel.y;
        imprimirDados( gw->pos.x, gw->pos.y, "cima" );
    } else if ( gw->pos.y + gw->raio >= GetScreenHeight() ) {
        gw->pos.y = GetScreenHeight() - gw->raio;
        gw->vel.y = -gw->vel.y;
        imprimirDados( gw->pos.x, gw->pos.y, "baixo" );
    }

    EndDrawing();

}
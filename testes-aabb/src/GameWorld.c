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

#include "Entity.h"

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

    gw->e1 = (Entity) {
        .pos = { 10, 125 },
        .lastPos = { 0 },
        .vel = { 0 },
        .dim = { 100, 50 },
        .color = BLUE,
        .dragging = false
    };

    gw->e2 = (Entity) {
        .pos = { 150, 100 },
        .lastPos = { 0 },
        .vel = { 0 },
        .dim = { 50, 100 },
        .color = ORANGE,
        .dragging = false
    };

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
    Vector2 mousePos = GetMousePosition();

    static int offsetX = 0;
    static int offsetY = 0;
    static Entity *selectedEntity = NULL;

    /*if ( IsMouseButtonPressed( MOUSE_BUTTON_LEFT ) ) {

        if ( checkCollisionEntityPosition( &gw->e1, mousePos ) ) {
            gw->e1.dragging = true;
            selectedEntity = &gw->e1;
        } else if ( checkCollisionEntityPosition( &gw->e2, mousePos ) ) {
            gw->e2.dragging = true;
            selectedEntity = &gw->e2;
        } else {
            selectedEntity = NULL;
        }

        if ( selectedEntity != NULL ) {
            offsetX = selectedEntity->pos.x - mousePos.x;
            offsetY = selectedEntity->pos.y - mousePos.y;
        }

    }

    if ( IsMouseButtonUp( MOUSE_BUTTON_LEFT ) ) {
        gw->e1.dragging = false;
        gw->e2.dragging = false;
        selectedEntity = NULL;
    }*/

    if ( selectedEntity != NULL ) {

        Vector2 newPosition = {
            mousePos.x + offsetX,
            mousePos.y + offsetY
        };

        updateEntityPosition( selectedEntity, newPosition );

    } else {

        if ( IsKeyDown( KEY_LEFT ) ) {
            gw->e1.vel.x = -100;
        } else if ( IsKeyDown( KEY_RIGHT ) ) {
            gw->e1.vel.x = 100;
        } else {
            gw->e1.vel.x = 0;
        }

        if ( IsKeyDown( KEY_UP ) ) {
            gw->e1.vel.y = -100;
        } else if ( IsKeyDown( KEY_DOWN ) ) {
            gw->e1.vel.y = 100;
        } else {
            gw->e1.vel.y = 0;
        }

    }

    updateEntity( &gw->e1, delta );
    updateEntity( &gw->e2, delta );

    resolveCollisionEntityEntity( &gw->e1, &gw->e2 );
    //resolveCollisionEntityEntity( &gw->e2, &gw->e1 );

}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    drawEntity( &gw->e1 );
    drawEntity( &gw->e2 );

    DrawRectangleRec( getEntityEntityOverlapBB( &gw->e1, &gw->e2 ), GREEN );

    EndDrawing();

}
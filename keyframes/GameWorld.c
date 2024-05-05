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

#include "Ball.h"
#include "Timeline.h"
#include "Layer.h"
#include "Keyframe.h"

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );
    *gw = (GameWorld){0};

    Ball *ball = newBall( 
        (Vector2){ 
            GetScreenWidth() / 2,
            GetScreenHeight() / 2
        }, 
        50, 
        BLUE
    );
    
    Keyframe *keyframe1 = newKeyframe( ball->pos, 0 );
    Keyframe *keyframe2 = newKeyframe( (Vector2){ ball->pos.x + 100, ball->pos.y + 100 }, 1 );

    Layer *layer = newLayer( 2, ball );
    layer->keyframes[0] = keyframe1;
    layer->keyframes[1] = keyframe2;

    Timeline *timeline = newTimeline( 1, 5.0f );
    timeline->layers[0] = layer;
    
    gw->ball = ball;
    gw->timeline = timeline;

    return gw;

}

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld( GameWorld **gw ) {
    deleteTimeline( &(*gw)->timeline );
    deleteBall( &(*gw)->ball );
    free( *gw );
    *gw = NULL;
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

    if ( gw != NULL ) {
        drawTimeline( gw->timeline );
    }

    EndDrawing();

}
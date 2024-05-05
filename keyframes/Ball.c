#include <stdlib.h>
#include "Ball.h"
#include "raylib.h"

Ball *newBall( Vector2 pos, int radius, Color color ) {
    Ball *ball = (Ball*) malloc( sizeof( Ball ) );
    ball->pos = pos;
    ball->radius = radius;
    ball->color = color;
    return ball;
}

void deleteBall( Ball **ball ) {
    if ( *ball != NULL ) {
        free( *ball );
        *ball = NULL;
    }
}

void updateBall( Ball *ball ) {

}

void drawBall( Ball *ball ) {
    if ( ball != NULL ) {
        DrawCircleV( ball->pos, ball->radius, ball->color );
    }
}
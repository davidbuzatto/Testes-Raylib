#pragma once 

#include "raylib.h"

typedef struct Ball {
    Vector2 pos;
    int radius;
    Color color;
} Ball;

Ball *newBall( Vector2 pos, int radius, Color color );
void deleteBall( Ball **ball );
void updateBall( Ball *ball );
void drawBall( Ball *ball );
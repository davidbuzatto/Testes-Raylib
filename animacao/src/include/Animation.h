#pragma once

#include "raylib/raylib.h"

typedef struct Animation {

    Texture2D textureMap;
    Vector2 mapOrigin;
    int mapWidth;

    Vector2 spriteDim;

    int currentFrame;
    int frameQuantity;
    float timeCounter;
    float timeToNextFrame;

} Animation;

Animation createAnimation( Texture2D textureMap, Vector2 mapOrigin, Vector2 spriteDim, int frameQuantity, float timeToNextFrame );
void updateAnimation( Animation *animation, float delta );
void drawAnimation( Animation *animation, Vector2 pos );

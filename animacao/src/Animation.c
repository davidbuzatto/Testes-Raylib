#include "Animation.h"
#include "raylib/raylib.h"

Animation createAnimation( Texture2D textureMap, Vector2 mapOrigin, Vector2 spriteDim, int frameQuantity, float timeToNextFrame ) {

    Animation newAnimation = {
        .textureMap = textureMap,
        .mapOrigin = mapOrigin,
        .mapWidth = (int) ( spriteDim.y * frameQuantity ),
        .spriteDim = spriteDim,
        .currentFrame = 0,
        .frameQuantity = frameQuantity,
        .timeCounter = 0.0f,
        .timeToNextFrame = timeToNextFrame
    };

    return newAnimation;

}

void updateAnimation( Animation *animation, float delta ) {

    animation->timeCounter += delta;

    if ( animation->timeCounter >= animation->timeToNextFrame ) {
        animation->timeCounter = 0.0f;
        animation->currentFrame = ( animation->currentFrame + 1 ) % animation->frameQuantity;
    }

}

void drawAnimation( Animation *animation, Vector2 pos ) {

    DrawRectangleV( pos, (Vector2) { 10, 10 }, BLACK );

    DrawTexturePro( 
        animation->textureMap,
        (Rectangle) {
            .x = animation->mapOrigin.x + animation->currentFrame * animation->spriteDim.x,
            .y = animation->mapOrigin.y,
            .width = animation->spriteDim.x,
            .height = animation->spriteDim.y,
        },
        (Rectangle) {
            .x = pos.x,
            .y = pos.y,
            .width = animation->spriteDim.x,
            .height = animation->spriteDim.y,
        },
        (Vector2) { 0 },
        0.0f,
        WHITE
    );

}
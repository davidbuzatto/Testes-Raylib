#pragma once

#include "Ball.h"
#include "Keyframe.h"

typedef struct Layer {

    int keyframeQuantity;
    Keyframe **keyframes;

    Ball *ball;

} Layer;

Layer *newLayer( int keyframeQuantity, Ball *ball );
void deleteLayer( Layer **layer );
void updateLayer( Layer *layer );
void drawLayer( Layer *layer );
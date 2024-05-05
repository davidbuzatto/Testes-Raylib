#pragma once

#include "Layer.h"

typedef struct Timeline {

    int layerQuantity;
    Layer **layers;

    int currentFrame;
    float timeToNextFrame;
    float frameAcumulator;

} Timeline;

Timeline *newTimeline( int layerQuantity, float timeToNextFrame );
void deleteTimeline( Timeline **timeline );
void updateTimeline( Timeline *timeline );
void drawTimeline( Timeline *timeline );
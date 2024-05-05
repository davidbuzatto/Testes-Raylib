#include <stdlib.h>
#include "Layer.h"
#include "raylib.h"

Layer *newLayer( int keyframeQuantity, Ball *ball ) {
    Layer *layer = (Layer*) malloc( sizeof( Layer ) );
    layer->keyframeQuantity = keyframeQuantity;
    layer->keyframes = (Keyframe**) malloc( keyframeQuantity * sizeof( Keyframe** ) );
    layer->ball = ball;
    return layer;
}

void deleteLayer( Layer **layer ) {
    if ( *layer != NULL ) {
        for ( int i = 0; i < (*layer)->keyframeQuantity; i++ ) {
            deleteKeyframe( &(*layer)->keyframes[i] );
        }
        free( (*layer)->keyframes );
        free( *layer );
        *layer = NULL;
    }
}

void updateLayer( Layer *layer ) {

}

void drawLayer( Layer *layer ) {
    if ( layer != NULL ) {
        drawBall( layer->ball );
    }
}
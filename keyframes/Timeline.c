#include <stdlib.h>
#include "Timeline.h"
#include "raylib.h"

Timeline *newTimeline( int layerQuantity, float timeToNextFrame ) {
    Timeline *timeline = (Timeline*) malloc( sizeof( Timeline ) );
    timeline->layerQuantity = layerQuantity;
    timeline->layers = (Layer**) malloc( layerQuantity * sizeof( Layer** ) );
    timeline->currentFrame = 0;
    timeline->timeToNextFrame = timeToNextFrame;
    timeline->frameAcumulator = 0;
    return timeline;
}

void deleteTimeline( Timeline **timeline ) {
    if ( *timeline != NULL ) {
        for ( int i = 0; i < (*timeline)->layerQuantity; i++ ) {
            deleteLayer( &(*timeline)->layers[i] );
        }
        free( (*timeline)->layers );
        free( *timeline );
        *timeline = NULL;
    }
}

void updateTimeline( Timeline *timeline ) {

}

void drawTimeline( Timeline *timeline ) {
    if ( timeline != NULL ) {
        for ( int i = 0; i < timeline->layerQuantity; i++ ) {
            drawLayer( timeline->layers[i] );
        }
    }
}
#pragma once

#include "DetecteurDistance.h"

// 1000 / 1000 / us
const float SOUND_SPEED = 340.0;
// 340 m / s => 340 m / 1000 / 1000 / us
const float SOUND_SPEED_US = SOUND_SPEED / 1000000.0;
const unsigned long ULTRASOUND_MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

class DetecteurDistanceUltrason : public DetecteurDistance
{
    ;
};

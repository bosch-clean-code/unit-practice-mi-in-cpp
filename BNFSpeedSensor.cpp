#include "BNFSpeedSensor.h"
#include <random>

int  BNFSpeedSensor:: getCurrentSpeed(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);
    return distr(gen);
}


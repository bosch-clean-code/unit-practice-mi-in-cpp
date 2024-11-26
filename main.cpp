#include "SpeedMonitor.h"
#include "ConsoleLogger.h"
#include "BNFSpeedSensor.h"
#include "IOTCloudCommunicator.h"

int main() {
    ConsoleLogger logger;
    BNFSpeedSensor speedSensor;
    IOTCloudCommunicator cloudCommunicator;
    
    SpeedMonitor instance {10, &logger, &speedSensor, &cloudCommunicator};
    
    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
}

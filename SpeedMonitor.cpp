#include <iostream>
#include <random> 
#include <string>
#include "SpeedMonitor.h"
using namespace std;

 void SpeedMonitor::monitor(){
    if(_speedThreshold  < 1 || _speedThreshold > 100) {
        this->_logger->write("_speedThreshold value must be in the ramge {1-100} " + to_string(_speedThreshold));
    }
    
    int currentSpeedInKmph =_speedSensorInstance->getCurrentSpeed();
    this->_logger->write("Current Speed In Kmph " + to_string(currentSpeedInKmph));
    
    if(currentSpeedInKmph > _speedThreshold) {
        double mph = currentSpeedInKmph * 0.621371;
        string message="Current Speed in Miles "+ to_string(mph);
        int statusCode = (*_cloudCommunicatorInstance).pushMessage(message);
        if(statusCode > 400) {
            //Log Message to Console
            this->_logger->write("Error In Communication Unable to Contact Server " + message);
          }
         
    }
              
}


#ifndef IOT_CLOUD_COMMUNICATOR_H
#define IOT_CLOUD_COMMUNICATOR_H

#include "ICloudCommunicator.h"

class IOTCloudCommunicator:public ICloudCommunicator{

public:
    int pushMessage(const string& message);
};

#endif

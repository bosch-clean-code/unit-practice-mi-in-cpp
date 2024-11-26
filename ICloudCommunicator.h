#ifndef ICLOUD_COMMUNICATOR_H
#define ICLOUD_COMMUNICATOR_H

#include <string>

using namespace std;

class ICloudCommunicator{
    public:
      virtual int pushMessage(const string& message) = 0;
};

#endif

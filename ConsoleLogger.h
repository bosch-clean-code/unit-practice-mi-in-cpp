#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include <string>
#include "ILogger.h"
using namespace std;

class ConsoleLogger:public ILogger{
  public:
  void write(const string& msg);
};

#endif

#include <gtest/gtest.h>
#include "SpeedMonitor.h"
uisng namespace testing;

//Fake Dependency , Susbstitution for real time dependency
class SpeedSendorTestDouble:public ISpeedSensor {
public:
  int getCurrentSpeed(){
      return 50;
  }
};
class LoggerTestDouble:public ILogger{
public:
  int writeCallCount=0;
  string writeMsgArg="";

  void write(const string& msg){
      writeCallCount+=1;
     writeMsgArg=msg;
  }
   
};
class CommunicatorTestDouble:public ICloudCommunicatior{
public:
  int pushMessage(const string& message){  return 200;}
};



TEST(SpeeMonitorTestSuite,AssertValidSpeedMonitorInstantiation){
  //Arrange
    LoggerTestDouble loggerStub;
    CommunicatorTestDouble communicatorStub;
    SpeedSendorTestDouble speedSensorStub;
   //ACT
    SpeedMonitor objUnderTest {40,&loggerStub,&speedSensorStub,&communicatorStub } ;
//ASSERT
     //Value Based Testing
    ASSERT_EQ(objUnderTest.getSpeedThreshold(),40);
}

TEST(SpeeMonitorTestSuite,VerifyValidSpeedThresholdState){
  //interaction- Behavior-Commnication  Testing
    LoggerTestDouble loggermock;
    CommunicatorTestDouble communicatorStub;
    SpeedSendorTestDouble speedSensorStub;
    string expectedMessage=""_speedThreshold value must be in the ramge {1-100} 400";
    SpeedMonitor objUnderTest {400,&loggermock,&speedSensorStub,&communicatorStub } ;
    objUnderTest.monitor();
    
    EXPECT_EQ(loggermock.writeCallCount,1);
    EXPECT_STREQ(loggermock.writeMsgArg,expectedMessage);
    

}



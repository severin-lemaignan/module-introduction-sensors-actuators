#include <ros.h>
#include <std_msgs/UInt16.h>
#include <Servo.h> 

using namespace ros;

NodeHandle  nh;
Servo servo;

void cb( const std_msgs::UInt16& msg){
  servo.write(msg.data); // 0-180
}

Subscriber<std_msgs::UInt16> sub("servo", cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);

  servo.attach(9); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}



#include <Servo.h> 
#include <ros.h>
#include <sensor_msgs/JointState.h>

ros::NodeHandle  nh;

Servo servo;

void servo_cb( const sensor_msgs::JointState& msg){
  int angle = (int) (msg.position[0] * 180/3.14);
  servo.write(angle); //set servo angle, should be from 0-180  
}

ros::Subscriber<sensor_msgs::JointState> sub("joint_states", servo_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}

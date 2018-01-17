/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo servo1;
Servo servo2;
Servo servo3;

void servo1_cb( const std_msgs::UInt16& cmd_msg){
  servo1.write(cmd_msg.data); //set servo angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}

void servo2_cb( const std_msgs::UInt16& cmd_msg){
  servo2.write(cmd_msg.data); //set servo angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}

void servo3_cb( const std_msgs::UInt16& cmd_msg){
  servo3.write(cmd_msg.data); //set servo angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<std_msgs::UInt16> sub("servo1", servo1_cb);
ros::Subscriber<std_msgs::UInt16> sub("servo2", servo2_cb);
ros::Subscriber<std_msgs::UInt16> sub("servo3", servo3_cb);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.subscribe(sub3);
  
  servo.attach(9); //attach it to pin 9
  servo.attach(10); //attach it to pin 9
  servo.attach(11); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(20);
}

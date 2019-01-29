//#define USE_USBCON
#define IN1 5
#define ENA 7
#define IN2 4

#define IN4 10
#define ENB 11
#define IN3 9

int kolo1;

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;
  std_msgs::Int16 int_msgs;

void messageCb( const std_msgs::Int16& msg)
{
  kolo1 = msg.data;
//  digitalWrite(7,HIGH-digitalRead(100));
//    digitalWrite(7,HIGH-digitalRead(msg.Data));
}

ros::Subscriber<std_msgs::Int16> sub("/chatter", &messageCb);

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN4, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}
void loop()
{
  nh.spinOnce();
  delay(1);
  digitalWrite(IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(ENA, kolo1);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite(ENA, 0);
  delay(1000);


  digitalWrite(IN4, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(ENB, 255);
  delay(1000);
  digitalWrite(IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite(ENB, 0);
  delay(1000);
}


// W terminalu:
// roscore
// rostopic pub /chatter std_msgs/Int16 "data: 220" 


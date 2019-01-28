//Zadanie 1+2 - wysyłanie wartości liczbowej (pomiary z potencjometru)
#include <ros.h>
#include <std_msgs/Int16.h>
int joypin_X = 0; 
int value1= 0;
ros::NodeHandle nh;
std_msgs::Int16 str_msg;
ros::Publisher data("data", &str_msg);

void setup() {
  nh.initNode();
  nh.advertise(data);

}

void loop() {
  value1 = analogRead(joypin_X);

  str_msg.data = value1;
  data.publish(&str_msg);
  nh.spinOnce();
}

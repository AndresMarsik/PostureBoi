
#include <MPU9250_asukiaaa.h>

MPU9250 imu;
float aSet, aY;
int led = 1;

void setup() {
  pinMode(led, OUTPUT);
  TinyWireM.begin();
  imu.setWire(&TinyWireM);
  imu.beginAccel();
  aSet = 0;

  for(int i=0; i<50;i++){
  imu.accelUpdate();
  aSet += imu.accelY();
  delay(50);
  }

  aSet = aSet/50;
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led,LOW);
  delay(300);
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led,LOW);
}

void loop() {
  imu.accelUpdate();
  aY = imu.accelY();

  if((aY > aSet+0.3)||(aY < aSet-0.3)){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led,LOW);
  }
  
  delay(500);
}


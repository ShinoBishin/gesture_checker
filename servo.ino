#include <Servo.h>

Servo waiservoX;
Servo waiservoY;

void setup() {
    Serial.begin(9600);
    waiservoX.attach(5);
    waiservoY.attach(6);
}

void loop() {
    int i;
    long x, y;
    x = y = 0;     

    for (i = 0; i < 100; i++) {
        x = x + analogRead(0);
        y = y + analogRead(1);
    }

    x = x / 100;
    y = y / 100;

    int rotateX = (x - 448)/1.73;
    if (rotateX < 15) rotateX = 0;
    waiservoX.write(rotateX);
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(" ");
    Serial.print(rotateX);
    
    int rotateY= (y - 445)/1.80;
    if (rotateY < 15) rotateY = 0;
    waiservoY.write(rotateY);
    Serial.print("Y: ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(rotateY);
    delay(10);

}
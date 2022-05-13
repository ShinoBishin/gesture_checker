#include <Servo.h>

int maxX = 0;
int minX = 1000;
int maxY = 0;
int minY = 1000;
int maxZ = 0;
int minZ = 1000;

void setup() {
    Serial.begin(9600);
    Serial.println("Check... Start!");
}

void loop() {
    long x,y,z;
    x = y = z = 0;
    
    x = analogRead(1);
    y = analogRead(2);
    z = analogRead(3);

    if (maxX < x) {
        maxX = x;
    }

    if (minX > x) {
        minX = x;
    }

    if (maxY < y) {
        maxY = y;
    }

    if (minY > y) {
        minY = y;
    }


    if (maxZ < z) {
        maxZ = z;
    }

    if (minZ > z) {
        minZ = z;
    }

    int centerX = (maxX - minX)/2+minX;
    int centerY = (maxY - minY)/2+minY;
    int centerZ = (maxZ - minZ)/2+minZ;

    float rotateX = ((float)maxX - (float)minX)/180;        
    float rotateY = ((float)maxY - (float)minY)/180;        
    float rotateZ = ((float)maxZ - (float)minZ)/180;

    Serial.print("X:");
    Serial.print(minX);
    Serial.print(" ");
    Serial.print(centerX);
    Serial.print(" ");
    Serial.print(maxX);
    Serial.print(" ");
    Serial.print(rotateX);
    
    Serial.print(" Y:");
    Serial.print(minY);
    Serial.print(" ");
    Serial.print(centerY);
    Serial.print(" ");
    Serial.print(maxY);
    Serial.print(" ");
    Serial.print(rotateY);

    Serial.print(" Z:");
    Serial.print(minZ);
    Serial.print(" ");
    Serial.print(centerZ);
    Serial.print(" ");
    Serial.print(maxZ);
    Serial.print(" ");
    Serial.println(rotateZ);
    
    delay(50);
    

}
/* Solar Tracking System
 Automatically adjusts the solar panel to track sunlight.
*/
// Include the servo motor library
#include <Servo.h>
// Define the LDR sensor pins
#define LDR1 A0
#define LDR2 A1
// Define the error margin for alignment
#define ERROR_MARGIN 10
// Starting position of the servo motor (90° - center position)
int servoPosition = 90;
// Create an object for the servo motor
Servo servo;
void setup() {
 // Attach the servo to PWM pin 11
 servo.attach(11);

 // Set the initial position of the servo
 servo.write(servoPosition);
 delay(1000); // Allow the servo to stabilize
}


void loop() {
 // Read the light intensity from the LDR sensors
 int ldr1 = analogRead(LDR1);
 int ldr2 = analogRead(LDR2);
 // Calculate the difference in light intensity
 int difference = abs(ldr1 - ldr2);
 // Check if the difference is within the error margin (dead zone)
 if (difference > ERROR_MARGIN) {
 // Adjust the servo position based on the light intensity
 if (ldr1 > ldr2) {
 servoPosition--;
 } else if (ldr1 < ldr2) {
 servoPosition++;
 }
 // Ensure the servo position stays within its valid range (0 to 180 degrees)
 if (servoPosition > 180) servoPosition = 180;
 if (servoPosition < 0) servoPosition = 0;
 // Move the servo to the new position
 servo.write(servoPosition);
 }
 // Small delay to allow smooth servo movement
 delay(100);
}

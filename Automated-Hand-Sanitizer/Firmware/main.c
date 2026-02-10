#include <Servo.h>
#include <NewPing.h>

Servo dispenserServo;
 float lastDispenseTime = 0;

int TRIG_PIN = 9; //initialized to pin 9 on arduino
int ECHO_PIN = 8; //initialized to pin 8 on arduino
int SERVO_PIN = 6; //initialized to pin 6 on arduino
int MAX_DISTANCE =200;
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // function of newping

int HAND_DISTANCE_CM = 20 ;
int PRESS_ANGLE = 360 ;
int RELEASE_ANGLE = 0 ;
int PRESS_TIME_MS = 400;
int LOCKOUT_TIME_MS =1500 ; 
   // Max distance to measure (cm)

void setup() {
  Serial.begin(9600);

  dispenserServo.attach(SERVO_PIN); // Activates Servo 
  dispenserServo.write(RELEASE_ANGLE);   // Moves the Servo 
  Serial.println("Servo + NewPing ready"); // Prints when code is uploaded 
}

void loop() {

  unsigned int distance = sonar.ping_cm();  // NewPing distance read

  if (distance > 0) {
    Serial.print("Distance:");
    Serial.print(distance);
    Serial.println("cm");
  }

  if (distance > 0 && distance <= HAND_DISTANCE_CM) {
// millis() returns the number of milliseconds the arduino started running
// lastDispenseTime stores the time when sanitizer last dispensed 
// if function to prevent the sanitizer from dispensing repeatedly non-stop

    if (millis() - lastDispenseTime > LOCKOUT_TIME_MS) {
      dispenseSanitizer(); // calling function
      lastDispenseTime = millis();  // record the time so we can enforce cooldown
    }
  }

  delay(100);
}

// -------- Servo Action Function --------
void dispenseSanitizer() {
  Serial.println("Dispensing sanitizer");

// moves servo
  dispenserServo.write(PRESS_ANGLE);
  // delay
  delay(PRESS_TIME_MS);
  // returns to its original position
  dispenserServo.write(RELEASE_ANGLE);
}

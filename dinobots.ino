/*
  Basic dinobot drive sketch.

  Modified from the RC PulseIn Serial Read Out sketch by Nick Poole.
  https://www.sparkfun.com/tutorials/348
  License: CC-BY SA 3.0.

  Hardware:
  - Three channel radio receiver:
  - Channel 1 input connected to pin 3 (TODO: confirm this)
  - Channel 2 input connected to pin 2 (TODO: confirm this)
  - Some form 2 channel motor driver:
  - Motor 1 connected to pin 4.
  - Motor 2 connected to pin 5.
  - Motor 3 connected to pin 6.
  - Motor 4 connected to pin 7.

*/

int steerRead; // Reading from the steer channel.
int driveRead; // Reading from the drive channel.

// Pin assignments:
const int steerPin = 2; // Read input from the steer channel
const int drivePin = 3; // Read input from the drive channel
const int motor1Pin = 4; // Drive the motor 1 pin of the motor controller
const int motor2Pin = 5; // Drive the motor 2 pin of the motor controller
const int motor3Pin = 6; // Drive the motor 3 pin of the motor controller
const int motor5Pin = 7; // Drive the motor 4 pin of the motor controller

void setup() {

  pinMode(steerPin, INPUT); // Set our input pins as such
  pinMode(drivePin, INPUT);

  //and our output pins for movement
  pinMode(motor1Pin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {
  steerRead = pulseIn(3, HIGH, 20000); // Read the pulse width of 
  driveRead = pulseIn(2, HIGH, 29000); // each channel
  Serial.print("steerRead ");
  Serial.print(steerRead);
  Serial.print(" driveRead ");
  Serial.print(driveRead);
  Serial.print("         ");
  Serial.println(middleware());
  Drive(middleware());

  //delay(1000); // I put this here just to make the terminal 
  // window happier

  //ok, the two channel tranmitter sits at
  // ch 1: 1500
  // ch 2: 1024 when the tx is off
  //when on range is
  // ch 1: 2000 - 1520 - 960 (steering 2044 right)
  // ch 2: 2015 - 1520 - 1069 (throttle 1000 full forward)

  //there are some combinations we need to code for
  //turning, turning and moving, moving.
  //and then we need direction for all three

  
}

void Drive(int motorstate){
  //this guy takes the desired outbcome (determined by middleware) and
  //sets the pins corerctly on the h bridge module
  //the h bridge module has the following parameters
  //four inputs and 2 pwm (enables). we arn't doing pwm just yet
  //motorstate tells us what to do

  //we can use a switch statement for this
  switch (motorstate) {
  case 0:
    //no movement
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    break;
  case 1:
    //rotate left
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    break;
  case 2:
    //rotate right
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    break;
  case 3:
    //backward
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    break;
  case 4:
    //forward
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    break;
  }
}

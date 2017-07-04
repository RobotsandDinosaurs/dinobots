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
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      break;
    case 1:
      //rotate left
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
    case 2:
      //rotate right
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    case 3:
          //backward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    case 4:
          //forward
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
  }
  
}

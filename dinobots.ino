     
/*
 RC PulseIn Serial Read out
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */
 
int ch1; // Here's where we'll keep our channel values
int ch2;

//and our output pin numbers
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;

void setup() {

  pinMode(2, INPUT); // Set our input pins as such
  pinMode(3, INPUT);

//and our output pins for movement
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {

  ch1 = pulseIn(3, HIGH, 20000); // Read the pulse width of 
  ch2 = pulseIn(2, HIGH, 29000); // each channel
  Serial.print("ch1 ");        // each channel
  Serial.print(ch1);        // each channel
  Serial.print(" ch2 ");        // each channel
  Serial.print(ch2);        // each channel
  Serial.print("         ");        // each channel
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

// this routine, takes the values from the RC reciver (which is listneing to the remote control transmitter) 
//and determines
// which action should be taken by the drive mechanism.
// there are 5 options
//0 = no movement (no one is doing anything)
//1 = rotating on the spot left
//2 = rotating on the spot right
//3 = moving backward
//4 = moving forward
//as you can see there is no propotional control and if you turn whilst moving forward
//all forward movemnt stops and it will rotate on the spot

int middleware(){
  
  //we can tweak that and play with proportiona control in a later verison

  //ok lets setup our variables
  int myaction = 0; //this is the result we pass to drive mechanism

  //we already have channel 1 and 2 values from the RC control 

  //lets see if thye are trying to turn?
  // The Arduino occasionally reads a 0 for the steer
  // channel, so discard that.
  // TODO: If we get a 0 read, that results in briefly
  // taking no action. Better to remember previous
  // state and keep doing that.
  if (steerRead > 100) {
    if (steerRead < leftThreshold) {
      myaction = 1; //they are turning left
      return myaction; //stop doing anything else as we don't care if thye are moving forward or backward
    }
    if (steerRead > rightThreshold) {
      myaction = 2; //they are turning right
      return myaction; //stop doing anything else as we don't care if thye are moving forward or backward
    }
  }

  //ok so we aren't turning if we got this far, are we going forward or backward?
  // A 0 read on this channel typically means the transmitter isn't on.
  // So ignore it.
  if (driveRead > 100) {
    if (driveRead < forwardThreshold) {
      myaction = 4; //they are going forward
      return myaction; //stop doing anything else as they cna't be going forward AND backward at the same time
    }
    if (driveRead > backwardThreshold) {
      myaction = 3; //they are going backward
      return myaction; //stop
    }
  }
  //if we got this far then something went wrong or we have no input. in all cases we should not be moving
  return myaction;
}

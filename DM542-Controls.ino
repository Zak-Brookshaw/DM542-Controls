

int stepPin = 6;
int dirPin = 5;
int setPoint=0;
int rdValue = 100;
int relError = 1;
int error;


void setup() {

  Serial.begin(9600);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  digitalWrite(dirPin, LOW);
  
}

void loop() {
  // get the measured value
  error = setPoint - rdValue;


  
  if (error >= relError){
    setDirHigh();
    mkStep();
    rdValue+=-1;
  }
  else if (error <= -1*relError){
    setDirLow();
    mkStep();
    rdValue+=-1;
  }
  
  
  Serial.println(error);
}


void setDirHigh(){

    digitalWrite(dirPin, HIGH);

}

void setDirLow(){

    digitalWrite(dirPin, LOW);

}

void mkStep(){
  
  delay(2);
  digitalWrite(stepPin, HIGH);
  
  delay(2);
  digitalWrite(stepPin, LOW);
  
}

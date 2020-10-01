int motorControllA = 4;
int motorControllB = 3;

int motorControllC = 6;
int motorControllD = 5;

int motorControllE = 10;
int motorControllF = 9;

int motorControllG = 13;
int motorControllH = 12;

// led for headlights
int led = 7;

int motorSpeed1 = 2;
int motorSpeed2 = 7;
int motorSpeed3 = 8;
int motorSpeed4 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(">> START<<");  
  
  pinMode(motorControllA, OUTPUT);
  pinMode(motorControllB, OUTPUT);
  pinMode(motorControllC, OUTPUT);
  pinMode(motorControllD, OUTPUT);
  pinMode(motorControllE, OUTPUT);
  pinMode(motorControllF, OUTPUT);
  pinMode(motorControllG, OUTPUT);
  pinMode(motorControllH, OUTPUT);
}

void loop() {
  if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());

    switch (data)
    {
      
//       create a custom button for led and set the value as 5
        
      case '5': //led on
          digitalWrite(led, HIGH);
        
      case '1': //FORWARD
          digitalWrite(motorControllA, HIGH);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, HIGH);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, HIGH);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 255);

          digitalWrite(motorControllG, HIGH);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 255);
        break;
        
      case '2': //REVERSE
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, HIGH);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, HIGH);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, HIGH);
          analogWrite(motorSpeed3, 255);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, HIGH);
          analogWrite(motorSpeed4, 255);
        break;
        
      case '3': //FORWARD LEFT
          digitalWrite(motorControllA, HIGH);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, HIGH);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, HIGH);
          analogWrite(motorSpeed3, 225);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, HIGH);
          analogWrite(motorSpeed4, 225);
        break;
        
      case '4': //FORWARD RIGHT
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, HIGH);
          analogWrite(motorSpeed1, 225);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, HIGH);
          analogWrite(motorSpeed2, 225);

          digitalWrite(motorControllE, HIGH);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 225);

          digitalWrite(motorControllG, HIGH);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 225);
        break;
               
      default: //If bluetooth module receives any value not listed above, both motors turn off
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 0);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 0);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 0);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 0);
    }
  }
}

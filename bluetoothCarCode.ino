// Motor A (Right) connections
#define ENA 9       // Enable/speed motor Right wheels
#define IN_1  8    // Right wheels
#define IN_2  7    // Right wheels

// Motor B (Left) connections
#define ENB 3       // Enable/speed motor Left Right
#define IN_3  5    		// Left wheels
#define IN_4  4    		// Left wheels

int command; 			      //Int to store app command state.
int speedCar = 255; 		// 50 - 255.

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);

  Serial.begin(9600);

}

void goAhead() {

  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}

void goBack() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);


  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void goRight() {

  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);


  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void goLeft() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);

}

void stopRobot() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);


  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void loop() {

  if (Serial.available() > 0) {
    command = Serial.read();
    stopRobot(); 			//Initialize with motors stopped.

    switch (command) {
      case 'F': goAhead(); break;
      case 'B': goBack(); break;
      case 'L': goLeft(); break;
      case 'R': goRight(); break;
      case '0': speedCar = 100; break;
      case '1': speedCar = 115; break;
      case '2': speedCar = 130; break;
      case '3': speedCar = 145; break;
      case '4': speedCar = 160; break;
      case '5': speedCar = 175; break;
      case '6': speedCar = 190; break;
      case '7': speedCar = 205; break;
      case '8': speedCar = 220; break;
      case '9': speedCar = 235; break;
      case 'q': speedCar = 255; break;

    }
  }
}

const int VRy = A0;           // select the input pin for the potentiometer
const int buzzerPin = 9;      // select the pin for the buzzer
const int pause = 100;        // change length of pause; dot = 1 pause and dash = 3 dots

const int mid = 1024 / 2;     // when joystick is in the middle in the ideal world
const int err = 10;           // used for determining threshold

int yPosition = 0;
int beep = 0;

void setup() {
  pinMode(VRy, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  while(1){
    yPosition = analogRead(VRy);
    
    if(yPosition > mid + err) {
      beep = pause * 3;
    } else if (yPosition < mid - err) {
      beep = pause;
    } else {
      break;
    }
  
    digitalWrite(buzzerPin, HIGH);
    delay(beep);
    digitalWrite(buzzerPin, LOW);
    delay(pause);
  }
}
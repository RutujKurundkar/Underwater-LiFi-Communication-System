#define RECEIVERPIN A0  
#define THRESHOLD 500   

void setup() {
  Serial.begin(9600);
}

void loop() {
  char receivedChar = 0;
  int val = analogRead(RECEIVERPIN);

  while (val < THRESHOLD) {
    val = analogRead(RECEIVERPIN);
  }

  delay(10); 

  for (int i = 0; i < 8; i++) {
    val = analogRead(RECEIVERPIN);
    receivedChar = receivedChar << 1;
    if (val > THRESHOLD) {
      receivedChar |= 1;
    }
    delay(10);
  }

  Serial.print(receivedChar);
  delay(100); 
}

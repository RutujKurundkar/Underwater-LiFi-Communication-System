#define LASERPIN 7  

void setup() {
  pinMode(LASERPIN, OUTPUT);
}

void loop() {
  char myText[] = "GANGAPRASAD";
  int length = strlen(myText);
  int m;
  int bits[8];

  for (int n = 0; n < length; n++) {
    m = int(myText);
    int bin[8];

    for (int z = 0; z < 8; z++) {
      bin[7 - z] = m % 2;
      m = m / 2;
    }

    for (int p = 0; p < 8; p++) {
      bits[p] = bin[p] == 1 ? HIGH : LOW;
    }

    bits[0] = HIGH; // Sync bit

    for (int i = 0; i < 8; i++) {
      digitalWrite(LASERPIN, bits[i]);
      delay(10); 
    }

    digitalWrite(LASERPIN, LOW);
    delay(100);
  }
}

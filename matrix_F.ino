
int rows[8] = {9, 4, A0, 6, 10, A1, 11, A3};
int cols[8] = {5, 12, 13, 8, A2, 7, 3, 2};

byte letterF[8] = {
  B11111111,
  B10000000,
  B10000000,
  B11111100,
  B10000000,
  B10000000,
  B10000000,
  B00000000
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
}

void loop() {
  for (int r = 0; r < 8; r++) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(rows[i], LOW);
      digitalWrite(cols[i], HIGH);
    }

    digitalWrite(rows[r], HIGH);

    for (int c = 0; c < 8; c++) {
      if (bitRead(letterF[r], 7 - c)) {
        digitalWrite(cols[c], LOW);
      }
    }

    delay(2);
  }
}

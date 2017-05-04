
void setup() {
  Serial.begin(9600);
   analogWriteFrequency(9, 30000); // Teensy 3.0 pin 3 also changes to 375 kHz
  // put your setup code here, to run once:
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  pinMode(A9, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned int out = 0x00;
  for(int i = 1; i < 9; i++) {
    out |= ((digitalRead(i) << (8-i)));
    //Serial.print(i);
    //Serial.print(":");
    //Serial.print(digitalRead(i));
    //Serial.print("\n");
  }

  char pwm_char = (char) out;
  Serial.println(out);
  analogWrite(A9, out);
  //Serial.print(pwm_char);
  //Serial.print("\n");

  delay(20);

}

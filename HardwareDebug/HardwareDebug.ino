
int sw1 = 5;
int sw2 = 4;
int sw3 = 3;
int sw4 = 2;
int togLd = 7;
int togLu = 6;
int togRd = 8;   
int togRu = 9; // assign pins
int potL = 19;
int potR = 14;



void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(togRd, INPUT_PULLUP);
  pinMode(togRu, INPUT_PULLUP);
  pinMode(togLd, INPUT_PULLUP);
  pinMode(togLu, INPUT_PULLUP);
  pinMode(potR, INPUT_PULLUP);
  pinMode(potL, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)



  Serial.begin(9600);
}

void loop() {
  int read1 = digitalRead(sw1);
  int read2 = digitalRead(sw2);
  int read3 = digitalRead(sw3);
  int read4 = digitalRead(sw4);
  int read5 = digitalRead(togLd);
  int read6 = digitalRead(togLu);
  int read7 = digitalRead(togRd);
  int read8 = digitalRead(togRu);
  int read9 = analogRead(potR);
  int read10 = analogRead(potL);

  Serial.print(read1);
  Serial.print("\t");
  
  Serial.print(read2);
  Serial.print("\t");
  
  Serial.print(read3);
  Serial.print("\t");
  
  Serial.print(read4);
  Serial.print("\t");
  
  Serial.print(read5);
  Serial.print("\t");
  
  Serial.print(read6);
  Serial.print("\t");
  
  Serial.print(read7);
  Serial.print("\t");
  
  Serial.print(read8);
  Serial.print("\t");
  
  Serial.print(read9);
  Serial.print("\t");
  
  Serial.print(read10);
  Serial.print("\t");
  
  Serial.println();

  delay(200);
  

}

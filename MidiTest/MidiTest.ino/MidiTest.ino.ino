#define LED 13    // LED pin on Arduino board
#define switch1 5              // 1st Switch
#define switch2 4               // 2nd Switch
#define switch3 3               // 2nd Switch
#define switch4 2               // 2nd Switch
#define togLd 7
#define togLu 6
#define MIDI_COMMAND_CONTROL_CHANGE 0xB0
#define MIDI_COMMAND_NOTE_ON 0x90
#define MIDI_COMMAND_NOTE_OFF 0x80

//Variables
int switch1LastState = 0;
int switch1CurrentState = 0;
int switch2LastState = 0;
int switch2CurrentState = 0;
int switch3LastState = 0;
int switch3CurrentState = 0;
int switch4LastState = 0;
int switch4CurrentState = 0;
int togLdState = 0;
int togLuState = 0;
int togLState = 0;

// the format of the message to send Via serial 
typedef union {
    struct {
 uint8_t command;
 uint8_t channel;
 uint8_t data1;
 uint8_t data2;
    } msg;
    uint8_t raw[4];
} t_midiMsg;

int readTogL() {
  togLdState = digitalRead(togLd);
  togLuState = digitalRead(togLu);
  
  if (togLdState == 0) {
    return -1;
  }else if (togLuState == 0) {
    return 1;
  }else {
    return 0;
  }
}

void blinkLed(byte num) {  // Basic blink function
  for (byte i=0;i<num;i++) {
    digitalWrite(LED,HIGH);
    delay(50);
    digitalWrite(LED,LOW);
    delay(50);
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(togLd, INPUT_PULLUP);
  pinMode(togLu, INPUT_PULLUP);

  Serial.begin(115200);
  
  blinkLed(5);
}

void loop() {
  
  t_midiMsg midiMsg1;  // MIDI message for Switch 1
  t_midiMsg midiMsg2;  //MIDI message for Swtich 2
  t_midiMsg midiMsg3;  //MIDI message for Swtich 3
  t_midiMsg midiMsg4;  //MIDI message for Swtich 4
  switch1CurrentState = digitalRead(switch1);
  switch2CurrentState = digitalRead(switch2);
  switch3CurrentState = digitalRead(switch3);
  switch4CurrentState = digitalRead(switch4);
  togLState = readTogL();
  Serial.println(togLState);

// switch1 ///////////////////////////////////////////
  if (switch1CurrentState == 0){
      if(switch1LastState == 1){
          midiMsg1.msg.command = MIDI_COMMAND_NOTE_ON;
          midiMsg1.msg.channel = 1;
          midiMsg1.msg.data1   = 1;
          midiMsg1.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg1.raw, sizeof(midiMsg1));                         
          blinkLed(2);           
        }
  }
  if (switch1CurrentState == 1){
      if(switch1LastState == 0){
          midiMsg1.msg.command = MIDI_COMMAND_NOTE_OFF;
          midiMsg1.msg.channel = 1;
          midiMsg1.msg.data1   = 1;
          midiMsg1.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg1.raw, sizeof(midiMsg1));                    
          blinkLed(2);           
       }
   }
switch1LastState = switch1CurrentState;
/////////////////////////////////////////////////////////
// switch2 ///////////////////////////////////////////
  if (switch2CurrentState == 0){
      if(switch2LastState == 1){
          midiMsg2.msg.command = MIDI_COMMAND_NOTE_ON;
          midiMsg2.msg.channel = 2;
          midiMsg2.msg.data1   = 2;
          midiMsg2.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg2.raw, sizeof(midiMsg2));                         
          blinkLed(2);           
        }
  }
  if (switch2CurrentState == 1){
      if(switch2LastState == 0){
          midiMsg2.msg.command = MIDI_COMMAND_NOTE_OFF;
          midiMsg2.msg.channel = 2;
          midiMsg2.msg.data1   = 2;
          midiMsg2.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg2.raw, sizeof(midiMsg2));                    
          blinkLed(2);           
       }
   }
switch2LastState = switch2CurrentState;
/////////////////////////////////////////////////////////
// switch3 ///////////////////////////////////////////
  if (switch3CurrentState == 0){
      if(switch3LastState == 1){
          midiMsg3.msg.command = MIDI_COMMAND_NOTE_ON;
          midiMsg3.msg.channel = 3;
          midiMsg3.msg.data1   = 3;
          midiMsg3.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg3.raw, sizeof(midiMsg3));                         
          blinkLed(2);           
        }
  }
  if (switch3CurrentState == 1){
      if(switch3LastState == 0){
          midiMsg3.msg.command = MIDI_COMMAND_NOTE_OFF;
          midiMsg3.msg.channel = 3;
          midiMsg3.msg.data1   = 3;
          midiMsg3.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg3.raw, sizeof(midiMsg3));                    
          blinkLed(2);           
       }
   }
switch3LastState = switch3CurrentState;
/////////////////////////////////////////////////////////
// switch4 ///////////////////////////////////////////
  if (switch4CurrentState == 0){
      if(switch4LastState == 1){
          midiMsg4.msg.command = MIDI_COMMAND_NOTE_ON;
          midiMsg4.msg.channel = 4;
          midiMsg4.msg.data1   = 4;
          midiMsg4.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg4.raw, sizeof(midiMsg4));                         
          blinkLed(2);           
        }
  }
  if (switch4CurrentState == 1){
      if(switch4LastState == 0){
          midiMsg4.msg.command = MIDI_COMMAND_NOTE_OFF;
          midiMsg4.msg.channel = 4;
          midiMsg4.msg.data1   = 4;
          midiMsg4.msg.data2   = 0; /* Velocity */
          /* Send note on */
          Serial.write(midiMsg4.raw, sizeof(midiMsg4));                    
          blinkLed(2);           
       }
   }
switch4LastState = switch4CurrentState;
/////////////////////////////////////////////////////////
}

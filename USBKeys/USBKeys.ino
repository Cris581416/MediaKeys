#define PLAY_PAUSE_BUTTON 5
#define NEXT_BUTTON 4
#define LAST_BUTTON 2
#define VOL_UP_BUTTON 10
#define VOL_DOWN_BUTTON 12

char command;
bool newData;

bool lastPPress = false;
bool lastNPress = false;
bool lastLPress = false;
bool lastUPress = false;
bool lastDPress = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(PLAY_PAUSE_BUTTON, INPUT);
  pinMode(NEXT_BUTTON, INPUT);
  pinMode(LAST_BUTTON, INPUT);
  pinMode(VOL_UP_BUTTON, INPUT);
  pinMode(VOL_DOWN_BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkButtons();
  sendCommand();
}

void checkButtons(){
  if(digitalRead(PLAY_PAUSE_BUTTON) == HIGH){

    if(lastPPress == false){
      command = 'p';
      newData = true;
    } else{
      newData = false;
    }
    resetButtons();
    lastPPress = true;

  } else if(digitalRead(NEXT_BUTTON) == HIGH){

    if(lastNPress == false){
      command = 'n';
      newData = true;
    } else{
      newData = false;
    }
    resetButtons();
    lastNPress = true;

  } else if(digitalRead(LAST_BUTTON) == HIGH){

    if(lastLPress == false){
      command = 'l';
      newData = true;
    } else{
      newData = false;
    }
    resetButtons();
    lastLPress = true;

  } else if(digitalRead(VOL_UP_BUTTON) == HIGH){

    if(lastUPress == false){
      command = 'u';
      newData = true;
    } else{
      newData = false;
    }
    resetButtons();
    lastUPress = true;


  } else if(digitalRead(VOL_DOWN_BUTTON) == HIGH){

    if(lastDPress == false){
      command = 'd';
      newData = true;
    } else{
      newData = false;
    }
    resetButtons();
    lastDPress = true;

  } else{
    resetButtons();
    newData = false;
  }
}

void sendCommand(){
  if(newData == true){
    Serial.write(command);
    newData == false;
  }
}

void resetButtons(){
  lastPPress = false;
  lastNPress = false;
  lastLPress = false;
  lastUPress = false;
  lastDPress = false;
}

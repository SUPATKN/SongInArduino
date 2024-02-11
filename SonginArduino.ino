#define LED 21
#define button 23

hw_timer_t *My_timer = NULL;
int note[] = {319,379,477,436};
int TimeDelay = 200;
int c;
int x = 5;
int mode =5;

void IRAM_ATTR onTimer()
{
  // Toggle The LED
  digitalWrite(LED, !digitalRead(LED));
  
}
void IRAM_ATTR MODE()
{

  mode = mode-1;
  if(mode == 0){
    mode = 5;
  }
  TimeDelay = 100*mode;
  x = mode;

}
void setup() {

  pinMode(LED,OUTPUT);
  My_timer = timerBegin(0, 80, true);  // use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR
    // set alarm every 1 sec
  timerAlarmEnable(My_timer);
  attachInterrupt(button, MODE, FALLING);
}
void G (){
  c = note[0]*x;
  timerAlarmWrite(My_timer, note[0], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}

void E(){
  c = note[1]*x;
  timerAlarmWrite(My_timer, note[1], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}
void C(){
  c = note[2]*x;
  timerAlarmWrite(My_timer, note[2], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}
void D(){
  c = note[3]*x;
  timerAlarmWrite(My_timer, note[3], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}


void loop() {
  G();
  delay(TimeDelay*2);
  G();
  delay(TimeDelay*2);
  G();
  delay(TimeDelay*2);
  G();
  delay(TimeDelay*2);
  G();
  delay(TimeDelay);
  E();
  delay(TimeDelay);
  D();
  delay(TimeDelay);
  E();
  delay(TimeDelay);
  G();
  delay(TimeDelay);
  C();
}
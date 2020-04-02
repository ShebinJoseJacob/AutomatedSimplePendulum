/*============================
Developer       : Shebin Jose Jacob
Initial Release : 17 April 2019
License         : MIT
=============================*/

unsigned long pretime;
unsigned long currtime;
int pin = 2;
float timePeriod;
boolean flag = true;
float g,g1=0,t;
int i=0;
void setup(){
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pretime = micros();
  Serial.println("calibrating");
}
void loop(){
  if (digitalRead(pin) == 0)
  {
    if (flag == true)
    {
    currtime = micros();
    timePeriod = currtime-pretime;
    pretime = currtime;
    flag = !flag;
    t=timePeriod/1000000;
    g=(1.36/(t*t)); // In our case (4π²l=1.36), change it for yours
    g1=(g1+g)/2.0;
    if (i%2==0){
      if (g<12 && g>7){
      Serial.println(g);
      g1,g=0;
      }
    }
      i+=1;
    }
    else{
      flag = !flag;
      delay(100);
    }
  }
 
 /*Uncomment, upload and open serial plotter to see damping curve
  for (i=0;i<360;i++)
  { 
    Serial.println(10*t*sin(DEG_TO_RAD*i));
  }
}
*/



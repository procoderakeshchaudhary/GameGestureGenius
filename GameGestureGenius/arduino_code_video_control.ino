// arduino code for video controller



const int trigger1 = 10; //Trigger pin of 1st Sensor
const int echo1 = 9; //Echo pin of 1st Sensor
const int trigger2 = 12; //Trigger pin of 2nd Sensor
const int echo2 =11;//Echo pin of 2nd Sensor
long time_taken;
int dist,distance_L,distance_R;
int flag=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
}
void calculate_distance(int trigger, int echo)
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  time_taken = pulseIn(echo, HIGH);
  dist= time_taken*0.034/2;
  if (dist>50)
    dist = 50;
}
void loop() 
{ //infinite loopy
    calculate_distance(trigger1,echo1);
    distance_L =dist; 
    calculate_distance(trigger2,echo2);
    distance_R =dist; 
    Serial.print("L=");
    Serial.println(distance_L);
    Serial.print("R=");
    Serial.println(distance_R);
    if ((distance_L<50 && distance_R<50))
    { 
      
        Serial.println("Pause"); 
        delay(1000);
      //Serial.println(flag);
    }
    else if(distance_L==50 && distance_R<50)
    {
      Serial.println("right");
      delay(100);
    }
    else if(distance_L<50 && distance_R==50)
    {
      Serial.println("left");
      delay(100);
    }
    Serial.println("**");
    delay(200);
   
}
int led = 13;
const int morseLen = 6;

int timeMorseShort = 200;
int timeMorseLong = timeMorseShort * 3;
int timeMorseSpace = timeMorseShort;
int timeMorseSpaceLetter = timeMorseShort * 3;
int timeMorseSpaceWord = timeMorseShort * 7;

int a;
int b;

int morse[26][morseLen] = {
{2,0,1,0,0,0}, //a 97
{4,1,0,1,0,0}, //c 99
{4,1,0,0,0,0}, //b 98
{3,1,0,0,0,0}, //d 100
{1,0,0,0,0,0}, //e 101
{4,0,0,1,0,0}, //f 102
{3,1,1,0,0,0}, //g
{4,0,0,0,0,0}, //h
{2,0,0,0,0,0}, //i
{4,0,1,1,1,0}, //j
{3,1,0,1,0,0}, //k
{4,0,1,0,0,0}, //l
{2,1,1,0,0,0}, //m
{2,1,0,1,0,0}, //n
{3,1,1,1,0,0}, //o
{4,0,1,1,0,0}, //p
{4,1,1,0,1,0}, //q
{3,0,1,0,0,0}, //r
{3,0,0,0,0,0}, //s
{1,1,0,0,0,0}, //t
{3,0,0,1,0,0}, //u
{3,0,0,0,1,0}, //v
{3,0,1,1,0,0}, //w
{4,1,0,0,1,0}, //x
{4,1,0,1,1,0}, //y
{4,1,1,0,0,0}, //z
};

void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
};


void beepShort()
{
  digitalWrite(led,HIGH);
  delay(timeMorseShort);
  digitalWrite(led,LOW);
  delay(timeMorseSpace);
}

void beepLong()
{
  digitalWrite(led,HIGH);
  delay(timeMorseLong);
  digitalWrite(led,LOW);
  delay(timeMorseSpace);
}

void loop()
{
  a=Serial.read()-97;
  
  if(a>=-97 && a<29)
  {
    for(int i=1; i < (morse[a][0]) + 1; i++)
    {
      if(morse[a][i]==1)
      {
        beepLong();
        Serial.print(morse[a][i]);
      }   
      else if (morse[a][i]==0)
      {
        beepShort();
        Serial.print(morse[a][i]);
      }
    }
    
    if(a==-65)
    {
          delay(timeMorseSpaceWord);
          //Serial.println();
    }
    delay(timeMorseSpaceLetter);
    Serial.println();
  }
};





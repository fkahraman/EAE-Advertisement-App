/*  Author Fatih Kahraman
 *  Date  30.09.2019
 */

#define Buton 3
#define Led 10
#define ONE_SECOND 15624
#define SHORT_MODE 2
#define LONG_MODE 4

int CURRENT_MODE = 2;
int SECOND_COUNTER = 0;
bool INT_FLAG = false;

void exe(int value)
{
  for(int i = 0; i < value; i++)
  {
    digitalWrite(Led, HIGH);
    delay(1000);
    digitalWrite(Led, LOW);
    delay(1000);
  }
  
  for(int i = 0; i < value; i++)
  {
    digitalWrite(Led, HIGH);
    delay(2000);
    digitalWrite(Led, LOW);
    delay(2000);
  }
}

void Timer_init(void)
{ 
  INT_FLAG = true;  
  noInterrupts();           
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = ONE_SECOND;            
  TCCR1B |= (1 << CS12);    
  TIMSK1 |= (1 << TOIE1);   
  interrupts();             
}


ISR(TIMER1_OVF_vect)        
{  
  if (digitalRead(Buton))
  {
    SECOND_COUNTER += 1;
    TCNT1 = ONE_SECOND;            
  }
  
  else
  {
    TCNT1 = 0;
  }

} 

void setup() 
{
  pinMode(Buton, INPUT);
  pinMode(Led, OUTPUT); 

  attachInterrupt(1, Timer_init, RISING);
}

void loop() 
{
  exe(CURRENT_MODE);

  if(INT_FLAG == true)
  {
    if (digitalRead(Buton) == 0)
    {
      if(SECOND_COUNTER >= 3)
      {
        CURRENT_MODE = LONG_MODE;
      }      
      
      else
      {
        CURRENT_MODE = SHORT_MODE;
      }   
    }
  
    SECOND_COUNTER = 0;
    INT_FLAG = false;
     
  }
  
}

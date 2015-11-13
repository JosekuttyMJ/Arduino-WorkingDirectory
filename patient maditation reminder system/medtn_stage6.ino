//PATIENT MEDITATION REMINDER SYSTEM//
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>
char med[45][40]= { "Ether S","Halothane","Sevoflurane ","Propofol","Bupivacaine Hydrochloride","Lignocaine Hydrochloride","Glucose","Adrenaline","EMLA cream","Atropine Sulphate","Diazepam","Midazolam","Morphine Sulphate" ,"Promethazine","Acetyl","Salicylic Acid","Diclofen","Ibuprofen","Paracetamol","Morpine","Tramadol","Fentany","Allopurinol","Colchicin","Azathioprine ","Methotrexate","Sulfasalazine","phosphatev","Leflunomide","Bitartrate","Chlorpheniramine","Dexchlorphenira","Dexamethasone","Ampicillin","Benzylpenicillin","Cefotaxime","Injection"};
  int i=0,rem=0,j=9,k=0;
  char hor[20],mint[20];
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'#','0','*'},
  {'9','8','7'},
  {'6','5','4'},
  {'3','2','1'}
 };
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal lcd(A1, A0, 13, 12, 11, 10);
void setup()
{
 
  lcd.begin(16, 2);
  // Print a message to the LCD.
setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
    lcd.print("RTC failure");
 
 menu();
}
//################################################################################################################################################
void menu()
{
  lcd.clear();
   lcd.print("MEDITN REMINDER");
  delay(1000);
  lcd.clear();
  lcd.print("1)Set time2)Set");
  lcd.setCursor(0, 1);
  lcd.print("remind3)Home4alrms");
  char num = keypad.getKey();
char key = keypad.waitForKey();
lcd.clear();
   lcd.print(key);
   delay(1000);
switch (key)
{
 

   case '1':
   settime();
   break;
   case '2': 
   remndr();
   break;
      case '3': 
  // reset();
  disptime();
   break;
   case '4': 
  rems();
//alarm();
   break;

case NO_KEY:
   break;
   loop();
 }}
//##############################################################################################################################
void loop()
 {
  
  if (timeStatus() == timeSet) {
  disptime();
  char num = keypad.getKey();
  if (num=='*')
  {
    menu();
  }
  
  }
  }
  //#######################################################################################################################3
  void settime()
  {
    int hr=0,min=0,sec=0,day=0,month=0,yr=0;
    lcd.clear();
    lcd.print("Enter Hour:");
     lcd.setCursor(0, 1);
     lcd.print("# key after enter");
     delay(1000);
     lcd.clear();
     for(int i=0;i<3;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
    hr=hr*10+(key-48);
     lcd.clear();
  lcd.print(hr);
  
  
     }
     
   lcd.print("Enter Min:");
     lcd.setCursor(0, 1);
     lcd.print("# key after enter");
     delay(1000);
     lcd.clear();
     for(int i=0;i<3;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
    min=min*10+(key-48);
    lcd.clear();
     lcd.print(min);
    
     }
     lcd.print("Enter Sec:");
     lcd.setCursor(0, 1);
     lcd.print("# key after enter");
     delay(1000);
     lcd.clear();
     for(int i=0;i<3;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
    sec=sec*10+(key-48);
     lcd.clear();
  lcd.print(sec);
  }
       lcd.print("Enter Day:");
     lcd.setCursor(0, 1);
     lcd.print("# key after enter");
     delay(1000);
     lcd.clear();
     for(int i=0;i<3;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
    day=day*10+(key-48);
     lcd.clear();
  lcd.print(day);
  }
         lcd.print("Enter Month:");
     lcd.setCursor(0, 1);
     lcd.print("# key after enter");
     delay(1000);
     lcd.clear();
     for(int i=0;i<3;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
    month=month*10+(key-48);
     lcd.clear();
  lcd.print(month);
  }
         lcd.print("Enter Year:");
     lcd.setCursor(0, 1);
     lcd.print("# key after enter");
     delay(1000);
     lcd.clear();
     for(int i=0;i<4;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
    yr=yr*10+(key-48);
     lcd.clear();
  lcd.print(yr);
  }
   setTime(hr,min,sec,day,month,yr);
  }
  //############################################################################################################################################################
  
  //#####################################################################################################################################
  void alarm()
  {
   //f(k==j)
   //
    //return;
 //
    
    k=j;
    int led = 13;                
  pinMode(9, OUTPUT);  
  while(1)
  {
    lcd.clear();
       lcd.print("TAB NaME");
     lcd.setCursor(0, 1);
     lcd.print("# to skip"); 
     char num = keypad.getKey();
     if(num=='#')
    {break;
    } 
  digitalWrite(9, HIGH);   
  delay(100);              
  digitalWrite(9, LOW);    
  delay(100);              
}
disptime();
  }
  //##############################################################################
  void remndr()
  {
    int t=0;
    int hr=0;
  lcd.clear();
  lcd.print("*REMINDERS*");
  delay(1000); 
  lcd.clear();
   lcd.print("Enter num of");
    lcd.setCursor(0, 1);
    lcd.print("Reminds per day");
   delay(1000); 
    for(int i=0;i<4;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
   hr=hr*10+(key-48);
    lcd.clear();
  lcd.print(hr);
  delay(1000);
 rem=hr; 
  }
   //##########################
  for(int i=0;i<hr;i++)
  {
    int h=0,t=0;
     lcd.clear();
   lcd.print("Enter hour # min #:"); 
  for(int j=0;j<2;j++)
      {
      char key = keypad.waitForKey(); 
     if(key=='#')
    {break;
    }
    h=h*10+(key-48);
      }
    hor[i]=h;
      for(int k=0;k<2;k++)
      {
      char mi = keypad.waitForKey(); 
     if(mi=='#')
    {break;
    }
   t=t*10+(mi-48);
      }
      mint[i]= t;
      lcd.print(":::::::::::::::");
  lcd.clear();
  lcd.print(h);
    lcd.print(":");
      lcd.print(t);
      delay(1000);
  mint[i]=t;
lcd.clear();
lcd.print("entr mdcn code"); 
    for(int i=0;i<4;i++)
      
     {
      char key = keypad.waitForKey(); 
     
      if(key=='#')
    {break;
    }
   hr=hr*10+(key-48);
    lcd.clear();
  lcd.print(hr);
     }
menu();
}
//##############################################################################################################################################
void rems()
{
  for(int g=0;g<rem;g++)
{
    lcd.clear();
    int th=0,ph=0;
    th=hor[g];
    ph=mint[g];
  lcd.print(th);
   lcd.print(":");
   lcd.print(ph);
    delay(1000);
    }
    menu();
}  
 //###################################################################################################################################################

  void reset()
  { 
    lcd.clear();
  lcd.print("reset");
  loop();
 delay(1000);
 }
// #######################################################################################################################################3333
   void disptime()
     {
         lcd.clear();
           lcd.print("TIME:")  ;
         lcd.print(hour())  ; 
         lcd.print(":")  ;
         lcd.print(minute())  ;
          
          lcd.print(":")  ;
          lcd.print(second());
          lcd.setCursor(0, 1);
           lcd.print("Date:")  ; 
            lcd.print(day());
          lcd.print(":");
          lcd.print(month());
          lcd.print(":");
          lcd.print(year());
          delay(500);
   double thm,phm,a,s;
  for (i=0;i<rem;i++)
          {
    thm=hor[i];
    phm=mint[i];
    int a=hour();
    int b=minute();
   if (thm==a)
   {
 goto l;
   }
   l:if (phm==b)
   {
     j=i;
    hor[i]=25;
    mint[i]=80;
   alarm();
   j++;
   }
          
 }
     }
 
 

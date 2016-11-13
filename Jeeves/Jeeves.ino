int Pin_light=13;
int Pin_fan=12;
int Pin_tv=11;
int Pin_ac=10;
int i,flag=0;
String Device_list[]={"TV","tv","television","AC","ac","air conditioner","Air Conditioning","fan","Fan","light","Light","lights","Everything","everything","all","All"};
String Comm_voice;
int called_pin;
 
void setup() {
pinMode(Pin_light, OUTPUT);  		
  pinMode(Pin_fan, OUTPUT);
  pinMode(Pin_tv, OUTPUT);
  pinMode(Pin_ac, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    while(Serial.available()==0);
  Serial.flush();
   
  Comm_voice = Serial.readString();
  Serial.println(Comm_voice);
  flag=0;
  for(i=0;i<15;i++)
  {
    if(Comm_voice.indexOf(Device_list[i])>=0)
	{
	if(Comm_voice.indexOf("Light")>=0 || Comm_voice.indexOf("light")>=0 || Comm_voice.indexOf("lights")>=0)
		{
		flag=1;
		called_pin=Pin_light;
		}
	else if(Comm_voice.indexOf("tv")>=0 || Comm_voice.indexOf("TV")>=0 || Comm_voice.indexOf("television")>=0)
	{
		flag=1;
		called_pin=Pin_tv;
		}
	else if(Comm_voice.indexOf("AC")>=0 || Comm_voice.indexOf("ac")>=0 || Comm_voice.indexOf("air conditioner")>=0 ||  Comm_voice.indexOf("Air Conditioning")>=0)
		{
		flag=1;
		called_pin=Pin_ac;
		}
	else if(Comm_voice.indexOf("fan")>=0 || Comm_voice.indexOf("Fan")>=0)
		{
		flag=1;
		called_pin=Pin_fan;
		}
        else if(Comm_voice.indexOf("Everything")>=0 || Comm_voice.indexOf("All")>=0 || Comm_voice.indexOf("everything")>=0 || Comm_voice.indexOf("all")>=0)
                {
                  flag=2;
                }
	}
	else
        {
        }
  }
      Serial.println(flag);
        if(flag==1)
	{
        if(Comm_voice.indexOf("on")>=0)
		{
  		Serial.println("ON");
  		digitalWrite(called_pin, HIGH);
  		Serial.println("Led on");
		}  
	if(Comm_voice.indexOf("off")>=0)
		{
		 Serial.println("OFF");
		 digitalWrite(called_pin, LOW);
		 Serial.println("Led off");
		}
	}
        
       else if(flag==2)
        {
          if(Comm_voice.indexOf("on")>=0)
                {
                  Serial.println("ON");
                  digitalWrite(Pin_light, HIGH);
                  digitalWrite(Pin_fan, HIGH);
                  digitalWrite(Pin_tv, HIGH);
                  digitalWrite(Pin_ac, HIGH);
                }
           if(Comm_voice.indexOf("off")>=0)
           {
             Serial.println("OFF");
             digitalWrite(Pin_light, LOW);
             digitalWrite(Pin_fan, LOW);
             digitalWrite(Pin_tv, LOW);
             digitalWrite(Pin_ac, LOW);
           
        }
        
        
}


}


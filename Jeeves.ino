int Pin_light=13;
int Pin_fan=12;
int Pin_tv=11;
int Pin_ac=10;
int i,flag=0;
String Device_list[]={"TV","tv","television","AC","ac","Air Conditioner","Air Conditioning",fan","Fan","light","Light","lights"};
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
  
  for(i=0;i<11;i++)
  {
    if(Comm_voice==Device_list[i])
	{
	if(Comm_voice=="Light" || Comm_voice=="light" || Comm_voice=="lights")
		{
		flag=1;
		called_pin=Pin_light;
		}
	else if(Comm_voice=="TV" || Comm_voice=="tv" || Comm_voice=="television")
		{
		flag=1;
		called_pin=Pin_tv;
		}
	else if(Comm_voice=="AC" || Comm_voice=="ac" || Comm_voice=="Air Conditioner" ||  Comm_voice=="Air Conditioning")
		{
		flag=1;
		called_pin=Pin_ac;
		}
	else if(Comm_voice=="fan" || Comm_voice=="Fan")
		{
		flag=1;
		called_pin=Pin_fan;
		}
	else
		{}
 	}
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

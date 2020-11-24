int AnalogWert;
int Distanz;
unsigned long zeitAnfang = 0;
unsigned long intervall = 500;

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  if ((millis() - zeitAnfang) > intervall)
  { 
    AnalogWert = analogRead(1);
    Distanz = pow((3027.4 / AnalogWert), 1.2134);
    Serial.println(Distanz);
    zeitAnfang = millis();
  }
}

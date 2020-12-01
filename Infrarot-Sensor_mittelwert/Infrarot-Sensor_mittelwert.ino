int analogWert;
int distanz;
unsigned long zeitAnfang = 0;
unsigned long intervall = 500;
int analogWerte[3] = {0, 0, 0};
int zaehler = 0;
int dataOne = 0;
int ergebnis = 0;
int Mittelwert = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  if ((millis() - zeitAnfang) > intervall)
  {

    analogWerte[zaehler] = analogRead(1);
    zaehler++;
    zeitAnfang = millis();
    if (zaehler == 3)
    {
      ergebnis = 0;
      for (int i = 0; i < 3; i++)
      {
        dataOne = analogWerte[i];
        ergebnis = ergebnis + dataOne;
      }
      Mittelwert = ergebnis / 3;
      distanz = pow((3027.4 / Mittelwert), 1.2134);
      Serial.println(distanz);
      zaehler = 0;
      /*if (distanz <= 15)
      {
        Serial.println("9 Blöcke- Lager voll");
      }
      if ((distanz <= 20) && (distanz >= 17))
      {
        Serial.println("8 Blöcke");
      }
      if ((distanz <= 24) && (distanz >= 21))
      {
        Serial.println("7 Blöcke");
      }*/

    }
  }
}

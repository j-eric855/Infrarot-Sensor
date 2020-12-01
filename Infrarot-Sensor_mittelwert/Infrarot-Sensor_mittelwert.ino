/*
  Funktion:         Analogwerte werden gespeichert, sortiert und der Mittelwert ausgegeben
  Programierer:     Mattis Menge, Henning Meyer, Eric Junker
  letzte Änderung:  01.12.2020
  Version:          1.0
  Hardware:         Analog 1 = Infrarot Sensor
*/

int anzahlMesswerte = 10;
int analogWert;
int distanz;
unsigned long zeitAnfang = 0;
unsigned long intervall = 500;
int analogWerte[10];
int zaehler = 0;
int dataOne = 0;
int ergebnis = 0;
int mittelwert = 0;


void setup()
{
  Serial.begin(9600);
}

void loop()
{

  if ((millis() - zeitAnfang) > intervall)                //Im eingestelltem Intervall werden die Daten im Array gespeichert
  {

    analogWerte[zaehler] = analogRead(1);
    zaehler++;
    zeitAnfang = millis();
    if (zaehler == anzahlMesswerte)                       //Ist eine bestimtme Anzahl von Werten erreicht
    {
      BubbleSort(analogWerte, 10);

      ergebnis = 0;
      for (int i = 0; i < anzahlMesswerte; i++)           //Werte werden zusammengerechent
      {
        dataOne = analogWerte[i];
        ergebnis = ergebnis + dataOne;
      }

      mittelwert = ergebnis / (anzahlMesswerte - 2);           //Mittelwert wird gebildet
      distanz = pow((3027.4 / mittelwert), 1.2134);        //Umrechnung in cm
      Serial.println(distanz);
      zaehler = 0;
    }
  }
}

void BubbleSort(int messwerte[], int anzahl)
{
  for (int i = 0; i < (anzahl - 1); i++)
  {
    for (int j = 0; j < (anzahl - (i + 1)); j++)
    {
      if (messwerte[j] > messwerte[j + 1])
      {
        int zwischenwert = messwerte[j];
        messwerte[j] = messwerte[j + 1];
        messwerte[j + 1] = zwischenwert;
      }
    }
  }
  messwerte[0] = 0;
  messwerte[anzahl] = 0;
}


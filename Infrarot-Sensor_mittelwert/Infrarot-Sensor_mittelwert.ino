/*
  Funktion:         Analogwerte werden gespeichert, sortiert und der Mittelwert ausgegeben
  Programierer:     Mattis Menge, Henning Meyer, Eric Junker
  letzte Änderung:  03.12.2020
  Version:          1.1
  Hardware:         Analog 1 = Infrarot Sensor

  Benutztung:       Anzahl Messwerte muss mit der Anzahl im Array "analogWerte" überein stimmen;
                    Mit dem intervall legt man die Zeitspanne fest, in der die Messwerte abgespeichert werden;
*/

int anzahlMesswerte = 20;
int distanz;
unsigned long zeitAnfang = 0;
unsigned long intervall = 300;
int analogWerte[20];
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

      mittelwert = ergebnis / (anzahlMesswerte - 2);      //Mittelwert wird gebildet
      distanz = pow((3027.4 / mittelwert), 1.2134);       //Umrechnung in cm
      Serial.println(distanz);
      zaehler = 0;
    }
  }
}

void BubbleSort(int messwerte[], int anzahl)               //Array wird nach größe Sortiert von klein zu groß
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
  messwerte[0] = 0;                                        //Erster und letzter Messwerte werden gelöscht
  messwerte[anzahl] = 0;
}

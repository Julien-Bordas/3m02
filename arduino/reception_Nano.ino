
struct donneesMesureesDef //On définit une structure de données contenant 5 membres : 
{float voltageA; int16_t intValueA; float voltageB; uint8_t byteA; float voltageC;}
__attribute__((packed));; //"attribute((packed))" permet de s'assurer que les données de la structure soient empaquetées sans décalage.

donneesMesureesDef donneesAtransmettre; //On définit une instance de la structure "donneesMesureesDef".

bool nouvellesDonnes = false; //Indique si de nouvelles données ont été reçues ou non.

void setup()
{
      Serial.begin(19200); //On lance la communication série avec une vitesse de 19200 bauds.
      //Serial1.begin(9600);
}

void loop()
{
      //if (Serial1.available())
      if (Serial.available()) //Vérifie si des données sont disponibles dans le port série.
      {
            //Serial1.readBytes((byte*)&donneesAtransmettre, sizeof donneesAtransmettre);
            Serial.readBytes((byte*)&donneesAtransmettre, sizeof donneesAtransmettre); //Si les données sont disponibles, le programme les lit dans la strucutre  "donneesAtransmettre".
            nouvellesDonnes = true; 
      }
      
      if (nouvellesDonnes) //Si "nouvellesDonnes" est vrai : 
      {
            Serial.print(donneesAtransmettre.voltageA); Serial.print("\t"); //Imprime les membres de la structure "donneesAtransmettre" et les sépare par des tabulations.
            Serial.print(donneesAtransmettre.voltageB); Serial.print("\t");
            Serial.print(donneesAtransmettre.voltageC); Serial.print("\t");
            Serial.print(donneesAtransmettre.intValueA); Serial.print("\t");
            Serial.print(donneesAtransmettre.byteA); Serial.print("\t");
            Serial.println("");
            
            nouvellesDonnes = false;
      }
}
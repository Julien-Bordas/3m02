struct donneesMesureesDef //On définit une structure de données contenant 5 membres : 
{float voltageA; int16_t intValueA; float voltageB; uint8_t byteA; float voltageC;}
__attribute__((packed));; //"attribute((packed))" permet de s'assurer que les données de la structure soient empaquetées sans décalage.

donneesMesureesDef donneesAtransmettre; //On définit une instance de la structure "donneesMesureesDef".

unsigned long loopTime = 500; //La boucle principale est excécutée toutes les 500 ms
unsigned long loopTimeR = millis(); //Renvoie le nombre de millisecondes écoulées depuis le démarrage du programme.

String maPhrase = " ";  //Sert à stocker les phrases reçues via le moniteur série.

void setup()
{
      Serial.begin(19200); //On lance la communication série avec une vitesse de 19200 bauds.
    //Serial1.begin(9600);
      
      donneesAtransmettre.voltageA = 12.55; //On définit des valeurs initiales pour les membres de l'instance "donneesAtransmettre".
      donneesAtransmettre.voltageB = 2.03;
      donneesAtransmettre.voltageC = 3750.20;
}

void loop()
{
      if (millis()-loopTimeR >= loopTime) //Si l'intervalle de temps écoulé depuis la dernière itération de la boucle est supérieur à 500 millisecondes :
      {
            Serial.write((byte *)&donneesAtransmettre, sizeof donneesAtransmettre); //Les données stockées dans "donneesAtransmettre" sont envoyées via la communication série.
            donneesAtransmettre.voltageA += 0.25; //On fait varier les valeurs à l'aide de constantes. 
            donneesAtransmettre.voltageB += 1.1;
            donneesAtransmettre.voltageC += 110.02;
            donneesAtransmettre.intValueA ++;
            donneesAtransmettre.byteA ++;

            loopTimeR = millis(); //On remet à jour le temps d'exécution de la boucle.
            
           // while (1); // ajout test
      }
}
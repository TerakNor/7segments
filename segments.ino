// Code permettant d'afficher un compteur de 0 à 99 sur 2 afficheurs à segments
// Auteur : TerakNor
// Version : 1.0

// Déclaration des variables

// déclaration des pins des 2 afficheurs à segment.
// Déclarer les pins dans l'ordre suivant : {a,b,c,d,e,f,g,dp}
int afficheurs[2][8] = {{7,6,5,11,10,8,9,4},{14,15,16,3,2,19,18,17}};
// Déclaration du masque permettant d'éteindre les afficheurs
int noir [8]= {0,0,0,0,0,0,0,0};
// Déclaration des 10 masques des 10 chiffres (de 0 à 9)
int chiffres[10][8]={{1,1,1,1,1,1,0,0},
                     {0,1,1,0,0,0,0,0},
                     {1,1,0,1,1,0,1,0},
                     {1,1,1,1,0,0,1,0},
                     {0,1,1,0,0,1,1,0},
                     {1,0,1,1,0,1,1,0},
                     {1,0,1,1,1,1,1,0},
                     {1,1,1,0,0,0,0,0},
                     {1,1,1,1,1,1,1,0},
                     {1,1,1,1,0,1,1,0}
                   };
//Fonction d'affichage : prend en entrée la liste des pins d'un afficheur et le masque des bits d'affichage
void affiche( int leds[], int masque[])
{
  int i;
  // Pour chacune des 8 leds on affiche en fonction du masque
  for(i=0;i<=7;i++){ 
    digitalWrite(leds[i],masque[i]);
  };
};
// Initialisation
void setup() 
{ 
    int i;
    // On met toutes les leds des 2 afficheurs en sortie
    for(i=0;i<=7;i++){ 
        pinMode(afficheurs[0][i],OUTPUT);
        pinMode(afficheurs[1][i],OUTPUT);
    };
} 
// Boucle principale
void loop() 
{ 
  // on éteint tout (évite des restes disgracieux d'anciens affichages)
  affiche(afficheurs[0],noir);
  affiche(afficheurs[1],noir);
  
  int i;
  // On fait tout clignoter 10 fois parce que ... parce que
  for(i=0;i<=9;i++){
    affiche(afficheurs[0],chiffres[0]);
    affiche(afficheurs[1],chiffres[0]);
    delay(300);
    affiche(afficheurs[0],noir);
    affiche(afficheurs[1],noir);
    delay(300);
  };
  
  int dec;
  // boucle d'affichage des nombres de 0 à 99
  for(i=0;i<=99;i++){ 
        // on prend la partie décimale pour le premier afficheur
        dec=i/10;
        affiche(afficheurs[0],chiffres[dec]);
        // on soustrait la partie décimale du nombre pour afficher les unités sur le 2ieme afficheur
        affiche(afficheurs[1],chiffres[i-(dec*10)]);
        // on lit la valeur du potentiomètre sur la sortie analogique A0 pour en déduire le délai avant le prochain chiffre
        delay(analogRead(A0));
    };  
  }




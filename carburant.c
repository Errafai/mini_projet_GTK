#include<stdio.h>
#include<string.h>

double retard(double total,char mois_actuel[20]);

enum type_carburant{
     Essence,
     Gazoil,
     hybride,
     electrique,

};
int main(){
    int puissance,i,nombre;
    const int PUISSANCE_MIN[] = {0, 8, 11, 15}; // Tableau des valeurs minimales de puissance pour essence
    const int SOMME[] = {350, 650, 3000, 8000}; // Tableau des sommes correspondantes pour essence
    const int PUISSANCE_MIN1[] = {0, 8, 11, 15}; // Tableau des valeurs minimales de puissance pour gazoil
    const int SOMME1[] = {700, 1500,6000, 20000}; // Tableau des sommes correspondantes pour gazoil
    enum type_carburant carburant;
    double  total=0.0;
    char mois_actuel[20];

    printf("quel est votre type de carburant\n");
    printf("entrez \t0 si il s\'agit de essence \n \t1 si il s\'agit de Gazoil\n \t2 si il s\'agit de hybride \n\t3 si il s\'agit de electrique\n");
    scanf("%d",&nombre);

    switch(nombre){

    case Essence:
        printf("Veuillez entrer la puissance fiscale de votre voiture : ");
        scanf("%d", &puissance);

        if (puissance <=PUISSANCE_MIN[0]) {
        printf("Veuillez saisir une valeur valide de la puissance de votre voiture.\n");
    }
    else {
         for (i = 0; i < sizeof(PUISSANCE_MIN) / sizeof(PUISSANCE_MIN[0]); i++) {
            if (puissance < PUISSANCE_MIN[i + 1]&&puissance<15) {
                total= SOMME[i];
                break;
            }
            else if(puissance>=15)
                total=SOMME[3];
        }
        printf("La somme %c payer est %f DH.\n",133, total);
    }
        break;
    case Gazoil:
        printf("Veuillez entrer la puissance fiscale de votre voiture : ");
        scanf("%d", &puissance);

    if (puissance <=PUISSANCE_MIN1[0]) {
        printf("Veuillez saisir une valeur valide de la puissance de votre voiture.\n");
    }
    else {
        int i;
        for (i = 0; i < sizeof(PUISSANCE_MIN1) / sizeof(PUISSANCE_MIN1[0]); i++) {
            if (puissance < PUISSANCE_MIN[i + 1]&&puissance<15) {
                total = SOMME1[i];
                break;
            }
            else if(puissance>=15)
                total=SOMME1[3];
        }
        printf("La somme %c payer est %f DH.\n",133, total);
    }

        break;
    case hybride:
        printf("votre total de vignette est %.0f DH\n",total);
        break;
    case electrique:
        printf("votre total de vignette est %.0f DH\n",total);
        break;

    }
    printf("c\'est quoi le mois actuel\n **merci de le taper en minuscule**");
    scanf("%s",mois_actuel);
    total=retard(total,mois_actuel);
    printf("**si tu es en retard jusqu\'%c avril elle s\'ajoute 15%c de votre total\n \tsi tu as d%cpass%c avril elle s\'ajoute 0.5%c pour chaque mois\n**",133,37,130,130,37);

    printf("la somme %c payer en tenant compte des p%cnalit%cs est :%f\n ",133,130,130,total);




return 0;

}
double retard(double total,char mois_actuel[20]){


        const char *mois[]={"janvier","février","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","décembre"};
        for(int j=0;j<12;++j){

            if(strcmp( mois_actuel,mois[j])==0){
                if(j!=0){
                total+=total*0.15; //ajoute des frais de retard tels que si le retard est jusquà février on ajoute 0.15%des frais si jusquà un autre mois on ajoute 0,15 % our chaque mois de retard
                total+=total*0.005*(j-1);
                }
            break;
            }
        }

return total;
}

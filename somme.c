#include <stdio.h>
#include <stdlib.h>

float calculer_assurance(int poin_puiss, int choix) {
    float assurance;
    float tableau[2][29]={
        {1214.55 , 1214.55 ,1214.55 , 1214.55 ,1214.55 , 1214.55 ,1473.57 ,1473.57 ,1597.89 ,1597.89 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41  },
        {2234.66 , 2234.66 ,2234.66 , 2234.66 ,2234.66 , 2234.66 ,2714.35 ,2714.35 ,2944.56 ,2944.56 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32  }
    };


        if (strcmp("SEMESTRIELLE", choix))
            assurance = tableau[0][poin_puiss+1];
        else
            assurance = tableau[1][poin_puiss+1];

    return assurance ;
}

int main () {
    char marque[20];
    int puiss;
    float assurance;
    int choix;
    int* poin_puiss = &puiss;

    printf("veuilliez entrer votre marque de voiture et votre puisssance fiscale :");
    scanf("%s %d", marque, &puiss);
    printf("pour payer une assurance semestrielle taper 1 \npour payer une assurance semestrielle taper 2\n ");
    scanf("%d", &choix);
    assurance = calculer_assurance(poin_puiss, choix);
    printf("le montant que vous devez payer d'une %s de puissance fiscale %d est : %.2f DH", marque, puiss, assurance);

    return 0;
}

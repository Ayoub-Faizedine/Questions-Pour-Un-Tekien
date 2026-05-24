#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

// Déclaration des prototypes externes
void LancerModeEnseignant();
void LancerModeEtudiant();

int main() {
    int choix = 0;

    do {
        printf("\n===================================\n");
        printf("     QUESTIONS POUR UN TEKIEN     \n");
        printf("===================================\n");
        printf("1) Mode Enseignant\n");
        printf("2) Mode Etudiant\n");
        printf("3) Quitter\n");
        printf("Votre Choix : ");
        
        if (scanf("%d", &choix) != 1) {
            printf(" Erreur : veuillez saisir un nombre valide.\n");
            while (getchar() != '\n'); // nettoyage
            continue;
        }
            
        switch (choix) {
            case 1:
                LancerModeEnseignant();
                break;
            case 2:
                LancerModeEtudiant();
                break;
            case 3:
                printf("Fermeture de l'application. À bientôt !\n");
                break;
            default:
                printf("Erreur : Choix invalide (entrez 1, 2 ou 3).\n");
                break;
        }
    } while (choix != 3);

    return 0;
}

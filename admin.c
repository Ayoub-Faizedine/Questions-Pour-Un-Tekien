#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void LancerModeEnseignant() {
    char mdpSaisi[50];
    int essais = 3;
    
    printf("\n===================================\n");
    printf("          MODE ENSEIGNANT          \n");
    printf("===================================\n");

    // 1. GESTION DE L'AUTHENTIFICATION
    while (essais > 0) {
        printf("Veuillez saisir le mot de passe : ");
        scanf("%s", mdpSaisi);

        if (strcmp(mdpSaisi, MOT_DE_PASSE) == 0) {
            printf(">> Acces Autorise.\n");
            // Nettoyage 
            while (getchar() != '\n'); 
            break; // Sort de la boucle des mots de passe
        } else {
            essais--;
            printf(">> Erreur, mauvais mot de passe. Il vous reste %d essai(s).\n", essais);
            if (essais == 0) {
                printf(">> Vous avez echoue a taper le mot de passe ! Retour au menu.\n");
                return; // Quitte la fonction et retourne au menu principal
            }
        }
    }

    // 2. CRÉATION DU QCM
    char nomQCM[50];
    char nomFichier[60];
    int ptsNegatifs, reponsesMultiples, modeSequentiel, nbQuestion, i;
    FILE *f = NULL;

    char enonce[MAX_TEXT], propA[MAX_TEXT], propB[MAX_TEXT], propC[MAX_TEXT], propD[MAX_TEXT], solution[10];

    printf("\n--- CREATION D'UN NOUVEAU QCM ---\n");
    printf("Entrez le nom du QCM (sans espaces) : ");
    scanf("%s", nomQCM);
    sprintf(nomFichier, "%s.txt", nomQCM);

    printf("Activer les points negatifs ? (1:Oui / 0:Non) : ");
    scanf("%d", &ptsNegatifs);
    
    printf("Autoriser plusieurs reponses vraies ? (1:Oui / 0:Non) : ");
    scanf("%d", &reponsesMultiples);
    
    printf("Activer le mode sequentiel ? (1:Oui / 0:Non) : ");
    scanf("%d", &modeSequentiel);

    printf("Combien de questions contient ce QCM ? ");
    scanf("%d", &nbQuestion);

    // Nettoyage
    while (getchar() != '\n'); 

    f = fopen(nomFichier, "w");
    if (f == NULL) {
        printf("🚨 Erreur : Impossible de creer le fichier %s.\n", nomFichier);
        return;
    }

    // Écriture de la configuration pour le mode Étudiant
    fprintf(f, "%d %d %d\n", ptsNegatifs, reponsesMultiples, modeSequentiel);
    fprintf(f, "%d\n", nbQuestion);

    for (i = 1; i <= nbQuestion; i++) {
        printf("\n--- Question %d ---\n", i);
        
        printf("Enonce : ");
        fgets(enonce, MAX_TEXT, stdin);
        enonce[strcspn(enonce, "\n")] = 0; // Retire le \n

        printf("Proposition A : ");
        fgets(propA, MAX_TEXT, stdin);
        propA[strcspn(propA, "\n")] = 0;

        printf("Proposition B : ");
        fgets(propB, MAX_TEXT, stdin);
        propB[strcspn(propB, "\n")] = 0;

        printf("Proposition C : ");
        fgets(propC, MAX_TEXT, stdin);
        propC[strcspn(propC, "\n")] = 0;

        printf("Proposition D : ");
        fgets(propD, MAX_TEXT, stdin);
        propD[strcspn(propD, "\n")] = 0;

        printf("Solution attendue (ex: A, ou AC) : ");
        scanf("%s", solution);
        
        while (getchar() != '\n'); // Nettoyage 

        fprintf(f, "%s\n%s\n%s\n%s\n%s\n%s\n", enonce, propA, propB, propC, propD, solution);
    }

    fclose(f);
    printf("\n✅ Le QCM '%s' a ete cree et sauvegarde avec succes !\n", nomQCM);
}

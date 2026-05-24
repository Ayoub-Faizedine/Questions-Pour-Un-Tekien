#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h" // On appelle votre fichier commun
#include "fonctions.h" // A ajouter si tu as le fichier fonctions.h

void LancerModeEtudiant() {
    char nomFichier[60];
    char nomQCM[50];
    int ptsNegatifs, reponsesMultiples, modeSequentiel, nbQuestions, i;
    float noteTotale = 0, pointsMax = 0;
    char reponseUser[10];

    printf("\n===================================\n");
    printf("           MODE ETUDIANT           \n");
    printf("===================================\n");
    
    printf("Entrez le nom du QCM a charger (sans '.txt') : ");
    scanf("%s", nomQCM);
    sprintf(nomFichier, "%s.txt", nomQCM); // Formate le nom comme dans le mode Enseignant

    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("🚨 Erreur : Impossible de trouver le QCM '%s'.\n", nomFichier);
        return; 
    }

    // 1. LECTURE DES PARAMÈTRES
    fscanf(fichier, "%d %d %d", &ptsNegatifs, &reponsesMultiples, &modeSequentiel);
    fscanf(fichier, "%d", &nbQuestions);

    // Création du tableau de questions
    Question q[nbQuestions];

    // Nettoyage 
    while (fgetc(fichier) != '\n');

    // 2. CHARGEMENT DES QUESTIONS
    for (i = 0; i < nbQuestions; i++) {
        fgets(q[i].enonce, MAX_TEXT, fichier);
        q[i].enonce[strcspn(q[i].enonce, "\n")] = 0; // Nettoie 

        fgets(q[i].optA, MAX_TEXT, fichier);
        q[i].optA[strcspn(q[i].optA, "\n")] = 0;

        fgets(q[i].optB, MAX_TEXT, fichier);
        q[i].optB[strcspn(q[i].optB, "\n")] = 0;

        fgets(q[i].optC, MAX_TEXT, fichier);
        q[i].optC[strcspn(q[i].optC, "\n")] = 0;

        fgets(q[i].optD, MAX_TEXT, fichier);
        q[i].optD[strcspn(q[i].optD, "\n")] = 0;

        fgets(q[i].reponseCorrecte, 10, fichier);
        q[i].reponseCorrecte[strcspn(q[i].reponseCorrecte, "\n")] = 0;
    }
    fclose(fichier);

    // 3. PASSAGE DU QCM
    printf("\n--- DÉBUT DU TEST ---\n");
    for (i = 0; i < nbQuestions; i++) {
        printf("\nQuestion %d : %s\n", i + 1, q[i].enonce);
        printf("A) %s\nB) %s\nC) %s\nD) %s\n", q[i].optA, q[i].optB, q[i].optC, q[i].optD);
        
        // Adaptation 
        if (modeSequentiel == 0) {
            printf("Votre choix (ex: A, AC) ou tapez P pour passer : ");
        } else {
            printf("Votre choix obligatoire (ex: A, AC) : ");
        }
        
        scanf("%s", reponseUser);

        // --- MODIFICATION : Conversion manuelle en majuscules ---
        int k;
        for(k = 0; reponseUser[k] != '\0'; k++) {
            if (reponseUser[k] >= 'a' && reponseUser[k] <= 'z') {
                reponseUser[k] = reponseUser[k] - 32;
            }
        }
        // -------------------------------------------------------

        // Si le mode séquentiel est désactivé et que l'étudiant passe
        // Note: La réponse est maintenant forcément en majuscule, "P" suffit.
        if (modeSequentiel == 0 && strcmp(reponseUser, "P") == 0) {
            printf(">> Question ignorée.\n");
            pointsMax += 1;
            continue; 
        }

        pointsMax += 1; // 1 point de base par question

        // Vérification de la réponse 
        if (strcmp(reponseUser, q[i].reponseCorrecte) == 0) {
            printf(">> Correct !\n");
            noteTotale += 1;
        } else {
            printf(">> Mauvaise réponse. (La solution était %s)\n", q[i].reponseCorrecte);
            if (ptsNegatifs == 1) {
                printf(">> Malus appliqué (-0.5 pt).\n");
                noteTotale -= 0.5;
            }
        }
    }

    // 4. CALCUL DE LA NOTE (sur 20 points, selon le cahier des charges)
    float noteSur20 = 0;
    if (pointsMax > 0) {
        noteSur20 = (noteTotale / pointsMax) * 20.0;
    }
    
    // Sécurité 
    if (noteSur20 < 0) {
        noteSur20 = 0;
    }

    printf("\n==============================");
    printf("\n   NOTE FINALE : %.2f / 20", noteSur20);
    printf("\n==============================\n");
}

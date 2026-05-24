#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_TEXT 256
#define MOT_DE_PASSE "tekien2026" // Protégé par un mot de passe 

typedef struct {
    char enonce[MAX_TEXT];
    char optA[MAX_TEXT];
    char optB[MAX_TEXT];
    char optC[MAX_TEXT];
    char optD[MAX_TEXT];
    char reponseCorrecte[10]; // Modifié ici pour gérer "AB", "ACD", etc.
} Question;

#endif

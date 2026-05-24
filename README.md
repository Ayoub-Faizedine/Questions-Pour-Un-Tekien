# Projet C - Questions pour un Tekien

**Auteurs :** Ayoub & Mohamed MI5
**Niveau :** Cycle PreING1

---

## Description du Projet
"Questions pour un Tekien" est un gestionnaire de QCM interactif code en C. Le programme est divise en deux espaces securises permettant de separer la creation des examens (par le professeur) et leur passage (par les etudiants). Toutes les donnees sont gerees dynamiquement via des fichiers textes `.txt`.

## Fonctionnalites et Robustesse

Nous avons accorde une attention particuliere a la **securite des saisies** pour eviter tout crash du programme :

- **Securite Anti-Boucle Infinie :** Utilisation systematique de la purge du tampon clavier (`while (getchar() != '\n')`) pour gerer les cas ou un utilisateur tape des lettres au lieu de chiffres.
- **Insensibilite a la casse :** Les reponses des etudiants (a, b, ac...) sont manuellement converties en majuscules via la table ASCII (soustraction de 32), sans utiliser de bibliotheques externes, pour garantir une correction sans faille.
- **Controles stricts :** Les parametres de creation du QCM (0 ou 1) sont proteges par des boucles `do-while` bloquantes.

### Mode Enseignant (Securise)
- Protege par le mot de passe administrateur : `tekien2026`.
- Configuration du QCM : Points negatifs (malus), reponses multiples, et mode sequentiel.
- Generation automatique du fichier de configuration `.txt`.

### Mode Etudiant
- Chargement dynamique de n'importe quel QCM cree.
- Application du bareme en temps reel et affichage de la note sur 20.
- Gestion du saut de question (touche 'P') si le mode sequentiel est desactive.

---

## Architecture des Fichiers

- `main.c` : Point d'entree, prototypes des fonctions et menu principal.
- `admin.c` : Logique de creation de fichiers et d'authentification.
- `etudiant.c` : Logique de lecture, de deroulement du test et de notation.
- `structures.h` : Fichier d'en-tete commun contenant la structure `Question`.
- `Makefile` : Script de compilation automatisee (norme C99).
- `Math.txt`, `math2.txt`, `math3.txt` : Fichiers de tests generes par notre programme montrant differentes configurations.

---

## Compilation et Execution (Linux / WSL)

Placez-vous dans le repertoire du projet depuis un terminal.

**1. Compiler le projet :**
make

**2. Lancer l'application :**
./tekien

**3. Nettoyer les fichiers compiles (.o) :**
make clean

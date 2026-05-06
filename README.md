# Questions-Pour-Un-Tekien

##  Description
"Questions pour un Tekien" est un gestionnaire de QCM interactif développé en langage C. 
Il propose deux modes :
- **Mode Enseignant** : Création, paramétrage (points négatifs, réponses multiples) et sauvegarde de QCM dans des fichiers.
- **Mode Étudiant** : Passage des QCM avec évaluation et notation automatique sur 20.



## Participant
  Ayoub.F et Mohamed MI5 .



## Mode Enseignant
-Doit être protégé par un mot de passe

-création d’un nouveau QCM dont les
informations devront être sauvegardées dans un fichier pour qu’il
puisse être réalisé ultérieurement

-QCM doit avoir un nom pour pouvoir être identifiable.

-paramètres qui seront choisis par l’enseignant : 
      la possibilité de mettre des points négatifs si une réponse
      fausse est choisie.
       la possibilité d’avoir plusieurs réponses vraies par question
       l’obligation ou non de devoir répondre à une question avant
      de passer à la suivante (mode séquentiel).
       Ces paramètres seront valables pour l’ensemble du QCM et
      non pas par question.


## Mode Étudiant

-Effectuer les QCM qui auront été créés
précédemment et enregistrés dans des fichiers.
-mode est choisi, la liste des QCM disponibles doit être
affichée et l’étudiant peut alors indiquer quel QCM il ‘souhaite’ faire

-Lorsque le QCM est fini, le programme doit comparer les réponses de
l’étudiant avec les réponses attendues, calculer la note, et la fournir à
l’étudiant.

- La note donnée doit toujours être sur 20 points et, par
défaut, chaque question fera le même nombre de points



## Détail
- Plusieur Mode
- Limite de Temps
- Ranger les QCM par catégories.
- Possibilité d’indiquer le nombre de points que vaut une question.
- Ajouter une interface graphique et/ou des appuis clavier dynamiques
-Possibilité de revenir sur une question précédente lorsqu’on passe
un QCM
- Vous pouvez implémenter d’autres améliorations de votre choix

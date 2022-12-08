#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NOM 10

// Fonction qui vérifie que les paramètres d'entrée sont valides
int valider_params(int argc, char* argv[], int* nb_poules, int* age_depart, int* age_fin)
{
  // Vérifie que les paramètres d'entrée sont valides
  if (argc != 4)
  {
    printf("Usage: %s <nombre de poules> <age de depart> <age de fin>\n", argv[0]);
    return 0;
  }

  // Récupère les paramètres d'entrée
  *nb_poules = atoi(argv[1]);
  *age_depart = atoi(argv[2]);
  *age_fin = atoi(argv[3]);

  // Vérifie que les paramètres d'entrée sont valides
  if (*nb_poules <= 0 || *age_depart < 0 || *age_fin <= *age_depart)
  {
    printf("Les paramètres doivent être positifs et l'âge de fin doit être supérieur à l'âge de départ.\n");
    return 0;
  }

  return 1;
}

// Fonction qui affiche l'entête du tableau
void afficher_entete()
{
  // Affiche l'entête du tableau
  printf("Annee\tAge\tPoules\tLettre\tRot\tNom\tSexe\n");
  printf("------\t----\t------\t------\t---\t---\t----\n");
}

// Fonction qui calcule la population de poules pour chaque année
void calculer_population(int nb_poules, int age_depart, int age_fin)
{
  // Variables pour la boucle
  int annee, age, poules, rot, sexe;
  char lettre, nom[MAX_NOM];

  // Boucle sur chaque année
  for (annee = 0; annee <= age_fin - age_depart; annee++)
  {
    // Calcule l'âge du fermier
    age = age_depart + annee;

    // Calcule la population de poules
    poules = nb_poules;
    if (annee % 2 == 0)
      poules += poules * 0.3;
    else
      poules += poules * 0.4;
    poules = (int)poules;

    // Calcule le reste de la division par 26
    rot = poules % 26;

    // Détermine la lettre à utiliser pour le prénom
    lettre = (char)(65 + rot);

    // Vérifie si un enfant doit naître cette année
    if (poules % 2 == 0)
    {
      // Détermine le sexe de l'enfant
      if (annee % 2 == 0)
        sexe = 'F';
      else
        sexe = 'M';

      // Génère le prénom de l'enfant
      sprintf(nom, "%c%d", lettre, annee);
    }
    else
    {
      // Pas d'enfant cette année
      sexe = '-';
      strcpy(nom, "-");
    }

    // Affiche les résultats
    printf("%d\t%d\t%d\t%c\t%d\t%s\t%c\n", annee, age, poules, lettre, rot, nom, sexe);
  }
}

int main(int argc, char *argv[])
{
  // Vérifie le nombre de paramètres
  if (argc != 4)
  {
    printf("Usage: %s <nb_poules> <age_depart> <age_fin>\n", argv[0]);
    return 1;
  }

  // Récupère les paramètres d'entrée
  int nb_poules = atoi(argv[1]);
  int age_depart = atoi(argv[2]);
  int age_fin = atoi(argv[3]);

  // Vérifie les valeurs des paramètres
  if (valider_params(argc, argv, &nb_poules, &age_depart, &age_fin) < 1)
    return 1;

  // Affiche l'entête du tableau
  afficher_entete();

  // Calcule la population de poules pour chaque année
  calculer_population(nb_poules, age_depart, age_fin);

  // Tout s'est bien passé
  return 0;
}



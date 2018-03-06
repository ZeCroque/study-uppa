#include "menu.h"
#include "outils.h"

void menuPrincipal(alerte** altTab, int* iAltSize, unite** uniTab, int* iUniSize)
{
  int iUsrChoice=0;

  do
  {
    system("clear");
    printf("*****MENU PRINCIPAL*****\n\n[0]Gestion des alertes\n[1]Gestion des unités\n[2]DEBUG\n[3]Quitter\n");
    scanf("%d%*c", &iUsrChoice);
    switch (iUsrChoice)
    {
      case 0:
        traitementAlertes(altTab, iAltSize, *uniTab, *iUniSize);
        break;
      case 1:
        gestionUnite(uniTab, iUniSize);
        break;
      case 2:
          menuDebug(altTab, iAltSize, uniTab, iUniSize);
          break;
      case 3:
        break;
      default:
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=3);
}

void menuDebug(alerte** altTab, int* iAltSize, unite** uniTab, int* iUniSize)
{
  int iUsrChoice=0;

  do
  {
    system("clear");
    printf("*****MENU DEBUG*****\n\n[0]Gérer les alertes\n[1]Gérer les unités\n[2]Mode démo\n[3]Retour au menu principal\n");
    scanf("%d%*c", &iUsrChoice);
    switch (iUsrChoice)
    {
      case 0:
        gererAlertes(altTab, iAltSize);
        break;
      case 1:
        gererUnites(uniTab, iUniSize);
        break;
      case 2:
          modeDemo(altTab, iAltSize, uniTab, iUniSize);
          break;
      case 3:
        break;
      default:
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=3);
}

void gererAlertes(alerte** altTab, int* iSize)
{
  int iUsrChoice=0;
  int iUsrConfirm=0;
  int iIndex=0;

  do
  {
    system("clear");
    printf("*****GESTION DES ALERTES*****\n\n[0]Déclencher une alerte\n[1]Afficher une alerte\n[2]Modifier une alerte\n[3]Supprimer une alerte\n[4]Retour au menu principal\n");
    scanf("%d%*c",&iUsrChoice);
    switch (iUsrChoice)
    {
      case 0 :
        ajouterAlerte(altTab, iSize);
        affichageAlerte((*altTab)[(*iSize)-1]);
        validerSaisie();
        break;
      case 1 :
        system("clear");
        printf("*****AFFICHER ALERTE*****");
        iIndex=affichageTableauAlertes(*altTab, *iSize);
        if (iIndex!=-1)
        {
          affichageAlerte((*altTab)[iIndex]);
        }
        validerSaisie();
        break;
      case 2 :
      system("clear");
      printf("*****MODIFIER ALERTE*****");
        iIndex=affichageTableauAlertes(*altTab, *iSize);
        if (iIndex!=-1)
        {
          modifierAlerte(&(*altTab)[iIndex]);
          affichageAlerte((*altTab)[iIndex]);
        }
        validerSaisie();
        break;
      case 3 :
        do
        {
          system("clear");
          printf("*****SUPPRIMER ALERTE*****");
          iIndex=affichageTableauAlertes(*altTab, *iSize);
          if(iIndex!=-1)
          {
            printf("\nEtes vous sur de vouloir supprimer cette alerte?\n[0]Non\n[1]Oui\n");
            scanf("%d%*c",&iUsrConfirm);
          }
        } while(iUsrConfirm<0 || iUsrConfirm>1);
        if (iIndex!=-1)
        {
          if (iUsrConfirm)
          {
            supprimerAlerte(altTab, iIndex, iSize);
            printf("Alerte supprimée.\n\n");
          }
          else
          {
            printf("L'alerte n'a pas été supprimée\n\n");
          }
        }
        validerSaisie();
        break;
      case 4 :
        break;
      default :
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=4);
}

void gererUnites(unite** uniTab, int* iSize)
{
  int iUsrChoice=0;
  int iUsrConfirm=0;
  int iIndex=0;

  do
  {
    system("clear");
    printf("*****GESTION DES UNITES*****\n\n[0]Ajouter une unité\n[1]Afficher une unité\n[2]Modifier une unité\n[3]Supprimer une unité\n[4]Retour au menu principal\n");
    scanf("%d%*c",&iUsrChoice);
    switch (iUsrChoice)
    {
      case 0 :
        ajouterUnite(uniTab, iSize);
        affichageUnite((*uniTab)[(*iSize)-1]);
        validerSaisie();
        break;
      case 1 :
        system("clear");
        printf("*****AFFICHER UNITE*****");
        iIndex=affichageTableauUnites(*uniTab, *iSize);
        if (iIndex!=-1)
        {
          affichageUnite((*uniTab)[iIndex]);
        }
        validerSaisie();
        break;
      case 2 :
      system("clear");
      printf("*****MODIFIER UNITE*****");
        iIndex=affichageTableauUnites(*uniTab, *iSize);
        if (iIndex!=-1)
        {
          modifierUnite(&(*uniTab)[iIndex]);
          affichageUnite((*uniTab)[iIndex]);
        }
        validerSaisie();
        break;
      case 3 :
        do
        {
          system("clear");
          printf("*****SUPPRIMER UNITE*****");
          iIndex=affichageTableauUnites(*uniTab, *iSize);
          if(iIndex!=-1)
          {
            printf("\nEtes vous sur de vouloir supprimer cette unité?\n[0]Non\n[1]Oui\n");
            scanf("%d%*c",&iUsrConfirm);
          }
        } while(iUsrConfirm<0 || iUsrConfirm>1);
        if (iIndex!=-1)
        {
          if (iUsrConfirm)
          {
            supprimerUnite(uniTab, iIndex, iSize);
            printf("Unité supprimée.\n\n");
          }
          else
          {
            printf("L'unité n'a pas été supprimée\n\n");
          }

        }
        validerSaisie();
        break;
      case 4 :
        break;
      default :
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=4);
}

void traitementAlertes(alerte** altTab, int* iAltSize, unite* uniTab, int iUniSize)
{
  int iAltIndex=-1;
  int iUniIndex=-1;
  int iUsrChoice=0;
  int iIndex=0;

  do
  {
    system("clear");
    if (iAltIndex!=-1)
    {
      affichageAlerte((*altTab)[iAltIndex]);
      printf("\n");
    }
    printf("*****TRAITEMENT ALERTE*****\n\n[0]Déclencher une alerte\n[1]Afficher l'alerte\n[2]Choisir l'alerte à traiter\n[3]Affecter unité\n[4]Afficher les unités affectées\n[5]Traiter l'alerte (effacer)\n[6]Retour au menu principal\n");

    scanf("%d%*c",&iUsrChoice);
    switch (iUsrChoice)
    {
      case 0 :
        ajouterAlerte(altTab, iAltSize);
        affichageAlerte((*altTab)[(*iAltSize)-1]);
        validerSaisie();
        break;
      case 1 :
          system("clear");
          printf("*****AFFICHER ALERTE*****");
          iIndex=affichageTableauAlertes(*altTab, *iAltSize);
          if (iIndex!=-1)
          {
            affichageAlerte((*altTab)[iIndex]);
          }
          validerSaisie();
          break;
      case 2 :
        system("clear");
        printf("*****TRAITEMENT ALERTE*****");
        iAltIndex=affichageTableauAlertes(*altTab, *iAltSize);
        validerSaisie();

        break;
      case 3 :
        system("clear");
        printf("*****TRAITEMENT ALERTE*****");
        if(iAltIndex!=-1)
        {
          iUniIndex=affichageTableauUnites(uniTab, iUniSize);
          if(iUniIndex!=-1)
          {
            assignerUnite(&((*altTab)[iAltIndex]), &(uniTab[iUniIndex]));
          }
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'alerte.\n");
        }
        validerSaisie();


        break;
      case 4:
        system("clear");
        printf("*****TRAITEMENT ALERTE*****");
        if(iAltIndex!=-1)
        {
          afficherUnitesAssignees(*altTab,iAltIndex);
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'alerte.\n");
        }
        validerSaisie();
        break;
      case 5:
        system("clear");
        printf("*****TRAITEMENT ALERTE*****");
        if(iAltIndex!=-1)
        {
          traiterAlerte(altTab, iAltIndex, iAltSize);
          iAltIndex=-1;
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'alerte.\n");
        }
        validerSaisie();
        break;
      case 6:
        break;
      default :
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=6);
}

void gestionUnite(unite** uniTab, int* iUniSize)
{
  int iUniIndex=-1;
  int iUsrChoice=0;
  int iIndex=0;

  do
  {
    system("clear");
    if (iUniIndex!=-1)
    {
      affichageUnite(*(uniTab)[iUniIndex]);
      printf("\n");
    }
    printf("*****GESTION OPERATIONNELLE UNITE*****\n\n[0]Ajouter un unité\n[1]Afficher une unité\n[2]Choisir l'unité à traiter\n[3]Gérer les états\n[4]Afficher l'alerte affectée\n[5]Retour au menu principal\n");

    scanf("%d%*c",&iUsrChoice);
    switch (iUsrChoice)
    {
      case 0 :
        ajouterUnite(uniTab, iUniSize);
        affichageUnite((*uniTab)[(*iUniSize)-1]);
        validerSaisie();
        break;
      case 1 :
        system("clear");
        printf("*****AFFICHER UNITE*****");
        iIndex=affichageTableauUnites(*uniTab, *iUniSize);
        if (iIndex!=-1)
        {
          affichageUnite((*uniTab)[iIndex]);
        }
        validerSaisie();
        break;
      case 2 :
        system("clear");
        printf("*****GESTION OPERATIONNELLE UNITE*****");
        iUniIndex=affichageTableauUnites(*uniTab, *iUniSize);
        validerSaisie();

        break;
      case 3 :
        system("clear");
        printf("*****GESTION OPERATIONNELLE UNITE*****");
        if(iUniIndex!=-1)
        {
            affichageUnite((*uniTab)[iUniIndex]);
            gestionEtat(uniTab[iUniIndex]);
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'unité.\n");
        }
        validerSaisie();
        break;
      case 4:
        system("clear");
        printf("*****GESTION OPERATIONNELLE UNITE*****");
        if(iUniIndex!=-1)
        {
          afficherAlerteAssignee((*uniTab)[iUniIndex]);
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'unité.\n");
        }
        validerSaisie();
        break;
      case 5:
        break;
      default :
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=5);
}

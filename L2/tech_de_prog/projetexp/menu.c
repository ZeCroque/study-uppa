#include "menu.h"
#include "outils.h"

void menuPrincipal(alerte** altTab, int* iAltSize, unite** uniTab, int* iUniSize)
{
  int iUsrChoice=0;

  do
  {
    system("clear");
    printf("*****MENU PRINCIPAL*****\n\n[0]Gérer les alertes\n[1]Gérer les unités\n[2]Traitement des alertes\n[3]Gestion des unités\n[4]Mode démo\n[5]Quitter\n");
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
        traitementAlertes(*altTab, *iAltSize, *uniTab, *iUniSize);
        break;
      case 3:
        gestionUnite(*uniTab, *iUniSize);
        break;
      case 4:
          modeDemo(altTab, iAltSize, uniTab, iUniSize);
          break;
      case 5:
        break;
      default:
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=5);
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

void traitementAlertes(alerte* altTab, int iAltSize, unite* uniTab, int iUniSize)
{
  int iAltIndex=-1;
  int iUniIndex=-1;
  int iUsrChoice=0;

  do
  {
    system("clear");
    if (iAltIndex!=-1)
    {
      affichageAlerte(altTab[iAltIndex]);
      printf("\n");
    }
    printf("*****TRAITEMENT ALERTE*****\n\n[0]Choisir l'alerte à traiter\n[1]Affecter unité\n[2]Afficher les unités affectées\n[3]Retour au menu principal\n");

    scanf("%d%*c",&iUsrChoice);
    switch (iUsrChoice)
    {
      case 0 :
        system("clear");
        printf("*****TRAITEMENT ALERTE*****");
        iAltIndex=affichageTableauAlertes(altTab, iAltSize);
        validerSaisie();

        break;
      case 1 :
        system("clear");
        printf("*****TRAITEMENT ALERTE*****");
        if(iAltIndex!=-1)
        {
          iUniIndex=affichageTableauUnites(uniTab, iUniSize);
          if(iUniIndex!=-1)
          {
            assignerUnite(&(altTab[iAltIndex]), &(uniTab[iUniIndex]));
          }
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'alerte.\n");
        }
        validerSaisie();


        break;
      case 2:
        system("clear");
        printf("*****TRAITEMENT ALERTE*****");
        if(iAltIndex!=-1)
        {
          afficherUnitesAssignees(altTab,iAltIndex);
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'alerte.\n");
        }
        validerSaisie();
        break;
      case 3:
        break;
      default :
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=3);
}

void gestionUnite(unite* uniTab, int iUniSize)
{
  int iUniIndex=-1;
  int iUsrChoice=0;

  do
  {
    system("clear");
    if (iUniIndex!=-1)
    {
      affichageUnite(uniTab[iUniIndex]);
      printf("\n");
    }
    printf("*****GESTION OPERATIONNELLE UNITE*****\n\n[0]Choisir l'unité à traiter\n[1]Gérer la disponibilité\n[2]Afficher l'alerte affectée\n[3]Retour au menu principal\n");

    scanf("%d%*c",&iUsrChoice);
    switch (iUsrChoice)
    {
      case 0 :
        system("clear");
        printf("*****GESTION OPERATIONNELLE UNITE*****");
        iUniIndex=affichageTableauUnites(uniTab, iUniSize);
        validerSaisie();

        break;
      case 1 :
        system("clear");
        printf("*****GESTION OPERATIONNELLE UNITE*****");
        if(iUniIndex!=-1)
        {
            //TODO GestionDispo
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'unité.\n");
        }
        validerSaisie();
        break;
      case 2:
        system("clear");
        printf("*****GESTION OPERATIONNELLE UNITE*****");
        if(iUniIndex!=-1)
        {
          afficherAlerteAssignee(uniTab[iUniIndex]);
        }
        else
        {
          printf("\n\nVous n'avez pas sélectionné d'unité.\n");
        }
        validerSaisie();
        break;
      case 3:
        break;
      default :
        erreurSaisie();
        break;
    }
  } while(iUsrChoice!=3);
}

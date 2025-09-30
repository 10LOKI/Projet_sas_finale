#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

// structures
typedef struct
{
    int id_client;
    char nom[MAX_SIZE];
    char prenom[MAX_SIZE];
    char email[MAX_SIZE];
    float solde;
}client;

typedef struct 
{
    int id_produit;
    char nom_produit[MAX_SIZE];
    char categorie[MAX_SIZE];
    float prix;
    int stock;
    char description[MAX_SIZE];
}produit;

typedef struct 
{
    int jour;
    int mois;
    int annee;
}date;

// arrays
client customer[1];
// Variables Globales 
int nbr_client = 0;
// =====>  Le Menu et les sous menus
void creation_profile()
{
    int b_creer;
    do 
    {
    printf("\n\n======= Creation du compte ======= \n\n");
    printf("1 . Creer un profile \n");
    printf("0 . Retour au menu principale \n\n");
    printf("Veuillez saisir un choix  :  ");
    scanf("%d",&b_creer);

    switch (b_creer)
    {
    case 1:
    printf("Veuillez saisir votre nom :\n");
    scanf("%s",customer[nbr_client].nom);
    printf("Veuillez saisir votre prenom :\n");
    scanf("%s",customer[nbr_client].prenom);
    char temp_email[MAX_SIZE];
    sprintf(temp_email, "%s.%s@gmail.com",customer[nbr_client].prenom, customer[nbr_client].nom);
    strcpy(customer[nbr_client].email, temp_email);
    customer[nbr_client].id_client= nbr_client+1;
    nbr_client++;
    break;
    case 0:
    break;
    default:
        break;
    }
    }
    while(b_creer!= 0);
}
void gestion_profile()
{
    int button_gestion;
    if(nbr_client == 0)
    {
        creation_profile();
    }
    else 
    {
        do
        {
            printf("======== La Gestion du Profil Client ========\n\n");
            printf("\n1 . Modifier le profile \n");
            printf("2 . Consulter le profile \n");
            printf("0 . Retour au menu principale\n");
            printf("\nVeuillez saisir un choix : ");
            scanf("%d",&button_gestion);

            switch(button_gestion)
            {
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 0:
                break;
                default :
                printf("Veuillez sasir un choix valid\n");
            }
        }
    while(button_gestion != 0);
    }
}

void gest_solde()
{
    int button_solde;
    do
    {
        printf("\n========= La Gestion du Solde Virtuel =========\n\n");
        printf("1 . Consulter votre solde \n");
        printf("2 . Depot d'argent\n");
        printf("3 . Historique des transactions \n");
        printf("0 . Quitter ce Menu\n");
        printf("\n\nVeuillez sasir un choix :\n");
        scanf("%d",&button_solde);

        switch(button_solde)
        {
            case 1 :
            break;
            case 2:
            break;
            case 3:
            break;
            case 0:
            break;
            default :
            printf("Veuillez saisir un valide choix\n");
        }
    }
    while(button_solde != 0);
}

void catalogue_prod()
{
    int button_catalogue;
    do
    {
        printf("\n========= La Catalogue des Produits =========\n\n");
        printf("1 . Afficher le catalogue \n");
        printf("2 . Rechercher un produit \n");
        printf("3 . Afficher les statistique des produits \n"); // west hadi khassni ndir recherche par category w recherche par prix
        printf("4 . Details d'un produit \n");
        printf("5 . Produits predefinies \n");
        printf("0 . Quitter ce Menu\n\n");
        printf("\n\nVeuillez sasir un choix :\n");
        scanf("%d",&button_catalogue);

        switch(button_catalogue)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 0:
            break;
            default:
            printf("Veuillez saisir un valide choix \n");
        }
    }
    while(button_catalogue != 0);
}

void effectuer_achat()
{
    int button_achat;
    do
    {
        printf("\n========= Le Processus d'Achat =========\n\n");
        printf("1 . Acheter un produit\n");
        printf("2 . Voir le panier actuel\n");
        printf("3 . Vider le panier\n");
        printf("4 . Procéder au paiement\n");
        printf("5 . Historique des achats\n");
        printf("0 . Retour au menu principal\n\n");
        printf("\n\nVeuillez sasir un choix :\n");
        scanf("%d",&button_achat);

        switch(button_achat)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 0:
            break;
            default:
            printf("Veuillez sairi un valide choix \n");
        }
    }
    while(button_achat != 0);
}

void afficher_stat()
{
    int button_stat;
    do
    {
        printf("\n========= Mes statistiques =========\n\n");
        printf("1 . Statistiques generales\n");
        printf("2 . Depenses par categorie\n");
        printf("3 . Produits les plus achetes\n");
        printf("0 . Retour au menu principal\n\n");
        printf("Votre choix: ");
        scanf("%d",&button_stat);

        switch(button_stat)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 0:
            break;
            default:
            printf("Veuillez sairi un valide choix \n");
        }
    }
    while(button_stat != 0);
}

void menu_principale()
{
    int button_menu;
    do
    {
        printf("\n======= Systeme d'achat client =======\n\n");
        printf("1. Gestion du profil client\n");
        printf("2. Gestion du solde virtuel\n");
        printf("3. Consultation des produits\n");
        printf("4. Effectuer un achat\n");
        printf("5. Mes statistiques\n");
        printf("0. Quitter l'application\n\n");
        printf("Veuillez saisir votre choix : ");
        scanf("%d",&button_menu);

    switch (button_menu)
    {
        case 1:
        gestion_profile();
        break;
        case 2:
        gest_solde();
        break;
        case 3:
        catalogue_prod();
        break;
        case 4:
        effectuer_achat();
        break;
        case 5:
        afficher_stat();
        break;
        case 0:
        printf("\nMerci a vous cher client \nA bientot \n");
        break;
        default:
        printf("Veuillez saisir un valide choix entre 0 et 5 : \n");
        }
    }
    while(button_menu != 0);
}

int main(void)
{
    int b1;
    menu_principale();

    return 0;
}
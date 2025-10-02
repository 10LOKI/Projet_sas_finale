// transaction mou7al ndirha
// khass nkemel despenses par categorie w les produits les plus achetes
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
// structures
typedef struct {
    int id_client;
    char nom[MAX_SIZE];
    char prenom[MAX_SIZE];
    char email[MAX_SIZE];
    float solde;
} client;
typedef struct {
    int id_produit;
    char nom_produit[MAX_SIZE];
    char categorie[MAX_SIZE];
    char description[MAX_SIZE];
    float prix;
    int stock;
} produit;
// arrays
client customer[1];
produit prod[MAX_SIZE] = {
    {1,"Casque","electronics","Casque audio haute qualite",799.00,5},
    {2,"Smartphone","electronics","telephone intelligent derniere genere",499.00,10},
    {3,"Parfum","beauty","Fragrance elegante et persistante",89.00,15},
    {4,"Echarpe DOSEI","beauty","echape legere style parisien",25.00,20},
    {5,"Cupcakes","food","delicieux cupcakes faits maison",45.00,12},
    {6,"Yoga","sports","Mat confortable pour yoga",29.99,8},
    {7,"Lamp","home","lumiere douce pour ambiance",45.50,15},
    {8,"Novelt","books","Roman passionnant best-seller",13.99,25},
    {9,"Board","sports","Jeu de societe familial",49.95,12},
    {10,"Watering","garden","Arrosoir pratique jardin exterieur",19.75,30}
};
// Variables Globales
int nbr_client = 0;
int nbr_produits = 10;
// =====>  Le Menu et les sous menus
void creation_profile() {
    printf("\n\nVeuillez s'inscrire dabord \n");
    int b_creer;
    printf("\n\n======= Creation du compte ======= \n\n");
    printf("1 . Creer un profile \n");
    printf("0 . Retour au menu principale \n\n");
    printf("Veuillez saisir un choix  :  ");
    scanf("%d", &b_creer);
    switch (b_creer)
    {
    case 1:
        printf("Veuillez saisir votre nom :\n");
        scanf("%s", customer[nbr_client].nom);
        printf("Veuillez saisir votre prenom :\n");
        scanf("%s", customer[nbr_client].prenom);
        customer[nbr_client].id_client = nbr_client + 66;
        char temp_email[MAX_SIZE];
        strcpy(temp_email, customer[nbr_client].prenom);
        strcat(temp_email, customer[nbr_client].nom);
        strcat(temp_email, "@gmail.com");
        strcpy(customer[nbr_client].email, temp_email);
        printf("votre adresse email est %s\n", customer[nbr_client].email);
        printf("Votre ID est %d", customer[nbr_client].id_client);
        nbr_client++;
        break;
    case 0:
        printf("Retour au menu \n\n");
        break;
    default:
        printf("choix invalid il faut ressayer\n");
        break;
    }
}
void modifier_profile() {
    printf("\n======= Modification du profile =======\n");
    printf("\n\nNouveau nom : ");
    scanf("%s",customer[nbr_client-1].nom);
    printf("Nouveau prenom : ");
    scanf("%s",customer[nbr_client-1].prenom);
    char temp_email[MAX_SIZE];
    strcpy(temp_email, customer[nbr_client-1].prenom);
    strcat(temp_email, customer[nbr_client-1].nom);
    strcat(temp_email, "@gmail.com");
    strcpy(customer[nbr_client-1].email,temp_email);
    printf("votre adresse email est %s\n",customer[nbr_client-1].email);
    printf("Modification de profile a ete avec succes\n");
}
void consulte_profile() {
    for (int i = 0; i < nbr_client; i++) {
        printf("\n\n========= Les information du client d'ID %d\n", i+1);
        printf("Prenom : %s\n", customer[i].prenom);
        printf("Nom : %s\n", customer[i].nom);
        printf("Email : %s\n", customer[i].email);
        printf("solde : %.2f DH\n", customer[i].solde);
    }
}
void gestion_profile() {
    int button_gestion;
    if (nbr_client == 0) {
        creation_profile();
        if (nbr_client > 0) {
            do {
                printf("\n\n======== La Gestion du Profil Client ========\n\n");
                printf("1 . Modifier le profile \n");
                printf("2 . Consulter le profile \n");
                printf("0 . Retour au menu principale\n");
                printf("\nVeuillez saisir un choix : ");
                scanf("%d", &button_gestion);

                switch (button_gestion) {
                case 1:
                    modifier_profile();
                    break;
                case 2:
                    consulte_profile();
                    break;
                case 0:
                    printf("Retour a menu principale \n");
                    break;
                default:
                    printf("Veuillez saisir un choix valide\n");
                }
            } while (button_gestion != 0);
        }
    }
    else {
        do {
            printf("======== La Gestion du Profil Client ========\n\n");
            printf("\n1 . Modifier le profile \n");
            printf("2 . Consulter le profile \n");
            printf("0 . Retour au menu principale\n");
            printf("\nVeuillez saisir un choix : ");
            scanf("%d", &button_gestion);

            switch (button_gestion) {
            case 1:
                modifier_profile();
                break;
            case 2:
                consulte_profile();
                break;
            case 0:
                printf("Retour a menu principale \n");
                break;
            default:
                printf("Veuillez saisir un choix valide\n");
            }
        } while (button_gestion != 0);
    }
}

void consult_solde() {
    printf("\n\n======= Consultation du Solde =======\n");
    printf("\n\n=======Solde Actuelle========\n");
    printf("Client d'ID %d\n", customer[nbr_client-1].id_client);
    printf("Votre solde actuellle est :\n");
    printf("===========> %.2f DH\n", customer[nbr_client-1].solde);
}

void depot_argent() {
    float montant_temp;
    printf("\n\n=======Depot d'argent ========\n");
    printf("Veuillez saisir le montant que vous voulez deposer :\n");
    scanf("%f", &montant_temp);
    customer[nbr_client-1].solde += montant_temp;
    printf("le depot a ete avec succes \n");
}
void historique_trans() {
}
void gest_solde() {
    int button_solde;
    do {
        printf("\n========= La Gestion du Solde Virtuel =========\n\n");
        printf("1 . Consulter votre solde \n");
        printf("2 . Depot d'argent\n");
        printf("3 . Historique des transactions \n");
        printf("0 . Quitter ce Menu\n");
        printf("\n\nVeuillez sasir un choix :\n");
        scanf("%d", &button_solde);

        switch (button_solde) {
        case 1:
            consult_solde();
            break;
        case 2:
            depot_argent();
            break;
        case 3:
            historique_trans();
            break;
        case 0:
            break;
        default:
            printf("Veuillez saisir un valide choix\n");
        }
    } while (button_solde != 0);
}
void affichage_catalogue() {
    printf("\n=========== Liste des produits ==========\n\n");
    for (int i = 0; i < nbr_produits; i++) {
        printf("produit N%d :\n\n", i + 1);
        printf("Nom du produit : %s\n", prod[i].nom_produit);
        printf("Categorie : %s\n", prod[i].categorie);
        printf("le prix : %.2f\n", prod[i].prix);
    }
}
int recherche_par_nom() {
    char nom_temp[MAX_SIZE];
    int trouve = 0;
    int index_trouve = -1;

    if (nbr_produits == 0) {
        printf("y'a pas de produit enregistre.\n");
        return -1;
    }
    printf("Entrez le nom du produit : ");
    scanf("%s", nom_temp);

    for (int i = 0; i < nbr_produits; i++) {
        if (strcmp(prod[i].nom_produit, nom_temp) == 0) {
            printf("\nProduit trouver\n\n");
            printf("ID du produit : %d\n", prod[i].id_produit);
            printf("nom du produit : %s\n", prod[i].nom_produit);
            printf("category du produit  : %s\n", prod[i].categorie);
            printf("Prix du produit : %.2f\n", prod[i].prix);
            trouve = 1;
            index_trouve = i;
            break;
        }
    }
    if (!trouve) {
        printf("Nom non trouvé\n");
        return -1;
    }
    return index_trouve;
}

int recherche_par_categorie() {
    char categorie_temp[MAX_SIZE];
    int trouve = 0;
    int index_trouve = -1;

    if (nbr_produits == 0) {
        printf("y'a pas de produit enregistre.\n");
        return -1;
    }
    printf("Entrez la categorie du produit : ");
    scanf("%s", categorie_temp);

    for (int i = 0; i < nbr_produits; i++) {
        if (strcmp(prod[i].categorie, categorie_temp) == 0) {
            printf("\nProduit trouver\n\n");
            printf("ID du produit : %d\n", prod[i].id_produit);
            printf("nom du produit : %s\n", prod[i].nom_produit);
            printf("category du produit  : %s\n", prod[i].categorie);
            printf("Prix du produit : %.2f\n", prod[i].prix);
            trouve = 1;
            index_trouve = i;
            break;
        }
    }
    if (!trouve) {
        printf("Categorie non trouvé\n");
        return -1;
    }
    return index_trouve;
}

void recherche_prod() {
    int choix;
    do {
        printf("\nVoulez vous rechercher en fonction :\n");
        printf("1 . Nom\n");
        printf("2 . Categorie\n");
        printf("0 . Quitter\n\n");
        printf("Vuillez choisir un choix : ");
        scanf("%d", &choix);
        switch (choix) {
        case 1:
            recherche_par_nom();
            break;
        case 2:
            recherche_par_categorie();
            break;
        case 0:
            printf("Retour au menu principale \n");
            break;
        default:
            printf("Choix Invalide , veuillez saisir un choix valide \n");
        }
    } while (choix != 0);
}
void ordre_croissant()
{
for(int i=0;i<nbr_produits;i++)
{
    produit temp;
    for(int j=0;j<nbr_produits-1;j++)
    {
        if(prod[j].prix > prod[j+1].prix)
        {
            temp = prod[j];
            prod[j] = prod[j+1];
            prod[j+1] = temp;
        }
    }
}
for(int i=0;i<nbr_produits;i++)
{
    printf("%s  : %.2f\n",prod[i].nom_produit,prod[i].prix);
}
}
void ordre_decroissant()
{
for(int i=0;i<nbr_produits;i++)
{ 
    produit temp;
    for(int j=0;j<nbr_produits-1;j++)
    {
        if(prod[j].prix<prod[j+1].prix)
        {
            temp = prod[j];
            prod[j] = prod[j+1];
            prod[j+1] = temp;
        }
    }
}
for(int i=0;i<nbr_produits;i++)
{
    printf("%s  : %.2f\n",prod[i].nom_produit,prod[i].prix);
}
}
void ordre_alphabetique() {
    produit temp;
    produit temp_prod[MAX_SIZE];
    for(int i = 0; i < nbr_produits; i++) {
        temp_prod[i] = prod[i];
    }
    for(int i = 0; i < nbr_produits - 1; i++) {
        for(int j = 0; j < nbr_produits - i - 1; j++) {
            if(strcmp(temp_prod[j].nom_produit,temp_prod[j+1].nom_produit) > 0) {
                temp = temp_prod[j];
                temp_prod[j] = temp_prod[j+1];
                temp_prod[j+1] = temp;
            }
        }
    }
    printf("\n=== Produits par ordre alphabetique ===\n");
    for(int i = 0; i < nbr_produits; i++) {
        printf("%d. %s - %.2f DH\n", i+1, temp_prod[i].nom_produit, temp_prod[i].prix);
    }
}
void statistiques_prod()
{
    int choix;
    do
    {
        printf("\nVoulez vous Trier en fonction de :\n");
        printf("1 . ordre croissant\n");
        printf("2 . ordre decroissant \n");
        printf("3 . ordre alphabetique\n");
        printf("0 . Quitter\n\n");
        printf("Vuillez choisir un choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        ordre_croissant();
        break;
        case 2:
        ordre_decroissant();
        break;
        case 3 :
        ordre_alphabetique();
        break;
        case 0:
        printf("Retour au menu principale \n");
        break;
        default:
        printf("Choix Invalide , veuillez saisir un choix valide \n");
        }
    } while (choix != 0);
}
void details_prod()
{

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
        printf("0 . Quitter ce Menu\n\n");
        printf("\n\nVeuillez sasir un choix :\n");
        scanf("%d", &button_catalogue);

        switch (button_catalogue)
        {
        case 1:
        affichage_catalogue();
        break;
        case 2:
        recherche_prod();
        break;
        case 3:
        statistiques_prod();
        break;
        case 4:
        recherche_par_nom();
        break;
        case 0:
        printf("Retour au menu principale \n");
        break;
        default:
        printf("Veuillez saisir un valide choix \n");
        }
    } while (button_catalogue != 0);
}
/*
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
        printf("0 . Retour au menu principal\n\n");
        printf("\n\nVeuillez sasir un choix :\n");
        scanf("%d", &button_achat);

        switch (button_achat)
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
    } while (button_achat != 0);
}
    */

void afficher_stat()
{
    int button_stat;
    do
    {
        printf("\n========= Mes statistiques =========\n\n");
        printf("1 . Statistiques des produits\n");
        printf("2 . Depenses par categorie\n");
        printf("3 . Produits les plus achetes\n");
        printf("0 . Retour au menu principal\n\n");
        printf("Votre choix: ");
        scanf("%d", &button_stat);

        switch (button_stat)
        {
        case 1:
        statistiques_prod();
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
    } while (button_stat != 0);
}
void choisir_produit(){
    printf("\n=========== Liste des produits ==========\n\n");
    char nom_temp[nbr_produits];
    for (int i = 0; i < nbr_produits; i++)
    {
        printf("Nom du produit : %s\n", prod[i].nom_produit);
        printf("Categorie : %s\n", prod[i].categorie);
        printf("le prix : %.2f DH\n", prod[i].prix);
    }
    printf("Veuillez saisir le nom du produit que vous voulez acheter : ");
    scanf("%s", nom_temp);

    int trouve = 0;
    for (int i = 0; i < nbr_produits; i++)
        {
            if (strcmp(prod[i].nom_produit, nom_temp) == 0)
            {
                printf("\nProduit trouver\n\n");
                printf("ID du produit : %d\n",prod[i].id_produit);
                printf("nom du produit : %s\n",prod[i].nom_produit);
                printf("category du produit  : %s\n",prod[i].categorie);
                printf("Prix du produit : %.2f\n",prod[i].prix);
                printf("Stock du produit : %d\n",prod[i].stock);
                printf("Description du produit : %s\n",prod[i].description);
                trouve = 1;
                break;
            }
        }
    if(trouve != 1){
        printf("Produit n'est pas trouve \n");
    }
}
void effectuer_paiement(){
    printf("\n=========== paiement ==========\n\n");
    
    char nom_produit[nbr_produits];
    int quantite;
    float montant_total = 0;
    
    printf("Veuillez saisir le nom du produit a payer : ");
    scanf("%s", nom_produit);
    int index = -1;
    for (int i = 0; i < nbr_produits; i++) {
        if (strcmp(prod[i].nom_produit, nom_produit) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("produit n'est pas trouve\n");
        return;
    }
    printf("quantite que tu souhaite : ");
    scanf("%d", &quantite);
    if (quantite > prod[index].stock) {
        printf("stock n'est pas suffisant (stock est %d)\n", prod[index].stock);
        return;
    }
    if (quantite <= 0) {
        printf("Quantite invalide\n");
        return;
    }
    montant_total = quantite*prod[index].prix;
    printf("\nbillet de la commande \n");
    printf("Produit : %s\n", prod[index].nom_produit);
    printf("prix unitaire : %.2f DH\n", prod[index].prix);
    printf("quantite : %d\n", quantite);
    prod[index].stock -= quantite;
    printf("Montant total : %.2f DH\n", montant_total);
    customer[0].solde -= montant_total;

    printf("\n\nPAiement effectue avec succes \n");
}
void achat_effec()
{
    int button_achat;
    do
    {
        printf("\n======= Processus d'Achat =======\n\n");
        printf("1. Choisir un produit \n");
        printf("2. Effectuer le paiement \n");
        printf("0. Quitter l'application\n\n");
        printf("Veuillez saisir votre choix : ");
        scanf("%d", &button_achat);

        switch (button_achat)
        {
        case 1:
            choisir_produit();
            break;
        case 2:
            effectuer_paiement();
            break;
        case 0:
            printf("\nMerci a vous cher client \nA bientot \n");
            break;
        default:
            printf("Veuillez saisir un valide choix entre 0 et 2 : \n");
        }
    } while (button_achat != 0);
}
void depenses_par_categorie() {
   
}
void statistiques() {
    int button_stats;
    do {
        printf("\n======= Statistiques Avancées =======\n\n");
        printf("1. Dépenses par catégorie\n");
        printf("2. Produits les plus achetés\n");
        printf("3. Statistiques des produits\n");
        printf("4. Solde moyen des clients\n");
        printf("0. Retour au menu principal\n");
        printf("\nVeuillez saisir un choix : ");
        scanf("%d", &button_stats);

        switch (button_stats) {
            case 1:
                depenses_par_categorie();
                break;
            case 2:
                printf("\n=== Produits les plus achetés ===\n");
                printf("Fonctionnalité en développement...\n");
                // Ici vous pouvez trier les produits par nombre d'achats
                break;
            case 3:
                statistiques_prod(); // Utilise la fonction existante
                break;
            case 4:
                printf("\n=== Solde moyen des clients ===\n");
                if (nbr_client == 0) {
                    printf("Aucun client enregistré.\n");
                } else {
                    float total_solde = 0;
                    for (int i = 0; i < nbr_client; i++) {
                        total_solde += customer[i].solde;
                    }
                    printf("Solde moyen: %.2f DH\n", total_solde / nbr_client);
                    printf("Nombre total de clients: %d\n", nbr_client);
                }
                break;
            case 0:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide! Veuillez saisir un choix entre 0 et 4.\n");
        }
    } while (button_stats != 0);
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
        scanf("%d", &button_menu);

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
            achat_effec();
            break;
        case 5:
            
            break;
        case 0:
            printf("\nMerci a vous cher client \nA bientot \n");
            break;
        default:
            printf("Veuillez saisir un valide choix entre 0 et 5 : \n");
        }
    } while (button_menu != 0);
}

int main(void) {
    int b1;
    menu_principale();
    return 0;
}
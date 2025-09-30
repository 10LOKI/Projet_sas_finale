#include <stdio.h>


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
    while(button_menu != 0);
}
int main(void)
{
    int b1;
    menu_principale();

    return 0;
}
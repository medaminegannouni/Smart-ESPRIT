
#include<gtk/gtk.h>
typedef struct menu
{
char id[20];
char type[20];//bouton radio petit dej deuj dinnee
char ingred[20];//case à cocher viande legume fruit produit laitier
char etat[20];//combo plat principale dessert ou entree
char qut[20];//spinbutton
}menu;
void ajout_menu(menu m);
void affiche_menu(GtkWidget *liste);
void modifier_menu(menu m);
void suprimer_menu(menu m);
int chercher_menu(menu m);

 


#include<gtk/gtk.h>
typedef struct menu
{
char id[200];
char type[200];//bouton radio petit dej deuj dinnee
char ingred[200];//case à cocher viande legume fruit produit laitier
char etat[200];//combo plat principale dessert ou entree
char qut[200];//spinbutton
}menu;
void ajout_menu(menu m);
void affiche_menu(GtkWidget *liste);
void modifier_menu(menu m);
void suprimer_menu(menu m,char ch1[]);
menu chercher_menu(char ch1[]);

 

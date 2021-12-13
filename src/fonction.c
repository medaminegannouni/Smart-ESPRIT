
#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
enum
{
	EID,
	ETYPE,
	EINGRED,
	EETAT,
	EQUT,
	COLUMNS,
};
	
void ajout_menu(menu m)
  {
   FILE *f;
  f=fopen("nom.txt","a+");
   if (f!=NULL)
    {

 fprintf(f,"%s %s %s %s %s \n",m.id, m.type , m.ingred , m.etat , m.qut);
 fclose(f);
   }
 
  }

void modifier_menu(menu m)
{
char type[500],ingred[200],etat[200],qut[200];
FILE *f=NULL,*x;
f=fopen("nom.txt","r");
x=fopen("mod.txt","a+");
menu u;
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s \n ",u.id , u.type , u.ingred , u.etat,u.qut)!= EOF)
{
if (strcmp(m.id,u.id)==0)
{
fprintf(x,"%s %s %s %s %s \n ",m.id , m.type , m.ingred , m.etat,m.qut) ;
}
else
{
fprintf(x,"%s %s %s %s %s \n ",u.id , u.type , u.ingred ,u.etat,u.qut);
}
}
}
fclose(x);
fclose(f);
remove("nom.txt");
rename("mod.txt","nom.txt");
}
void affiche_menu(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[20];
	char type[20];//bouton radio petit dej deuj dinnee
	char ingred[20];//case à cocher viande legume fruit produit laitier
	char etat[20];//combo plat principale dessert ou entree
	char qut[20];//spinbutton
store= NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" ingred",renderer,"text",EINGRED,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" etat",renderer,"text",EETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" qut",renderer,"text",EQUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

  f=fopen("nom.txt","r");
   if (f==NULL)
   {
return;
}
else
{
f=fopen("nom.txt","a+");
while (fscanf(f,"%s %s %s %s %s\n",id,type,ingred,etat,qut)!= EOF)
    {
	gtk_list_store_append(store,&iter);
	gtk_list_store_set (store,&iter,EID,id,ETYPE,type,EINGRED,ingred,EETAT,etat,EQUT,qut,-1);

    
   }
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) ,GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}
void suprimer_menu( menu m ,char ch1[200])
{ char type[500],ingred[200],etat[200],qut[200];
FILE *f=NULL;
FILE *x=NULL ;
f=fopen("nom.txt","r");
x=fopen("mod.txt","a");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s \n ",m.id , m.type , m.ingred , m.etat,m.qut)!= EOF)
{
if (strcmp(ch1,m.id)!=0)
{
fprintf(x,"%s %s %s %s %s \n ",m.id , m.type , m.ingred , m.etat,m.qut) ;
}
}
}
fclose(x);
fclose(f);

remove("nom.txt");
rename("mod.txt","nom.txt");
}

menu chercher_menu (char ch1[])
{int trouve=0;
menu m1;
 //char ch1[200];
FILE *f=NULL;
f=fopen("nom.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s \n",m1.id,m1.type,m1.ingred,m1.etat,m1.qut)!= EOF)
{if (strcmp(m1.id,ch1)==0)
{

fclose(f);
return m1;

}

/*else
{
strcpy(m1.type,"introuvable");
strcpy(m1.ingred,"introuvable");
strcpy(m1.etat,"introuvable");
strcpy(m1.qut,"introuvable");
return m1;
}*/
}

}
}



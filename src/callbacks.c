#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int choix;
int t[9]={0,0,0,0,0,0,0,0,0};

void
on_button_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *first, *modifier;
first=lookup_widget(objet,"first");  
gtk_widget_destroy(first);
modifier=create_modifier();
gtk_widget_show(modifier);

}

void
on_button_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *ajout;
first=lookup_widget(objet,"first");  //first --> ajout
gtk_widget_destroy(first);
ajout=create_ajout();
gtk_widget_show(ajout);
}


void
on_button_sup_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *first, *sup;
first=lookup_widget(objet,"first"); 
gtk_widget_destroy(first);
sup=create_sup();
gtk_widget_show(sup);                                    
}                                     


void
on_button_app_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)


{
GtkWidget *entry_idmod;
GtkWidget *modifier;
GtkWidget *spinbutton1;
GtkWidget *comboboxentry1;
int x;
menu m;
char ch1[22];
modifier=lookup_widget(objet,"modifier");
entry_idmod=lookup_widget(objet,"entry_idmod");
strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(entry_idmod)));
strcpy(ch1,m.id);
if(choix==0)

strcpy(m.type,"petit_dejeuner");
else 
if(choix==1)
strcpy(m.type,"dejeuner");
else
if(choix==2)
strcpy(m.type,"diner");
if (t[0]==1)
strcpy(m.ingred," lait");
else 

if (t[1]==1)
strcpy(m.ingred,"jus");
else
if (t[2]==1)
strcpy(m.ingred,"viande");
else 
if (t[3]==1)
strcpy(m.ingred,"poisson");
else 
if (t[4]==1)
strcpy(m.ingred,"céreale");
else 
if (t[5]==1)
strcpy(m.ingred,"fruit");
else 
if (t[6]==1)
strcpy(m.ingred,"poulet");
else 
if (t[7]==1)
strcpy(m.ingred,"pate");
else 
if (t[8]==1)
strcpy(m.ingred,"salade");
comboboxentry1=lookup_widget(objet,"comboboxentry1");
spinbutton1=lookup_widget(objet,"spinbutton1");
strcpy(m.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
sprintf(m.qut,"%d",x);
//modifier_menu(ch1,m);
ajout_menu(m);


}


void
on_button_supp_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry3;
menu m;
char ch1[20];
entry3=lookup_widget(objet,"entry3");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(entry3)));
suprimer_menu(m,ch1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* type;
gchar* ingred;
gchar* etat; 
gchar* qut;
//char  ch1[200];
menu m;
GtkTreeModel *model = gtk_tree_view_get_model(treeview1);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&type,2,&ingred,3,&etat,4,&qut,-1);
strcpy(m.id,id);
strcpy(m.type,type);
strcpy(m.ingred,ingred);
strcpy(m.etat,etat);
strcpy(m.qut,qut);
//suprimer_menu(m,ch1);
affiche_menu(treeview1);
} 

}




void
on_affiche_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first; 
GtkWidget *treeview1;
first=lookup_widget(objet,"first");
treeview1=lookup_widget(first,"treeview1");
affiche_menu(treeview1);
}


void
on_button_ret_aff_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *affichage;
affichage=lookup_widget(objet,"affichage");
gtk_widget_destroy(affichage);
first=create_first();
gtk_widget_show(first);
}


void
on_ret_ajout_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *ajout;
ajout=lookup_widget(objet,"ajout");  
gtk_widget_destroy(ajout);
first=create_first();
gtk_widget_show(first);
}


void
on_ret_mod_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *modifier;
modifier=lookup_widget(objet,"modifier");  
gtk_widget_destroy(modifier);
first=create_first();
gtk_widget_show(first);
}


void
on_ret_sup_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *sup;
sup=lookup_widget(objet,"sup");  
gtk_widget_destroy(sup);
first=create_first();
gtk_widget_show(first);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix=0;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix=1;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix=2;
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[0]=1;
}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[1]=1;
}
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[2]=1;
}
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[3]=1;
}
}


void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[4]=1;
}
}


void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[5]=1;
}
}


void
on_button_appajout_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
menu m;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *ajout;
ajout=lookup_widget(objet,"ajout");
input1=lookup_widget(objet,"input1");
input2=lookup_widget(objet,"input2");
input3=lookup_widget(objet,"input3");
input4=lookup_widget(objet,"input4");
input5=lookup_widget(objet,"input5");
strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.type,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.ingred,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(m.etat,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(m.qut,gtk_entry_get_text(GTK_ENTRY(input5)));
//ajout_menu(m);
modifier_menu(m);
}


void
on_recherche_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
char ch1[30];
menu m;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
output1=lookup_widget(objet,"type");
output2=lookup_widget(objet,"ingred");
output3=lookup_widget(objet,"etat");
output4=lookup_widget(objet,"qut");
GtkWidget *entry_recherche;
entry_recherche=lookup_widget(objet,"entry_recherche");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(entry_recherche)));
m=chercher_menu (ch1);
gtk_label_set_text(GTK_LABEL(output1),m.type);
gtk_label_set_text(GTK_LABEL(output2),m.ingred);
gtk_label_set_text(GTK_LABEL(output3),m.etat);
gtk_label_set_text(GTK_LABEL(output4),m.qut);

}


void
on_checkbutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[7]=1;
}
}

void
on_checkbutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[8]=1;
}
}


void
on_checkbutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
t[6]=1;
}
}


void
on_best_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *first, *best;
best=lookup_widget(objet,"best"); 
gtk_widget_destroy(best);
best=create_best();
gtk_widget_show(best);                

}


void
on_ret_bestt_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *first, *best;
best=lookup_widget(objet,"best");  
gtk_widget_destroy(best);
first=create_first();
gtk_widget_show(first);
}


#include "mini_projet.h"

int total;
double total_with_penalties;
char carburant[MAX];
char puissance[MAX];

void on_retour2_clicked(GtkButton *button, gpointer user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    GtkTextIter start, end;

    gtk_stack_set_visible_child_name(stack, "page2_2");
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    gtk_text_buffer_delete(buffer, &start, &end);
}

void on_payer_clicked(GtkButton *button, gpointer user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    //get_assurance_info();


    if (valid)
    {

        gtk_stack_set_visible_child_name(stack, "page2_4");
        afficher_recu();
    }
    else
    {
        gtk_label_set_label(GTK_LABEL(error_info), "Vos informations sont incorrectes. Cliquez sur retour pour les corriger.");
    }
    //gtk_stack_set_visible_child_name(stack, "page2_4");
}

void on_menu_clicked(GtkButton *button, gpointer *user_data)
{

    GtkStack *stack = GTK_STACK(user_data);
    GtkTextIter start, end;

    gtk_stack_set_visible_child_name(stack, "page1");

    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(cin_entry), "");
    gtk_entry_set_text(GTK_ENTRY(ville_entry), "");
    gtk_entry_set_text(GTK_ENTRY(matricule_entry), "");
    gtk_entry_set_text(GTK_ENTRY(puissance_entry), "");
    gtk_entry_set_text(GTK_ENTRY(marque_entry), "");
    gtk_entry_set_text(GTK_ENTRY(date_entry), "");
    gtk_entry_set_text(GTK_ENTRY(matricule_entry_), "");
    gtk_entry_set_text(GTK_ENTRY(puissance_entry_), "");


    gtk_label_set_text(GTK_LABEL(nom_error), "");
    gtk_label_set_text(GTK_LABEL(prenom_error), "");
    gtk_label_set_text(GTK_LABEL(cin_error), "");
    gtk_label_set_text(GTK_LABEL(ville_error), "");
    gtk_label_set_text(GTK_LABEL(date_error), "");
    gtk_label_set_text(GTK_LABEL(marque_error), "");
    gtk_label_set_text(GTK_LABEL(matricule_error), "");
    gtk_label_set_text(GTK_LABEL(puissance_error), "");
    gtk_label_set_text(GTK_LABEL(puissance_error_), "");

    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    gtk_text_buffer_delete(buffer, &start, &end);

    gtk_text_buffer_get_start_iter(buffer_v, &start);
    gtk_text_buffer_get_end_iter(buffer_v, &end);
    gtk_text_buffer_delete(buffer_v, &start, &end);

}

int test(char *matricule){
    int m=0;
    info_v_file = malloc(sizeof(VIGNETTE_INFO));
    FILE *fichier = fopen("vignette.txt", "r");

    if (info_v_file == NULL) return 0;

    if(fichier!=NULL)
    {

        printf("le fichier existe\n");
        while (fscanf(fichier,"%s %s %s \n", info_v_file->nom, info_v_file->prenom, info_v_file->matricule)!=EOF)
        {

            if(strcmp(info_v_file->matricule, matricule) == 0)
            {
                m=1;
                break;
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("ce fichier n\'existe pas\n");

    }
    return m;
}

void on_rechercher_clicked(GtkButton *button, gpointer *user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    gchar *matricule_v = gtk_entry_get_text(matricule_entry_);

    strcpy(puissance, gtk_entry_get_text(puissance_entry_));
    if (test(matricule_v))
    {
        if (gtk_toggle_button_get_active(diesel))
        {
            strcpy(carburant, "Diesel");
            total = total_vignette1("Diesel", atoi(gtk_entry_get_text(puissance_entry_)));
            gtk_stack_set_visible_child_name(stack, "page3_2");
        }
        else if (gtk_toggle_button_get_active(essence))
        {
            strcpy(carburant, "Essence");
            total = total_vignette1("Essence", atoi(gtk_entry_get_text(puissance_entry_)));
            gtk_stack_set_visible_child_name(stack, "page3_2");
        }
        else
            gtk_label_set_text(GTK_LABEL(error_label), "vous n'avez pas de vignette");

    }
    else
    {
        gtk_label_set_text(GTK_LABEL(error_label), "Matricule n'est pas valide");
    }
    write_personal_v_info(buffer_v);
}

void on_month_selected(GtkEntry *widget, gpointer data) {
    gchar *selected_month = g_strdup(gtk_entry_get_text(GTK_ENTRY(widget)));
    total_with_penalties = calculate_total(total, selected_month);
    char total_str[20];

    sprintf(total_str, "%.2f", total_with_penalties);
    gtk_label_set_text(GTK_LABEL(resultat_label), total_str);
}

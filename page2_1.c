#include "mini_projet.h"
void on_entry_activate(GtkEntry *entry, gpointer user_data)
{
    // Check if the entry parameter is a valid GtkEntry widget
    if (!GTK_IS_ENTRY(entry)) {
        // If it's not a valid GtkEntry widget, print an error message and return
        g_warning("on_entry_activate: Invalid entry parameter");
        return;
    }

    // Now we know that entry is a valid GtkEntry widget
    const gchar *text = gtk_entry_get_text(entry);
    GtkWidget *label = GTK_WIDGET(user_data);

    if (strlen(text) == 0)
    {
        gtk_label_set_text(GTK_LABEL(label), "Ce champ est obligatoire");
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(label), "");
    }

    /*gboolean entries_filled = are_entries_filled(nom_entry, ville_entry, cin_entry, prenom_entry);

    gtk_widget_set_sensitive(suivant_button, entries_filled); */
}

void on_suivant_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    gchar *text1 = gtk_entry_get_text(nom_entry);
    gchar *text2 = gtk_entry_get_text(prenom_entry);
    gchar *text3 = gtk_entry_get_text(cin_entry);


    if (strlen(text1) == 0 && strlen(text2) == 0 && strlen(text3) == 0)
    {
        gtk_label_set_text(GTK_LABEL(nom_error), "Ce champs est obligatoire");
        gtk_label_set_text(GTK_LABEL(prenom_error), "Ce champs est obligatoire");
        gtk_label_set_text(GTK_LABEL(cin_error), "Ce champs est obligatoire");
        gtk_label_set_text(GTK_LABEL(ville_error), "Ce champs est obligatoire");
    }
    else if (strlen(text2) == 0)
        gtk_label_set_text(GTK_LABEL(prenom_error), "Ce champs est obligatoire");
    else if (strlen(text3) == 0)
        gtk_label_set_text(GTK_LABEL(cin_error), "Ce champs est obligatoire");
    else if (strlen(text1) == 0)
        gtk_label_set_text(GTK_LABEL(nom_error), "Ce champs est obligatoire");
    else
        gtk_stack_set_visible_child_name(stack, "page2_2");
}


void on_payer2_clicked(GtkButton *button, gpointer user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    const gchar *label_text = gtk_label_get_text(GTK_LABEL(resultat_label));

    if (label_text != NULL && strlen(label_text) > 0)
    {
        afficher_recu2();
        gtk_stack_set_visible_child_name(stack, "page3_3");
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(mois_error), "Ce champ est obligatoire");
    }
}

void afficher_recu2() {
    // Get current time
    time_t current_time;
    struct tm *time_info;
    char time_string[50];

    clear_screen();

    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    printf("---------- Recu d'opération ----------\n");
    printf("Date et Heure: %s\n", time_string);
    printf("Nom: %s\n", info_v_file->nom);
    printf("Prénom: %s\n", info_v_file->prenom);
    printf("Matricule: %s\n", info_v_file->matricule);
    printf("la puissance de la voiture: %s\n", puissance);
    printf("le carburant de la voiture %s\n", carburant);
    printf("Montant de la veignette à payer: %.2f DH\n", total_with_penalties);
    printf("Merci pour votre paiement.\n");
    printf("--------------------------------------\n");
}
void write_personal_v_info(GtkTextBuffer *buffer) {
    GtkTextIter iter;

    // Create text tags for formatting
    GtkTextTag *tag_bold_red = gtk_text_buffer_create_tag(buffer, "bold_red",
                                                           "weight", PANGO_WEIGHT_BOLD,
                                                           "foreground", "red",
                                                           NULL);
    GtkTextTag *tag_bold = gtk_text_buffer_create_tag(buffer, "bold",
                                                       "weight", PANGO_WEIGHT_BOLD,
                                                       NULL);
    GtkTextTag *tag_red = gtk_text_buffer_create_tag(buffer, "red",
                                                      "foreground", "red",
                                                      NULL);

    // Get the iter at the end of the buffer
    gtk_text_buffer_get_end_iter(buffer, &iter);

    // Insert and format the text
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "INFORMATIONS PERSONNELLES\n\n", -1, "bold_red", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "Nom Complet:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info_v_file->nom, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, " ", -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info_v_file->prenom, -1, "bold", NULL);

    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nVOTRE VOITURE\n\n", -1, "bold_red", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "Marque: ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->marque, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nPuissance Fiscale:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, puissance, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nCarburant:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, carburant, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nImmatriculation:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info_v_file->matricule, -1, "bold", NULL);
}

void on_retour4_clicked(GtkButton *button, gpointer user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    GtkTextIter start, end;

    gtk_stack_set_visible_child_name(stack, "page3_1");
    gtk_text_buffer_get_start_iter(buffer_v, &start);
    gtk_text_buffer_get_end_iter(buffer_v, &end);
    gtk_text_buffer_delete(buffer_v, &start, &end);
}





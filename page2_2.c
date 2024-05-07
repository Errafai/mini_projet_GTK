#include "mini_projet.h"
GtkWidget *audi, *bmw, *citroen, *dacia, *fiat, *ford, *hyundai, *kia, *mercedes, *nissan, *opel, *peugeot, *renault, *rover, *skoda, *toyota, *volkswagen;
void on_suivant1_clicked(GtkButton *button, gpointer user_data)
{
    GtkWidget *suivant1 = GTK_WIDGET(user_data);
    GtkStack *stack = GTK_STACK(user_data);

    if (are_entries_filled(matricule_entry,date_entry, puissance_entry))
    {
        gtk_widget_set_sensitive(button, TRUE);
        gtk_stack_set_visible_child_name(stack, "page2_3");
        //GET ALL INFORMATION ABOUT USER
        get_assurance_info();
        valid = lire_et_rechercher_coordonnees(info);
        write_personal_info(buffer);

    }
    else
    {
        gtk_widget_set_sensitive(button, FALSE);
    }
}
void on_entry1_activate(GtkEntry *entry, gpointer user_data)
{
    const gchar *text = gtk_entry_get_text(entry);
    GtkWidget *label = GTK_WIDGET(user_data);

    if (strlen(text) == 0)
    {
        gtk_label_set_text(GTK_LABEL(label), "Ce champ est obligatoire");
        gtk_widget_set_sensitive(suivant1, FALSE);
    }
    else
    {
        gtk_widget_set_sensitive(suivant1, TRUE);
        gtk_label_set_text(GTK_LABEL(label), "");
    }
}

void on_retour1_clicked(GtkButton *button, gpointer user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page2_1");
}
void on_combo_box_text_changed(GtkComboBoxText *widget, gpointer user_data) {
    g_print("Selected item changed\n");
}

void write_personal_info(GtkTextBuffer *buffer) {
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
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->nom, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, " ", -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->prenom, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nVille:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->ville, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nC.I.N :  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->cin, -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\tNuméro De Téléphone: 0645454565\n", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\tDate D’obtention Du Permis: 05/04/2024\n", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\tDate De Naissance: 01/04/2008\n", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\tDurée De Couverture : 12 Mois\n", -1, "bold", NULL);

    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n\nVOTRE VOITURE\n\n", -1, "bold_red", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "Marque:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->marque, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nPuissance Fiscale:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->puissance, -1, "bold", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nImmatriculation:  ", -1, "bold", NULL);
    //gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\t\t\t", -1, NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, info->matricule, -1, "bold", NULL);
}

void on_puissance_activate(GtkEntry *entry, gpointer user_data)
{
    GtkWidget *label = GTK_WIDGET(user_data);

    const gchar *text = gtk_entry_get_text(entry);
    gint puissance = atoi(text);

    // Check if puissance is within the specified range or equal to 0
    if (puissance >= 1 && puissance <= 29) {
        gtk_label_set_text(GTK_LABEL(label), "");
    } else {
        gtk_label_set_text(GTK_LABEL(label), "Entrer une valeur entre 1 et 29");
    }
}

void on_date_activate(GtkEntry *entry, gpointer user_data)
{
    GtkWidget *label = GTK_WIDGET(user_data);
    const gchar *date = gtk_entry_get_text(entry);  // Use pointer to gchar

    // Check if the date is valid using Format_Date_Valide
    bool valid = Format_Date_Valide(date);  // Use bool instead of gboolean

    if (valid) {
        gtk_label_set_text(GTK_LABEL(label), "");
    } else {
        gtk_label_set_text(GTK_LABEL(label), "Ecrire la date sous la forme jj/mm/aaa");
    }
}
void on_marque_button_toggled(GtkRadioButton *radio_button, GtkComboBoxText *combo_box_text) {
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio_button))) {
        const gchar *button_id = gtk_widget_get_name(GTK_WIDGET(radio_button));
        gtk_combo_box_text_remove_all(combo_box_text);
        gtk_combo_box_text_append_text(combo_box_text, button_id);
        gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box_text), 0); // Set the active text
    }
}


void marque_options()
{
    audi = GTK_WIDGET(gtk_builder_get_object(builder, "Audi"));
    gtk_widget_set_name(audi, "Audi");
    g_signal_connect(audi, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    bmw = GTK_WIDGET(gtk_builder_get_object(builder, "BMW"));
    gtk_widget_set_name(bmw, "BMW");
    g_signal_connect(bmw, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    citroen = GTK_WIDGET(gtk_builder_get_object(builder, "Citroën"));
    gtk_widget_set_name(citroen, "Citroën");
    g_signal_connect(citroen, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    fiat = GTK_WIDGET(gtk_builder_get_object(builder, "Fiat"));
    gtk_widget_set_name(fiat, "Fiat");
    g_signal_connect(fiat, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    ford = GTK_WIDGET(gtk_builder_get_object(builder, "Ford"));
    gtk_widget_set_name(ford, "Ford");
    g_signal_connect(ford, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    hyundai = GTK_WIDGET(gtk_builder_get_object(builder, "Hyundai"));
    gtk_widget_set_name(hyundai, "Hyundai");
    g_signal_connect(hyundai, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    kia = GTK_WIDGET(gtk_builder_get_object(builder, "Kia"));
    gtk_widget_set_name(kia, "Kia");
    g_signal_connect(kia, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    mercedes = GTK_WIDGET(gtk_builder_get_object(builder, "Mercedes"));
    gtk_widget_set_name(mercedes, "Mercedes");
    g_signal_connect(mercedes, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    nissan = GTK_WIDGET(gtk_builder_get_object(builder, "Nissan"));
    gtk_widget_set_name(nissan, "Nissan");
    g_signal_connect(nissan, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    opel = GTK_WIDGET(gtk_builder_get_object(builder, "Opel"));
    gtk_widget_set_name(opel, "Opel");
    g_signal_connect(opel, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    peugeot = GTK_WIDGET(gtk_builder_get_object(builder, "Peugeot"));
    gtk_widget_set_name(peugeot, "Peugeot");
    g_signal_connect(peugeot, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    renault = GTK_WIDGET(gtk_builder_get_object(builder, "Renault"));
    gtk_widget_set_name(renault, "Renault");
    g_signal_connect(renault, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    rover = GTK_WIDGET(gtk_builder_get_object(builder, "Rover"));
    gtk_widget_set_name(rover, "Rover");
    g_signal_connect(rover, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    skoda = GTK_WIDGET(gtk_builder_get_object(builder, "Skoda"));
    gtk_widget_set_name(skoda, "Skoda");
    g_signal_connect(skoda, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    toyota = GTK_WIDGET(gtk_builder_get_object(builder, "Toyota"));
    gtk_widget_set_name(toyota, "Toyota");
    g_signal_connect(toyota, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    volkswagen = GTK_WIDGET(gtk_builder_get_object(builder, "Volkswagen"));
    gtk_widget_set_name(volkswagen, "Volkswagen");
    g_signal_connect(volkswagen, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);

    dacia = GTK_WIDGET(gtk_builder_get_object(builder, "Dacia"));
    gtk_widget_set_name(dacia, "Dacia");
    g_signal_connect(dacia, "toggled", G_CALLBACK(on_marque_button_toggled), marque_choser);



}




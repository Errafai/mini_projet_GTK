#include "mini_projet.h"

ASSURANCE_INFO *info;
GtkBuilder *builder;
GtkWidget *window;
GtkWidget *stack;
GtkWidget *page1;
GtkWidget *page2;
GtkWidget *page3;
GtkWidget *assurance;
GtkWidget *vignette;
GtkWidget *quitter;
//variable for page
GtkWidget *nom_error;
GtkWidget *nom_entry;
GtkWidget *nom_label;

GtkWidget *prenom_label;
GtkWidget *prenom_error;
GtkWidget *prenom_entry;

GtkWidget *cin_entry;
GtkWidget *cin_label;
GtkWidget *cin_error;

GtkWidget *ville_choser;
GtkWidget *ville_label;
GtkWidget *ville_error;
GtkWidget *ville_entry;
GtkWidget *ville_list;

GtkWidget *stack1;
GtkWidget *page2_1;
GtkWidget *page2_2;
GtkWidget *suivant_button;

GtkWidget *menu;
GtkWidget *page2_3;
GtkWidget *page2_4;
GtkWidget *retour1;
GtkWidget *retour2;
GtkWidget *suivant1;
GtkWidget *payer;
GtkWidget *retour3;
GtkWidget *radio;

GtkWidget *matricule_entry;
GtkWidget *matricule_label;
GtkWidget *matricule_error;

GtkWidget *police_entry;
GtkWidget *police_label;
GtkWidget *police_error;

GtkWidget *marque_entry;
GtkWidget *marque_label;
GtkWidget *marque_error;
GtkWidget *marque_choser;

GtkWidget *date_entry;
GtkWidget *date_label;
GtkWidget *date_error;

GtkWidget *puissance_entry;
GtkWidget *puissance_label;
GtkWidget *puissance_error;

GtkWidget *diesel;
GtkWidget *essence;
GtkWidget *electrique;
GtkWidget *hybride;

GtkWidget *annee_label;
GtkWidget *annee_error;
GtkWidget *annee_entry;

GtkWidget *matricule_entry_;
GtkWidget *matricule_label_;
GtkWidget *matricule_error_;

GtkWidget *puissance_entry_;
GtkWidget *puissance_label_;
GtkWidget *puissance_error_;

GtkWidget *user_info;
GtkTextBuffer *buffer;

GtkWidget *info_vignette;
GtkTextBuffer *buffer_v;

GtkWidget *somme;
GtkWidget *couverture_choser;
GtkWidget *error_info;

GtkWidget *menu1;
GtkWidget *menu2;
GtkWidget *menu4;
GtkWidget *menu3;
GtkWidget *menu5;
GtkWidget *menu6;
GtkWidget *menu7;

GtkWidget *matricule_entry_;
GtkWidget *matricule_label_;
GtkWidget *matricule_error_;
GtkWidget *rechercher;
GtkWidget *stack2;
GtkWidget *error_label;

GtkComboBoxText *mois_choser;
GtkWidget *resultat_label;
GtkWidget *mois_entry;
GtkWidget *mois_error;

GtkWidget *quitter2;

GtkWidget *quitter3;

GtkWidget *payer2;
GtkWidget *retour4;

int valid;

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "project.glade", NULL);

    //intial base for project
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    stack = GTK_WIDGET(gtk_builder_get_object(builder, "stack"));
    page1 = GTK_WIDGET(gtk_builder_get_object(builder, "page1"));
    page2 = GTK_WIDGET(gtk_builder_get_object(builder, "page2"));
    page3 = GTK_WIDGET(gtk_builder_get_object(builder, "page3"));
    assurance = GTK_WIDGET(gtk_builder_get_object(builder, "assurance"));
    gtk_widget_set_name(assurance, "assurance");
    vignette = GTK_WIDGET(gtk_builder_get_object(builder, "vignette"));
    quitter = GTK_WIDGET(gtk_builder_get_object(builder, "quitter"));
    quitter2 = GTK_WIDGET(gtk_builder_get_object(builder, "quitter2"));
    quitter3 = GTK_WIDGET(gtk_builder_get_object(builder, "quitter3"));

    diesel = GTK_WIDGET(gtk_builder_get_object(builder, "diesel"));
    gtk_widget_set_name(diesel, "radio");
    essence = GTK_WIDGET(gtk_builder_get_object(builder, "essence"));
    gtk_widget_set_name(essence, "radio");
    electrique = GTK_WIDGET(gtk_builder_get_object(builder, "electrique"));
    gtk_widget_set_name(electrique, "radio");
    hybride = GTK_WIDGET(gtk_builder_get_object(builder, "hybride"));
    gtk_widget_set_name(hybride, "radio");

    //secondry widget
    nom_error = GTK_WIDGET(gtk_builder_get_object(builder, "nom_error"));
    nom_entry = GTK_WIDGET(gtk_builder_get_object(builder, "nom_entry"));
    nom_label = GTK_WIDGET(gtk_builder_get_object(builder, "nom_label"));

    prenom_error = GTK_WIDGET(gtk_builder_get_object(builder, "prenom_error"));
    prenom_entry = GTK_WIDGET(gtk_builder_get_object(builder, "prenom_entry"));
    prenom_label = GTK_WIDGET(gtk_builder_get_object(builder, "prenom_label"));

    cin_error = GTK_WIDGET(gtk_builder_get_object(builder, "cin_error"));
    cin_entry = GTK_WIDGET(gtk_builder_get_object(builder, "cin_entry"));
    cin_label = GTK_WIDGET(gtk_builder_get_object(builder, "cin_label"));

    ville_error = GTK_WIDGET(gtk_builder_get_object(builder, "ville_error"));
    ville_entry = GTK_WIDGET(gtk_builder_get_object(builder, "ville_entry"));
    ville_label = GTK_WIDGET(gtk_builder_get_object(builder, "ville_label"));
    ville_choser = GTK_WIDGET(gtk_builder_get_object(builder, "ville_choser"));

    stack1 = GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));
    page2_1 = GTK_WIDGET(gtk_builder_get_object(builder, "page2_1"));
    page2_2 = GTK_WIDGET(gtk_builder_get_object(builder, "page2_2"));
    page2_3  = GTK_WIDGET(gtk_builder_get_object(builder, "page2_3"));
    page2_4 = GTK_WIDGET(gtk_builder_get_object(builder, "page2_4"));



    suivant_button = GTK_WIDGET(gtk_builder_get_object(builder, "suivant_button"));
    gboolean entries_filled = are_entries_filled(nom_entry, cin_entry, prenom_entry);
    gtk_widget_set_sensitive(suivant_button, TRUE);


    retour1 = GTK_WIDGET(gtk_builder_get_object(builder, "retour1"));
    retour2 = GTK_WIDGET(gtk_builder_get_object(builder, "retour2"));
    retour4 = GTK_WIDGET(gtk_builder_get_object(builder, "retour4"));
    suivant1 = GTK_WIDGET(gtk_builder_get_object(builder, "suivant1"));
    gtk_widget_set_sensitive(suivant1, FALSE);

    retour3 = GTK_WIDGET(gtk_builder_get_object(builder, "retour3"));

    matricule_entry = GTK_WIDGET(gtk_builder_get_object(builder, "matricule_entry"));
    matricule_error = GTK_WIDGET(gtk_builder_get_object(builder, "matricule_error"));
    matricule_label = GTK_WIDGET(gtk_builder_get_object(builder, "matricule_label"));


    police_entry = GTK_WIDGET(gtk_builder_get_object(builder, "police_entry"));
    police_error = GTK_WIDGET(gtk_builder_get_object(builder, "police_error"));
    police_label = GTK_WIDGET(gtk_builder_get_object(builder, "police_label"));

    marque_entry = GTK_WIDGET(gtk_builder_get_object(builder, "marque_entry"));
    marque_error = GTK_WIDGET(gtk_builder_get_object(builder, "marque_error"));
    marque_label = GTK_WIDGET(gtk_builder_get_object(builder, "marque_label"));
    marque_choser = GTK_WIDGET(gtk_builder_get_object(builder, "marque_choser"));

    date_entry = GTK_WIDGET(gtk_builder_get_object(builder, "date_entry"));
    date_error = GTK_WIDGET(gtk_builder_get_object(builder, "date_error"));
    date_label = GTK_WIDGET(gtk_builder_get_object(builder, "date_label"));

    puissance_entry = GTK_WIDGET(gtk_builder_get_object(builder, "puissance_entry"));
    puissance_error = GTK_WIDGET(gtk_builder_get_object(builder, "puissance_error"));
    puissance_label = GTK_WIDGET(gtk_builder_get_object(builder, "puissance_label"));

    diesel =  GTK_WIDGET(gtk_builder_get_object(builder, "diesel"));
    essence = GTK_WIDGET(gtk_builder_get_object(builder, "essence"));
    electrique = GTK_WIDGET(gtk_builder_get_object(builder, "electrique"));
    hybride = GTK_WIDGET(gtk_builder_get_object(builder, "hybride"));

    puissance_entry_ = GTK_WIDGET(gtk_builder_get_object(builder, "puissance_entry_"));
    puissance_error_ =  GTK_WIDGET(gtk_builder_get_object(builder, "puissance_error_"));


    somme = GTK_WIDGET(gtk_builder_get_object(builder, "somme"));
    couverture_choser = GTK_WIDGET(gtk_builder_get_object(builder, "couverture_choser"));

    user_info = GTK_WIDGET(gtk_builder_get_object(builder, "user_info"));
    gtk_text_view_set_editable(GTK_TEXT_VIEW(user_info), FALSE);
    gtk_widget_set_name(user_info, "user_info");
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_info));

    info_vignette = GTK_WIDGET(gtk_builder_get_object(builder, "info_vignette"));
    gtk_text_view_set_editable(GTK_TEXT_VIEW(info_vignette), FALSE);
    gtk_widget_set_name(info_vignette, "info_vignette");
    buffer_v = gtk_text_view_get_buffer(GTK_TEXT_VIEW(info_vignette));

    error_info = GTK_WIDGET(gtk_builder_get_object(builder, "error_info"));
    payer = GTK_WIDGET(gtk_builder_get_object(builder, "payer"));

    menu1 = GTK_WIDGET(gtk_builder_get_object(builder, "menu1"));
    menu2 = GTK_WIDGET(gtk_builder_get_object(builder, "menu2"));
    menu3 = GTK_WIDGET(gtk_builder_get_object(builder, "menu3"));
    menu4 = GTK_WIDGET(gtk_builder_get_object(builder, "menu4"));
    menu5 = GTK_WIDGET(gtk_builder_get_object(builder, "menu5"));
    menu6 = GTK_WIDGET(gtk_builder_get_object(builder, "menu6"));
    menu7 = GTK_WIDGET(gtk_builder_get_object(builder, "menu7"));
    gtk_widget_set_name(menu1, "menu");
    gtk_widget_set_name(menu2, "menu");
    gtk_widget_set_name(menu3, "menu");
    gtk_widget_set_name(menu4, "menu");
    gtk_widget_set_name(menu5, "menu");


    rechercher = GTK_WIDGET(gtk_builder_get_object(builder, "rechercher"));
    stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));
    matricule_entry_ = GTK_WIDGET(gtk_builder_get_object(builder, "matricule_entre_"));
    matricule_error_ = GTK_WIDGET(gtk_builder_get_object(builder, "matricule_error_"));
    matricule_label_ = GTK_WIDGET(gtk_builder_get_object(builder, "matricule_label_"));
    error_label = GTK_WIDGET(gtk_builder_get_object(builder, "error_label"));


    mois_choser = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "mois_choser"));
    resultat_label = GTK_WIDGET(gtk_builder_get_object(builder, "resultat_label"));

    mois_entry =  GTK_WIDGET(gtk_builder_get_object(builder, "mois_entry"));
    payer2 = GTK_WIDGET(gtk_builder_get_object(builder, "payer2"));
    mois_error = GTK_WIDGET(gtk_builder_get_object(builder, "mois_error"));

    /*************************maruqe*************************/


    marque_options();
    // Connect signals


    // Connect signals for page1 buttons
    g_signal_connect(assurance, "clicked", G_CALLBACK(on_assurance_clicked), stack);
    g_signal_connect(vignette, "clicked", G_CALLBACK(on_vignette_clicked), stack);
    g_signal_connect(quitter, "clicked", G_CALLBACK(on_quitter_clicked), window);
    g_signal_connect(quitter2, "clicked", G_CALLBACK(on_quitter_clicked), window);
    g_signal_connect(quitter3, "clicked", G_CALLBACK(on_quitter_clicked), window);
    //connect signals for page2_2
    g_signal_connect(nom_entry, "changed", G_CALLBACK(on_entry_activate), nom_error);
    g_signal_connect(prenom_entry, "changed", G_CALLBACK(on_entry_activate), prenom_error);
    g_signal_connect(cin_entry, "changed", G_CALLBACK(on_entry_activate), cin_error);
    g_signal_connect(ville_entry, "changed", G_CALLBACK(on_entry_activate), ville_error);


    g_signal_connect(suivant_button, "clicked", G_CALLBACK(on_suivant_button_clicked), stack1);

    g_signal_connect(suivant1, "clicked", G_CALLBACK(on_suivant1_clicked), stack1);



    g_signal_connect(payer, "clicked", G_CALLBACK(on_payer_clicked), stack1);

    g_signal_connect(retour1, "clicked", G_CALLBACK(on_retour1_clicked), stack1);
    g_signal_connect(retour2, "clicked", G_CALLBACK(on_retour2_clicked), stack1);
    g_signal_connect(retour4, "clicked", G_CALLBACK(on_retour4_clicked), stack2);


    g_signal_connect(matricule_entry, "changed", G_CALLBACK(on_entry1_activate), matricule_error);

    g_signal_connect(date_entry, "changed", G_CALLBACK(on_entry1_activate), date_error);
    g_signal_connect(date_entry, "changed", G_CALLBACK(on_date_activate), date_error);

    g_signal_connect(puissance_entry, "changed", G_CALLBACK(on_entry1_activate), puissance_error);
    g_signal_connect(puissance_entry, "changed", G_CALLBACK(on_puissance_activate), puissance_error);
    g_signal_connect(puissance_entry, "insert-text", G_CALLBACK(on_insert_text), NULL);

    g_signal_connect(marque_entry, "changed", G_CALLBACK(on_entry1_activate), marque_error);
    g_signal_connect(police_entry, "changed", G_CALLBACK(on_entry1_activate), police_error);


    g_signal_connect(ville_choser, "changed", G_CALLBACK(on_combo_box_text_changed), NULL);
    g_signal_connect(marque_choser, "changed", G_CALLBACK(on_combo_box_text_changed), NULL);


    g_signal_connect(diesel, "toggled", G_CALLBACK(on_radio1_toggled), puissance_error_);
    g_signal_connect(essence, "toggled", G_CALLBACK(on_radio1_toggled), puissance_error_);
    g_signal_connect(electrique, "toggled", G_CALLBACK(on_radio2_toggled), puissance_error_);
    g_signal_connect(hybride, "toggled", G_CALLBACK(on_radio2_toggled), puissance_error_);
    g_signal_connect(puissance_entry_, "insert-text", G_CALLBACK(on_insert_text), NULL);

    g_signal_connect(couverture_choser, "changed", G_CALLBACK(afficher_somme), somme);
    g_signal_connect(menu1, "clicked", G_CALLBACK(on_menu_clicked), stack);
    g_signal_connect(menu2, "clicked", G_CALLBACK(on_menu_clicked), stack);
    g_signal_connect(menu4, "clicked", G_CALLBACK(on_menu_clicked), stack);
    g_signal_connect(menu3, "clicked", G_CALLBACK(on_menu_clicked), stack);
    g_signal_connect(menu5, "clicked", G_CALLBACK(on_menu_clicked), stack);
    g_signal_connect(menu6, "clicked", G_CALLBACK(on_menu_clicked), stack);
    g_signal_connect(menu7, "clicked", G_CALLBACK(on_menu_clicked), stack);
    /****************page3***********************/
    g_signal_connect(rechercher, "clicked", G_CALLBACK(on_rechercher_clicked), stack2);
    g_signal_connect(mois_entry, "changed", G_CALLBACK(on_month_selected),NULL);

    g_signal_connect(payer2, "clicked", G_CALLBACK(on_payer2_clicked), stack2);


    //trying css:
    load_css();

    // Apply CSS styling to the button and the box


    gtk_builder_connect_signals(builder, NULL);
    gtk_widget_show_all(window);

    gtk_main();

    g_object_unref(builder);

    return 0;
}

// Callback functions for buttons
void on_assurance_clicked(GtkButton *button, gpointer user_data) {
    GtkStack *stack = GTK_STACK(user_data);
    // Get the child widget (stack1) of stack
    gtk_stack_set_visible_child_name(stack, "page2");
    gtk_stack_set_visible_child_name(stack1, "page2_1");

}

void on_vignette_clicked(GtkButton *button, gpointer user_data) {
    GtkStack *stack = GTK_STACK(user_data);

    gtk_stack_set_visible_child_name(stack, "page3");
    gtk_stack_set_visible_child_name(stack2, "page3_1");
}

void on_quitter_clicked(GtkButton *button, gpointer user_data) {
    GtkWindow *window = GTK_WINDOW(user_data);
    gtk_widget_destroy(GTK_WIDGET(window));
    gtk_main_quit();
}


// Signal connection for the button should be made in the main function or initialization function






void on_retour3_clicked(GtkButton *button, gpointer *user_data)
{
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page2_3");
}


void on_radio2_toggled(GtkRadioButton *togglebutton, gpointer user_data) {
    GtkWidget *label = GTK_WIDGET(user_data);
    if (gtk_toggle_button_get_active(togglebutton)) {

        gtk_label_set_text(GTK_LABEL(label), "0 DH pas de charge");

    }
    gtk_widget_hide(puissance_entry_);

}

void on_radio1_toggled(GtkRadioButton *radio_button, gpointer user_data) {
    GtkWidget *entry = puissance_entry_;// Utilisation de builder pour récupérer l'entry
    GtkWidget *label = GTK_WIDGET(user_data);

    gtk_widget_show(puissance_entry_);
    gtk_label_set_text(label, "");
}


void on_insert_text(GtkEditable *editable, const gchar *text, gint length, gint *position, gpointer user_data) {
    // Validate if the entered text is an integer
    gchar *endptr;
    strtol(text, &endptr, 10); // Try converting the entered text to an integer

    // If the conversion fails or if the entered text is empty, prevent insertion
    if (*endptr != '\0' || *text == '\0') {
        g_signal_stop_emission_by_name(editable, "insert-text");
        gtk_label_set_text(GTK_LABEL(puissance_error_),"Veuillez entrer un nombre ");
    }else{
        gtk_label_set_text(GTK_LABEL(puissance_error_),"");

    }
}





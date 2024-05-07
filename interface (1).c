 /* #include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    GtkWidget *window, *label, *fixed;

    gtk_init(&argc, &argv);

    // Charger le fichier Glade
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "C:/Users/User/Documents/Nouveau dossier/bouton.glade", NULL);

    // Accéder à la fenêtre, au label et au conteneur par leur ID
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    label = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));

    // Vérification des widgets récupérés


    // Définir le texte du label
    gtk_label_set_text(GTK_LABEL(label), "Quel est votre type de carburant ?");

    // Afficher la fenêtre
    gtk_widget_show_all(window);

    // Lancer la boucle principale GTK
    gtk_main();

    return 0;
}*/// "C:/Users/User/Documents/Nouveau dossier/bouton.glade"
#include <gtk/gtk.h>

GtkBuilder *builder ;// Déclaration globale de la variable builder
GtkWidget *entry;
GtkWidget *label4;
// Fonction de gestion de l'événement "toggled" pour les boutons radio "Hybride" et "Electrique"
void on_radio_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    GtkWidget *label2 = GTK_WIDGET(user_data);
    if (gtk_toggle_button_get_active(togglebutton)) {

        gtk_widget_show(label2);

    } else {
        gtk_widget_hide(label2);

    }
    gtk_widget_hide(entry);

}

// Fonction de gestion de l'événement "clicked" pour les boutons radio "Gazoil" et "Essence"
void on_radio_clicked(GtkRadioButton *radio_button, gpointer user_data) {
    GtkWidget *label3 = GTK_WIDGET(user_data);
    GtkWidget *entry = GTK_WIDGET(gtk_builder_get_object(builder, "puissanceentry")); // Utilisation de builder pour récupérer l'entry
    gtk_widget_show_all(label3);
    gtk_widget_show(entry);
}
void on_insert_text(GtkEditable *editable, const gchar *text, gint length, gint *position, gpointer user_data) {
    // Validate if the entered text is an integer
    gchar *endptr;
    strtol(text, &endptr, 10); // Try converting the entered text to an integer

    // If the conversion fails or if the entered text is empty, prevent insertion
    if (*endptr != '\0' || *text == '\0') {
        g_signal_stop_emission_by_name(editable, "insert-text");
        gtk_label_set_text(GTK_LABEL(label4),"Veuillez entrer un nombre ");
    }else{
        gtk_label_set_text(GTK_LABEL(label4)," ");

    }
}
int main(int argc, char *argv[]) {
    GtkWidget *window, *label2, *label3, *radio3, *radio4,*radio1, *radio2;

    gtk_init(&argc, &argv);

    // Charger le fichier Glade
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder,  "C:/Users/User/Documents/Nouveau dossier/bouton.glade", NULL);
    entry=GTK_WIDGET(gtk_builder_get_object(builder, "puissanceentry"));

    // Accéder à la fenêtre, aux labels et aux boutons radio par leur ID
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
    label3 = GTK_WIDGET(gtk_builder_get_object(builder, "label3"));
    radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));
    radio4 = GTK_WIDGET(gtk_builder_get_object(builder, "radio4"));
    radio1 =GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
    radio2 =GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
    label4 =GTK_WIDGET(gtk_builder_get_object(builder, "label4"));
    // Cacher les labels et le champ de saisie au démarrage de l'application
    //gtk_widget_hide(label2);
    //gtk_widget_hide(label3);
    //gtk_widget_hide(GTK_WIDGET(gtk_builder_get_object(builder, "puissanceentry")));

    // Associer les signaux d'événement pour les boutons radio
    g_signal_connect(radio3, "toggled", G_CALLBACK(on_radio_toggled), label2);
    g_signal_connect(radio4, "toggled", G_CALLBACK(on_radio_toggled), label2);
    g_signal_connect(radio1, "toggled", G_CALLBACK(on_radio_clicked), label3);
    g_signal_connect(radio2, "toggled", G_CALLBACK(on_radio_clicked), label3);
    // Connect the "insert-text" signal of the entry widget to the on_insert_text() handler
    g_signal_connect(entry, "insert-text", G_CALLBACK(on_insert_text), NULL);

    // Afficher la fenêtre
    gtk_widget_show_all(window);
    gtk_widget_hide(label2);
    gtk_widget_hide(label3);
    gtk_widget_hide(entry);

    // Lancer la boucle principale GTK
    gtk_main();
    g_object_unref(builder); // Destroy the builder object to free memory
    return 0;
}


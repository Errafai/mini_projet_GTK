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
    // Cacher les labels et le champ de saisie au démarrage de l'application
    //gtk_widget_hide(label2);
    //gtk_widget_hide(label3);
    //gtk_widget_hide(GTK_WIDGET(gtk_builder_get_object(builder, "puissanceentry")));

    // Associer les signaux d'événement pour les boutons radio
    g_signal_connect(radio3, "toggled", G_CALLBACK(on_radio_toggled), label2);
    g_signal_connect(radio4, "toggled", G_CALLBACK(on_radio_toggled), label2);
    g_signal_connect(radio1, "toggled", G_CALLBACK(on_radio_clicked), label3);
    g_signal_connect(radio2, "toggled", G_CALLBACK(on_radio_clicked), label3);

    // Afficher la fenêtre
    gtk_widget_show_all(window);
    gtk_widget_hide(label2);
    gtk_widget_hide(label3);
    gtk_widget_hide(entry);

    // Lancer la boucle principale GTK
    gtk_main();

    return 0;
}

#include "mini_projet.h"
ASSURANCE_INFO *info_file;
VIGNETTE_INFO *info_v_file;
float sum;

gboolean are_entries_filled(GtkEntry *entry1, GtkEntry *entry2, GtkEntry *entry3)
{
    const gchar *text1 = gtk_entry_get_text(entry1);
    const gchar *text2 = gtk_entry_get_text(entry2);
    const gchar *text3 = gtk_entry_get_text(entry3);
    //const gchar *text4 = gtk_entry_get_text(entry4);

    return (strlen(text1) > 0 && strlen(text2) > 0 && strlen(text3) > 0);
    // && strlen(text4) > 0
    //, GtkEntry *entry4)
}

void get_assurance_info() {
    info = malloc(sizeof(ASSURANCE_INFO));
    if (info == NULL) return;

    strcpy(info->nom,g_strdup(gtk_entry_get_text(GTK_ENTRY(nom_entry))));
    strcpy(info->prenom, g_strdup(gtk_entry_get_text(GTK_ENTRY(prenom_entry))));
    strcpy(info->cin, g_strdup(gtk_entry_get_text(GTK_ENTRY(cin_entry))));
    strcpy(info->ville, g_strdup(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ville_choser))));
    strcpy(info->matricule, g_strdup(gtk_entry_get_text(GTK_ENTRY(matricule_entry))));
    strcpy(info->date, g_strdup(gtk_entry_get_text(GTK_ENTRY(date_entry))));
    strcpy(info->marque, g_strdup(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(marque_choser))));
    strcpy(info->puissance,g_strdup(gtk_entry_get_text(GTK_ENTRY(puissance_entry))));
}

 void load_css()
 {
    GtkCssProvider *cssprovider;
    GdkScreen *screen;
    GdkDisplay *display;

    // Path to the CSS file
    GFile *css_file = g_file_new_for_path("style.css");

    // Create a CSS provider
    cssprovider = gtk_css_provider_new();

    // Get the default display and screen
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    // Add the CSS provider to the screen
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(cssprovider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Load CSS from file
    gtk_css_provider_load_from_file(cssprovider, css_file, NULL);
}



bool Format_Date_Valide(const char *date)
{
    int jour, mois, annee;
    char separator;

    // Parsing the date string
    if (sscanf(date, "%d/%d/%d", &jour, &mois, &annee) != 3)
        return false;

    // Vérification des limites des valeurs
    if (jour < 1 || jour > 31 || mois < 1 || mois > 12 || annee < 1960)
        return false;

    // Vérification du nombre de jours pour février
    if (mois == 2 && (jour > 29 || (jour > 28 && annee % 4 != 0)))
        return false;

    // Vérification du nombre de jours pour les mois avec 30 jours
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30)
        return false;

    return true;
}
float calculer_assurance(int poin_puiss, char *choix) {
    float assurance;
    float tableau[2][29]={
        {1214.55 , 1214.55 ,1214.55 , 1214.55 ,1214.55 , 1214.55 ,1473.57 ,1473.57 ,1597.89 ,1597.89 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41 ,2288.41  },
        {2234.66 , 2234.66 ,2234.66 , 2234.66 ,2234.66 , 2234.66 ,2714.35 ,2714.35 ,2944.56 ,2944.56 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32 ,4223.32  }
    };


        if (strcmp("SEMESTRUELLE", choix))
            assurance = tableau[1][poin_puiss+1];
        else
            assurance = tableau[0][poin_puiss+1];

    return assurance ;
}

void afficher_somme(GtkComboBoxText *combo_text, GtkLabel *label)
{
    gchar *choix = gtk_combo_box_text_get_active_text(combo_text);

    sum = calculer_assurance(atol(info->puissance), choix);

    // Convert the sum to a string before setting it as the label text
    gchar *sum_str = g_strdup_printf("%.2f", sum);
    gtk_label_set_text(label, sum_str);

    g_free(choix); // Free the memory allocated by gtk_combo_box_text_get_active_text
    g_free(sum_str); // Free the memory allocated by g_strdup_printf
}
/*ASSURANCE_INFO *create_assurance_info(ASSURANCE_INFO *info_file) {
    info = malloc(sizeof(ASSURANCE_INFO));
    if (info == NULL) {
        perror("Error allocating memory for ASSURANCE_INFO");
        exit(EXIT_FAILURE);
    }
    info->nom = malloc(21 * sizeof(char));
    info->prenom = malloc(21 * sizeof(char));
    info->cin = malloc(9 * sizeof(char));
    info->matricule = malloc(11 * sizeof(char));
    info->date = malloc(14 * sizeof(char));
    info->marque = malloc(11 * sizeof(char));
    if (info->nom == NULL || info->prenom == NULL || info->cin == NULL ||
        info->matricule == NULL || info->date == NULL || info->marque == NULL) {
        perror("Error allocating memory for ASSURANCE_INFO members");
        exit(EXIT_FAILURE);
    }
    return info;
} */


int lire_et_rechercher_coordonnees(ASSURANCE_INFO *info) {
    FILE *fichier = fopen("coordonnees.txt", "r");
    char ligne[1000];
    int found = 0;
    info_file = malloc(sizeof(ASSURANCE_INFO));
    if (!info_file) return 0;


    if (fichier != NULL) {
        printf("file opened successfully\n");
        while (!feof(fichier)) {
            // Assuming the file format is: nom prenom cin ville matricule date marque puissance

            fscanf(fichier, "%s %s %s %s %s %s ", info_file->nom, info_file->prenom, info_file->cin, info_file->matricule, info_file->date, info_file->marque);

            if (strcmp(info_file->cin, info->cin) == 0 &&
                strcmp(info_file->prenom, info->prenom) == 0 &&
                strcmp(info_file->nom, info->nom) == 0 &&
                strcmp(info_file->matricule, info->matricule) == 0 &&
                strcmp(info_file->date, info->date) == 0 &&
                strcmp(info_file->marque, info->marque) == 0)
                {
                printf("founded\n");
                found = 1;
                break;
                }
        }
        fclose(fichier);
        return found; // 1 if found, 0 if not found
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return -1; // Error opening file
    }
}

double calculate_total(double total, const char *selected_month) {
    const char *mois[] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"};

    for (int j = 0; j < 12; ++j) {
        if (strcmp(selected_month, mois[j]) == 0) {
            if (j != 0) {
                total += total * 0.15; // Ajoute des frais de retard
                total += total * 0.005 * (j-1); // Ajoute des frais mensuels de retard
            }
            break;
        }
    }

    return total;
}
void afficher_recu() {
    clear_screen(); // Clear the screen before printing

    // Get current time
    time_t current_time;
    struct tm *local_time;
    char time_buffer[100];

    time(&current_time);
    local_time = localtime(&current_time);

    // Format time into a string
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local_time);

    printf("---------- Recu d'opération ----------\n");
    printf("Date et heure: %s\n", time_buffer); // Print current time and date
    printf("Nom: %s\n", info->nom);
    printf("Prénom: %s\n",  info->prenom);
    printf("Matricule: %s\n", info->matricule);
    printf("CIN: %s\n", info->cin);
    printf("Date d'obtention du permis: %s\n", info->date);
    printf("Marque de la voiture: %s\n", info->marque);
    printf("Montant de l'assurance à payer: %.2f DH\n", sum);
    printf("Merci pour votre paiement.\n");
    printf("--------------------------------------\n");
}
void clear_screen() {
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
    system("clear"); // For Linux/Unix
    #endif
}
int total_vignette1(char carburant[15] ,int puissance){
       int total;
       const int PUISSANCE_MIN[] = {0, 8, 11, 15}; // Tableau des valeurs minimales de puissance pour les deux carburants
       const int SOMME[] = {350, 650, 3000, 8000}; // Tableau des sommes correspondantes pour essence
       const int SOMME1[] = {700, 1500, 6000, 20000}; // Tableau des sommes correspondantes pour gazoil
       if(strcmp(carburant,"Essence")==0){
            for(int i=0;i<4;++i){
                if(puissance<PUISSANCE_MIN[i+1]&&puissance<15){
                    total=SOMME[i];
                    break;}
            else if(puissance>15)
               total=SOMME[3];
            }
       }



       if(strcmp(carburant,"Diesel")==0){
            for(int i=0;i<4;++i){
                if(puissance<PUISSANCE_MIN[i+1]&&puissance<15){
                    total=SOMME1[i];
                break;}
            else if(puissance>15)
               total=SOMME1[3];
            }
       }


    return total;
}


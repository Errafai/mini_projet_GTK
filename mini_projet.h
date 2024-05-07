#ifndef MINI_PROJET_H_INCLUDED
#define MINI_PROJET_H_INCLUDED

/***biblioteque***/

#include <gtk/gtk.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

/****marcos****/

#define MAX 50

/***typedefs***/
typedef struct {
    gchar nom[MAX];
    gchar prenom[MAX];
    gchar cin[MAX];
    gchar ville[MAX];
    gchar matricule[MAX];
    gchar date[MAX];
    gchar marque[MAX];
    gchar puissance[MAX];
} ASSURANCE_INFO;

typedef struct {
    gchar nom[MAX];
    gchar prenom[MAX];
    gchar matricule[MAX];
} VIGNETTE_INFO;

/***fonctions***/
void on_assurance_clicked(GtkButton *button, gpointer user_data);
void on_vignette_clicked(GtkButton *button, gpointer user_data);
void on_quitter_clicked(GtkButton *button, gpointer user_data);
void on_entry_activate(GtkEntry *entry, gpointer user_data);
void on_suivant_button_clicked(GtkButton *button, gpointer user_data);
void on_suivant1_clicked(GtkButton *button, gpointer user_data);
void on_payer_clicked(GtkButton *button, gpointer user_data);
void on_retour1_clicked(GtkButton *button, gpointer user_data);
void on_retour2_clicked(GtkButton *button, gpointer user_data);
gboolean are_entries_filled(GtkEntry *entry1, GtkEntry *entry2, GtkEntry *entry3);
void on_menu_clicked(GtkButton *button, gpointer *user_data);
void on_retour3_clicked(GtkButton *button, gpointer *user_data);
void css_set(GtkCssProvider * cssProvider, GtkWidget *g_widget);
void on_combo_box_text_changed(GtkComboBoxText *widget, gpointer user_data);
void on_entry1_activate(GtkEntry *entry, gpointer user_data);
void load_css();
void on_radio1_toggled(GtkRadioButton *radio_button, gpointer user_data);
void on_radio2_toggled(GtkRadioButton *radio_button, gpointer user_data);
void on_insert_text(GtkEditable *editable, const gchar *text, gint length, gint *position, gpointer user_data);
void write_personal_info(GtkTextBuffer *buffer);

void on_puissance_activate(GtkEntry *entry, gpointer user_data);
void on_retour4_clicked(GtkButton *button, gpointer user_data);

bool Format_Date_Valide(const char *date);
void on_date_activate(GtkEntry *entry, gpointer user_data);
void on_marque_button_toggled(GtkRadioButton *radio_button, GtkComboBoxText *combo_box_text);
float calculer_assurance(int poin_puiss, char *choix);
void afficher_somme(GtkComboBoxText *combo_text, GtkLabel *label);
int lire_et_rechercher_coordonnees();
void free_assurance_info(ASSURANCE_INFO *info);
void marque_options();
void on_rechercher_clicked(GtkButton *button, gpointer *user_data);
int test(char *matricule);

void on_month_selected(GtkEntry *widget, gpointer data);
double calculate_total(double total, const char *selected_month);

void clear_screen();
void afficher_recu();
int total_vignette1(char carburant[15] ,int puissance);
void on_payer2_clicked(GtkButton *button, gpointer user_data);
void afficher_recu2();
void write_personal_v_info(GtkTextBuffer *buffer);


/***variable***/


extern GtkWidget *audi, *bmw, *dacia, *citroen, *fiat, *ford, *hyundai, *kia, *mercedes, *nissan, *opel, *peugeot, *renault, *rover, *skoda, *toyota, *volkswagen;
extern ASSURANCE_INFO *info;
extern ASSURANCE_INFO *info_file;
extern VIGNETTE_INFO *info_v_file;
extern GtkBuilder *builder;
extern GtkWidget *window;
extern GtkWidget *stack;
extern GtkWidget *page1;
extern GtkWidget *page2;
extern GtkWidget *page3;
extern GtkWidget *assurance;
extern GtkWidget *vignette;
extern GtkWidget *quitter;
//variable for page
extern GtkWidget *nom_error;
extern GtkWidget *nom_entry;
extern GtkWidget *nom_label;

extern GtkWidget *prenom_label;
extern GtkWidget *prenom_error;
extern GtkWidget *prenom_entry;

extern GtkWidget *cin_entry;
extern GtkWidget *cin_label;
extern GtkWidget *cin_error;

extern GtkWidget *ville_choser;
extern GtkWidget *ville_label;
extern GtkWidget *ville_error;
extern GtkWidget *ville_entry;
extern GtkWidget *ville_list;

extern GtkWidget *stack1;
extern GtkWidget *page2_1;
extern GtkWidget *page2_2;
extern GtkWidget *suivant_button;


extern GtkWidget *page2_3;
extern GtkWidget *page2_4;
extern GtkWidget *retour1;
extern GtkWidget *retour2;
extern GtkWidget *suivant1;
extern GtkWidget *payer;
extern GtkWidget *retour3;
extern GtkWidget *radio;

extern GtkWidget *matricule_entry;
extern GtkWidget *matricule_label;
extern GtkWidget *matricule_error;

extern GtkWidget *police_entry;
extern GtkWidget *police_label;
extern GtkWidget *police_error;

extern GtkWidget *marque_entry;
extern GtkWidget *marque_label;
extern GtkWidget *marque_error;

extern GtkWidget *date_entry;
extern GtkWidget *date_label;
extern GtkWidget *date_error;

extern GtkWidget *puissance_entry;
extern GtkWidget *puissance_label;
extern GtkWidget *puissance_error;

extern GtkWidget *user_info;
extern GtkTextBuffer *buffer;


extern GtkWidget *marque_entry;
extern GtkWidget *marque_label;
extern GtkWidget *marque_error;
extern GtkWidget *marque_choser;

extern GtkWidget *error_info;
extern int valid;

extern GtkWidget *menu1;
extern GtkWidget *menu2;
extern GtkWidget *menu4;
extern GtkWidget *menu3;
extern GtkWidget *menu7;

extern GtkWidget *matricule_entry_;
extern GtkWidget *matricule_label_;
extern GtkWidget *matricule_error_;

extern GtkWidget *puissance_entry_;
extern GtkWidget *puissance_label_;
extern GtkWidget *puissance_error_;

extern GtkWidget *diesel;
extern GtkWidget *essence;
extern GtkWidget *electrique;
extern GtkWidget *hybride;

extern GtkWidget *rechercher;
extern GtkWidget *stack2;
extern GtkWidget *error_label;

extern GtkComboBoxText *mois_choser;
extern GtkWidget *resultat_label;
extern GtkWidget *mois_entry;
extern GtkWidget *mois_error;

extern GtkWidget *quitter3;

extern GtkWidget *info_vignette;
extern GtkTextBuffer *buffer_v;

extern float sum;
extern int total;
extern double total_with_penalties;
extern char carburant[MAX];
extern char puissance[MAX];

extern GtkWidget *retour4;


#endif // MINI_PROJET_H_INCLUDED

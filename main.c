#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLEMAX 28 //Constante pour la taille maximum du mot
#define TAILLEPENDU 11 //Constante pour la taille de la matrice qui affiche le pendu



//Procédures
void InitialisationMot (char *str_mot, char *str_motCache, int *n_tailleMot);
void Tour (int *n_tailleMot, char *str_motCache, char str_mot[], int *n_pv);
void Potence (n_pv);
void Verification (int *n_test, int n_pv, char str_mot, char str_motCache);
void Fin (n_pv);


int main()
{
//Variables
int n_tailleMot=0, n_comparaison=0, n_pv=10, n_test=1;
char str_mot[TAILLEMAX], str_motCache[TAILLEMAX];

//jeu principal

InitialisationMot(&str_mot,&str_motCache,&n_tailleMot); //Procédure permettant d'initialiser les données de départ (mot, mot caché et taille du mot)
n_tailleMot=strlen(str_mot); //Réaffection de la longueur du mot
system("cls"); //Permet d'effacer les éléments présent dans la console (comme le mot à trouver)
do{ //Boucle principal du jeu, se répete jusqu'a ce que le jeu finisse
    Tour(n_tailleMot, &str_motCache, str_mot, &n_pv); //Procédure qui demande une lettre à l'utilisateur, la vérifie avec le mot et remplasse la lettre si nécessaire dans le mot caché
    Potence(n_pv); //Affichage de la potence dans une matrice en fonction du nombre de pv restant
    n_test=strcmp(str_mot,str_motCache); //Comparaison des deux mots, si ils sont identiques le resultat sera zero et la boucle principale s'arrete
    Verification (&n_test,n_pv,str_mot,str_motCache); //Procédure qui vérifie le nombre de pv, si les pv à zero la boucle principale s'arrete
    system("PAUSE"); //Pause dans la console afin que le pendu sois afficher correctement
    system("cls"); //Efface les éléments présents sur la console avant d'entamer un nouveau tour de boucle

}while(n_test!=0); //Fin de la boucle principal que n_test est égal à zero
Fin(n_pv); //Procédure qui affiche le méssage de fin de jeu en fonction du nombre de pv, défaite ou victoire
printf("Merci d'avoir joué!\n");





    return 0;
}



 /**************************************************************************************
    BUT : Initialiser le mot à trouver et le mot caché par des étoiles

    ENTREE : Le mot à trouver par l'utilisateur

    SORTIE : Affiche le mot à trouver

    Description : Cette procédure permet l'initialisation du mot à trouver et du mot caché par des étoiles, elle permet également d'enregistrer la longueur du mot
    **************************************************************************************/

void InitialisationMot (char *str_mot, char *str_motCache, int *n_tailleMot){

    int n_i=0; //Initialisation de n_i
    printf("Veuillez entrer le mot a trouver en minuscule\n");
    scanf("%s",str_mot); //Demande est scan du mot à trouver
    n_tailleMot=strlen(str_mot); //Taille du mot donné à n_tailleMot
    for (n_i=0;n_i<n_tailleMot;n_i++){ //Boucle permettant d'initialiser le mot caché avec des étoiles en fonction de la longueur du mot principal
        str_motCache[n_i]='*';
    }
    printf("Le mot a trouver est : %s\n",str_motCache); //Affichage du mot caché
}


 /**************************************************************************************
    BUT : Le déroulement d'un tour de jeu

    ENTREE : La lettre donné par l'utilisateur

    SORTIE : Affiche une erreur si la lettre n'est pas une lettre minuscule

    Description : Cette procédure permet le déroulement d'un tour de jeu en comparant une lettre donné par l'utilisateur avec les lettres du mot principal, elle permet également la vérification de la lettre donné et indique si elle n'est pas une lettre en minuscule
    **************************************************************************************/

void Tour (int *n_tailleMot, char *str_motCache, char str_mot[], int *n_pv){

    int n_i=0, n_erreur=0;
    char c_lettre=' ';
    fflush(stdin);
    printf("Le mot a trouver est : %s\n",str_motCache); //Rappel de l'avancer du mot caché
    printf("Veuillez entrer une lettre en minuscule\n");
    scanf("%c",&c_lettre); //Demande + scan de la lettre proposé par l'utilisateur
    if(c_lettre>='a' && c_lettre<='z'){ //SI qui permet la verification de la lettre et qui continue correctement le programme si c'est une lettre minuscule
    for(n_i=0;n_i<n_tailleMot;n_i++){ //Boucle qui permet de verifié si la lettre est dans le mot principal et si oui la rajoute dans le mot caché
        if(c_lettre==str_mot[n_i]){
            str_motCache[n_i]=c_lettre;
        }else{
            n_erreur++; //Si la lettre ne correspond pas n_erreur augment de 1..
        }
    }
    if(n_erreur==n_tailleMot){ //.. et si le nombre d'erreur est égal à la longueur du mot cela signifie que la lettre n'est pas présent dans le mot et donc que la lettre est fausse
        *n_pv=(*n_pv-1); //pv baisse de 1 car la lettre ne correspond pas
    }
    }else{
        printf("Erreur de saisie\n"); //Si le caractère n'est pas une lettre en minuscule l'utilisateur est prévenu est la boucle recommence sans perte de pv
    }
}


 /**************************************************************************************
    BUT : Afficher le pendu en fonction des points de vie

    ENTREE : /

    SORTIE : Affichage du pendu à l'écran

    Description : Cette procédure permet l'affichage du pendu en fonction de nombre de point de vien restant (n_pv)
    **************************************************************************************/

void Potence (n_pv){

    int n_ligne=0, n_colonne=0;
    char c_tabpendu[TAILLEPENDU][TAILLEPENDU];
    for(n_ligne=1;n_ligne<TAILLEPENDU;n_ligne++){ //Initialisation du tableau permettant d'afficher le pendu
        for(n_colonne=1;n_colonne<TAILLEPENDU;n_colonne++){
            c_tabpendu[n_ligne][n_colonne]=' ';
        }
    }
    if(n_pv<=9){ //Mise en place du pendu dans la matrice en fonction du nombre de pv
        c_tabpendu[9][1]='-';
        c_tabpendu[9][2]='-';
        c_tabpendu[9][3]='-';
        if(n_pv<=8){
            c_tabpendu[5][2]='|';
            c_tabpendu[6][2]='|';
            c_tabpendu[7][2]='|';
            c_tabpendu[8][2]='|';
            if(n_pv<=7){
                c_tabpendu[4][2]='_';
                c_tabpendu[4][3]='_';
                c_tabpendu[4][4]='_';
                c_tabpendu[4][5]='_';
                c_tabpendu[4][6]='_';
                if(n_pv<=6){
                    c_tabpendu[5][6]='|';
                    if (n_pv<=5){
                        c_tabpendu[6][6]='0';
                        if(n_pv<=4){
                            c_tabpendu[7][6]='|';
                            if(n_pv<=3){
                                c_tabpendu[7][5]='/';
                                if(n_pv<=2){
                                    c_tabpendu[7][7]='\\';
                                    if(n_pv<=1){
                                        c_tabpendu[8][5]='/';
                                        if(n_pv<=0){
                                            c_tabpendu[8][7]='\\';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(n_ligne=1;n_ligne<TAILLEPENDU;n_ligne++){ //Affichage de la matrice possédant le pendu en fonction des pv
        for(n_colonne=1;n_colonne<TAILLEPENDU;n_colonne++){
            printf("%c",c_tabpendu[n_ligne][n_colonne]);
        }
        printf("\n");
    }
    printf("\n");
    printf("PV restant : %d\n",n_pv); //Affichage du nombre de pv restant
}


 /**************************************************************************************
    BUT : Vérifier le nombre de pv

    ENTREE : /

    SORTIE : /

    Description : Cette procédure permet de verifier le nombre de pv et d'arreter le jeu s'il est égal à zero
    **************************************************************************************/

void Verification (int *n_test, int n_pv, char str_mot, char str_motCache){

    if(n_pv==0){ //Si les pv sont a zero le changement de n_test permet la sortie de la boucle principale
        *n_test=0;
    }
}


 /**************************************************************************************
    BUT : Afficher la fin de jeu

    ENTREE : /

    SORTIE : Affichage de la fin de jeu à l'écran

    Description : Cette procédure permet l'affichage d'un texte de victoire si la partie est gagné et d'un texte de défaite si la partie est perdue
    **************************************************************************************/

void Fin (n_pv){

    if(n_pv==0){ //Affichage du texte de fin de jeu après être sortie de la boucle principale
        printf("GAME OVER\n"); //Défaite si les pv sont a zero
    }else{
        printf("Felicitation!\n");//Victoire si dans l'autre cas
    }
}





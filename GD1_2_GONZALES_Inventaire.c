#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//On utilisera une structure pour tous les objets.
struct Objet{

	char cNom [40];
	int nPrix;

};	
typedef struct Objet item;


//Fonctions 
//voir l'inventaire du joueur
void viewInventory (item * inventaire) {
	
	for (int i = 0; i<50; i++) {
		if (strcmp(inventaire[i].cNom , "") > 0){
			int nSlot = i+1;
			printf ("\nCase %d : %s",nSlot, inventaire[i].cNom);
			
		}
		
	}
};

//trier l'invenaire par ordre alphabétique, en regardant la première lettre, puis la deuxième si la première lettre est identique
void sortInventory(item * inventaire){
	
    int nTamponPrix = 0;
    char cTamponNom[30];

    for(int i=0; i<49; i++){
        for(int j=(i+1); j<50; j++){
            if(strcmp(inventaire[j].cNom, "") >0){
                for(int k=0; k<30; k++){
                    if(strncmp(inventaire[i].cNom, inventaire[j].cNom, k) > 0 ){
                        strcpy(cTamponNom, inventaire[i].cNom);
                        strcpy(inventaire[i].cNom, inventaire[j].cNom);
                        strcpy(inventaire[j].cNom, cTamponNom);

                        nTamponPrix = inventaire[i].nPrix;
                        inventaire[i].nPrix = inventaire[j].nPrix;
                        inventaire[j].nPrix = nTamponPrix;
						k = 30;
                    }
                }
            }
        }

    }

};

//voir l'inventaire du marchand
void viewMerchantStore (item * inventaire) {
	
	for (int i = 0; i<50; i++) {
		if (strcmp(inventaire[i].cNom , "") > 0){
			int nSlot = i + 1;
			printf ("\nCase %d : %s", nSlot, inventaire[i].cNom);
			printf (" | PRIX : %d\n", inventaire[i].nPrix);
			
		}
		
	}
	printf ("\n*************************************************************************************************************\n");
};

//trier l'inventaire du marchand en fonction du prix
void sortStore(item * inventaire){
	
    int nTamponPrix = 0;
    char cTamponNom[30];

    for(int i=0; i<49; i++){
        for(int j=(i+1); j<50; j++){
			if (strcmp(inventaire[j].cNom , "") > 0){
				if(inventaire[i].nPrix > inventaire[j].nPrix){
					
					strcpy(cTamponNom, inventaire[i].cNom);
					strcpy(inventaire[i].cNom, inventaire[j].cNom);
					strcpy(inventaire[j].cNom, cTamponNom);
					
					nTamponPrix = inventaire[i].nPrix;
					inventaire[i].nPrix = inventaire[j].nPrix;
					inventaire[j].nPrix = nTamponPrix;
				}
			}
        }

    }
	
	

};

//ajouter un objet dans l'inventaire du marchand
void addMerchantItem (item * inventaire) {
	char cNom [25];
	int nPrix;
	printf (" Objet : ");
	scanf ("%s", &cNom);
	printf (" Prix : ");
	scanf ("%d", &nPrix);
	
	
	for(int i=0; i<50; i++){
        if(strcmp (inventaire[i].cNom , "") == 0 ){
			strcpy (inventaire[i].cNom , cNom);
			inventaire[i].nPrix = nPrix;
			i=50;
        }
	}
};

//acheter un objet
void buyItem (item * inventaire, item * objet) {
	int nbSlot;
	printf(" Choisissez un objet !\n");
	scanf ("%d", &nbSlot);
	nbSlot -= 1;
	
	for(int i=0; i<50; i++){
        if(strcmp (inventaire[i].cNom , "") == 0 ){
			strcpy (inventaire[i].cNom ,objet[nbSlot].cNom);
			inventaire[i].nPrix = objet[nbSlot].nPrix;
			strcpy(objet[nbSlot].cNom, "");
			objet[nbSlot].nPrix=0;
			i=50;
        }
	}
	
};

//Début
int main () {
	
	
	//Definition des structures
	item inventaireJoueur [50] = { {"Casque du Baron", 10}, {"Masse du flemahl", 19}, {"Dague mahlveillante", 25}, {"Hache porte-guerre du Siege", 16} };
	
	item MerchantStore [50] = { {"Masque de la mahlbushi", 10}, {"Fee mahlblinguee", 15}, {"Os de la Shamahl", 5}, {"Arc deshonorable mahlhonore", 20} };
	
	
	//Inventaire joueur
	printf ("\nVOTRE INVENTAIRE : \n");
	printf ("___________________\n");
	sortInventory (&inventaireJoueur[0]);
	viewInventory (&inventaireJoueur[0]);
	printf ("\n*************************************************************************************************************\n");
	
	//Inventaire Marchand
	printf ("\nRESERVE DE MAHL INCORPORATED (Il est si bon d'etre mauvais !) : \n");
	printf ("___________________\n");
	sortStore (&MerchantStore[0]);
	viewMerchantStore(&MerchantStore[0]);
	printf ("\n*************************************************************************************************************\n");
		
	//Commande
	printf ("\n Quel objet mahlefique ce larbin de stagiaire a-t-il oublie dans la reserve ? \n");
	addMerchantItem (&MerchantStore[0]);
	sortStore (&MerchantStore[0]);
	viewMerchantStore (&MerchantStore[0]);
	printf ("\n*************************************************************************************************************\n");
	
	//Achat
	printf ("\nQuel objet souhaitez vous vous approrier pour votre gloire personnelle ?\n");
	buyItem (&inventaireJoueur[0], &MerchantStore[0] );
	sortInventory (&inventaireJoueur[0]);
	viewInventory (&inventaireJoueur[0]);
	sortStore (&MerchantStore[0]);
	
	printf ("\n*************************************************************************************************************\n");
	return 0;
}
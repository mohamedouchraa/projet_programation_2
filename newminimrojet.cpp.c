#include<stdio.h>
#include<stdlib.h>
#include<string.h>   
//#include<ctype.h> 
//#include<curses.h> 
#include<conio.h>

void MenuPrincipal(void);
//int jours(struct date,struct date);
void MenuGestionVoiture(void);
void listevoiture(void);
void ajoutevoiture(void);
void modifiervoiture(void);
void supprimervoiture(void);
void Retourn(void);
int  checkid1(int); 
//float cot(int,struct date,struct date);
//int date_a_jour(struct date); 
void MenuGestionClient(void);
void listeclient(void);
void ajouteclient(void);
void modifierclient(void);
void supprimeclient(void);
int checkid2(int);
int verifier2(char,char);
void MenuLocation(void);
void Visualisercontrat(void);
void louervoiture(void);
void Retournervoiture(void);
void Modifiercontrat(void);
void Supprimercontrat(void);
//int cout(int);
int checkid3(int);
void ajoutecontrat(void);
void enlocationsupp(int);

FILE *fp,*ft,*fs,*fts,*fc,*ftc;
  //**************************************************************
	//***			STRUCTUR DE PROGRAME			      ***
	//***************************************************************
struct date
{
     int mm,dd,yy;
};
typedef struct voiture
{
int idVoiture;
char marque[15];
char nomVoiture[15];
char couleur[7];
int nbplaces;
int prixJour;
int EnLocation;
} voiture;


typedef struct contrat
{
int numContrat;
int idVoiture;
int idClient;
struct date debut;
struct date fin;
int dure;
int cout;
} contrat;

typedef struct client
{
   int idClient;
   char nom[20];
   char prenom[20];
   int cin;
   char adresse[15];
   int telephone;
}client; 
 struct voiture a;
 struct client b;
 struct contrat c;

//*****************************************************************
//****                ********************                     ****
//******            **                    **                  *****
//*********        ***PROGRAMME PRINCIPALE***            **********
//******            **                    **                  ***** 
//****                ********************                     ****  
//*****************************************************************

int main() { 
	MenuPrincipal();
	getch();
	system("color b4");
	return 0;
}

    //***************************************************************
	//***			TRAITEMENT DES MENUprincipale			      ***
	//***************************************************************

	
void MenuPrincipal(void)
{  system("cls");
system("color b4");
	int choix;


	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principale \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Location..............................1   \xba");
	printf("\n               \xba    Gestion voitures......................2   \xba");
	printf("\n               \xba    Gestion clients.......................3   \xba");
	printf("\n               \xba    Quitter...............................4   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

 switch(getch())
{
     case '1':
         MenuLocation();
             break;
     case '2':
          MenuGestionVoiture();
             break;
     case '3':
         MenuGestionClient();
             break;
     case '4':{
	 system("cls");
             exit(0);}
     default:{
     	puts("**************************************************************************************************");
          printf("\aMauvaise entrée !! Veuillez ré-entrer l'option correcte");
        puts("**************************************************************************************************");
             if(getch())
                    MenuPrincipal();
             }
}
 }	
     //**************************************************
	//***   L'ACCEE AU MENU DE GESTION DE VOITURE    ***
    //**************************************************
void MenuGestionVoiture()
{
	system("color b4");
	int choix;


	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion voiture \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    liste de voiture......................1   \xba");
	printf("\n               \xba    Ajouter voiture.......................2   \xba");
	printf("\n               \xba    Modifier voiture......................3   \xba");
	printf("\n               \xba    Supprimer voiture.....................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	
	
	 switch(getch())
{
     case '1':
          listevoiture();
             break;
     case '2':
          ajoutevoiture();
             break;
     case '3':
          modifiervoiture();
             break;
     case '4':
          supprimervoiture();
             break;
     case '5':
         Retourn();
             break;
     default:{
     	if(choix>5){ 
     	puts("**************************************************************************************************");
          printf("\aMauvaise entrée !! Veuillez ré-entrer l'option correcte");
        puts("**************************************************************************************************");
             if(getch())
                    MenuGestionVoiture();
             }	}

}
}               //**********************************************
				//***   Affichage  Listes des voitures       ***
				//**********************************************
	
void listevoiture(void){ 
    system("cls");
    system("color b4");
    int d;
      printf("\n________________________________ Liste de voitures_________________________________\n");
	  fp=fopen("voiture.dat","rb");
       while(fread(&a,sizeof(a),1,fp)==1)
		{ 
			printf("\n id de voiture               : %d",a.idVoiture);
			
			printf("\n marque de voiture           : %s",a.marque);
		
			printf("\n le nom de voiture           : %s",a.nomVoiture);
		 
			printf("\n le prix de joure de voiture : %d",a.prixJour);
			
			printf("\n le couleur de voiture       : %s",a.couleur);
		
			printf("\n le nembre deplace de voiture: %d",a.nbplaces);
				printf("\n_____________________________________________________________________________________\n");	
		
			printf("\n     en location  : oui (0)/non(1)    %d     \n",a.EnLocation);
            }  sleep(10);
             system("cls");
			  fclose(fp);
        	MenuGestionVoiture();
}
                  
                  //**********************************************
				  //***   ajouter   les voitures       ***
				  //**********************************************
				
void  ajoutevoiture(void){ 
system("cls");
system("color b4");
 int d;
   printf("\ntaper ID de voiture qui vous voulez ajouter    :");
   scanf("%d",&d);
    fp=fopen("voiture.dat","ab+"); 
	if(checkid1(d) == 0){
        printf("\aL'identifiant du voiture existe deja \a");

           MenuGestionVoiture();}//retourner a la menu voiture

    else{
          
           system("cls");
		          puts("_____________________________ Ajouter une voiture____________________________________");
	            	printf("\n  taper votre nom de voiture      : ");
		             scanf("%s",a.nomVoiture);
		            printf("\n  taper votre Id de voiture       : ");
                     scanf("%d",&a.idVoiture);
                    printf("\n  taper votre de mark de voiture  : ");
                     scanf("%s",a.marque);
                    printf("\n  taper votre couleur de voiture  : ");
                     scanf("%s",a.couleur);
                    printf("\n  taper votre nbplace de voiture  : ");
                     scanf("%d",&a.nbplaces);
                    printf("\n  taper votre prix de jour        : ");
                     scanf("%d",&a.prixJour);
                    printf("\n  taper votre enlocation oui (0)/non (1)\n ");
                     scanf("%d",&a.EnLocation);
                printf("\n____________________________________________________________________________________________\n");
	        fwrite(&a,sizeof(a),1,fp);
	        fseek(fp,0,SEEK_END);
              fclose(fp);
                  printf("\t\t\t L'enregistrement est enregistre avec succes");
                  
            printf("\n\n*************Economisez plus?(o/ n): *********************\n\n");
               if(getch()=='o')
                 ajoutevoiture(); 
               else 
			   MenuGestionVoiture();
                 system("cls");
                      
	} 
	}
	
				//**********************************************
				//***  modifier les information des voitures ***
				//**********************************************
		
void modifiervoiture(void)  
	{
		system("cls");
		system("color b4");
		int c=0;//teste la modefication a reusse
		int d;
		
		printf("**\n\n\nModifier la section des voitures\n\n\n**");
		char another='o';
		while(another=='o')
		{
			system("cls");
		
			printf("***taper le ID  de voiture qui vous modifieer:***");
			scanf("%d",&d);
			fp=fopen("Voiture.dat","rb+");
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(checkid1(d)==0)
				{
				
					printf("\n\n\n le voiture est disponible");
					
					printf("\n nouveau  ID de voiture         :%d",a.idVoiture);
					
					printf("\n nouveau  marque de voiture     :");scanf("%s",a.marque);
					
					printf("\n  nouveau nom de voiture        : ");scanf("%s",a.nomVoiture);
					
					printf("\n nouveau prix de voiture        :");scanf("%d",&a.prixJour);
					
					printf("\ntaper nouveau de voiture couleur:");scanf("%s",a.couleur);
					
					printf("\nEnter  nouveau  nombre places   :");scanf("%d",&a.nbplaces);
					printf("\nEnter  nouveau  en locale       :");scanf("%d",&a.EnLocation);
					printf("\n  _______L'enregistrement est modifie  _____________ ");
					fseek(fp,ftell(fp)-sizeof(a),0);
					fwrite(&a,sizeof(a),1,fp);
					fclose(fp);
					c=1;
				
				}
				if(c==0)
				{
					
					printf("Aucun Enregistrement Trouvé");
				}
			}
			
			printf("\nModifier un autre enregistrement?(o/n) ");
			fflush(stdin);
			another=getch() ;
		}
	  MenuGestionVoiture();
	}	
	            //**********************************************
				//***   Supprimer le voiture       ***
				//**********************************************
void supprimervoiture(void){
	system("cls");
	system("color b4");
	int h;
	int y=0;//test de existance de voiture
	printf("**************************************************************************************");
	 printf("           \n\n taper id de voiture qui vous voulez supprimer  \n\n          ");
	  scanf("%d",&h);
	         fp=fopen("voiture.dat","rb+");
             rewind(fp);
             while(fread(&a,sizeof(a),1,fp)==1){
	 	        if(checkid1(h)==0){
	 		     printf("\n\\t\t.........le voiture est disponible :)...........\t\t");
			        printf("\n\t\tVoulez-vous le supprimer?(o/n):\t\n\t");
                                    if(getch()=='o'){
                            ft=fopen("test.dat","wb+");  //temporary file for delete
                              rewind(fp);
                                  while(fread(&a,sizeof(a),1,fp)==1){
                                         if(a.idVoiture!=h){
                                        fseek(ft,0,SEEK_CUR);
                                         fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
                                     }                            }  //we want to delete
                                          fclose(ft);  
                                          fclose(fp);
                                           remove("voiture.dat");
                               rename("test.dat","voiture.dat"); //copy all item from temporary file to fp except that
			y++;
	 		printf("\n\t\t.........L'enregistrement est supprimé avec succes :) .............\t\t\t");
	 		 }}
	 		 if(y==0){
	 		 	puts("\n\n***********************************************************************************************************\n");
	           	printf("  \n............. ID de votr voiture n'existe pas dans la liste :) ...................\a\n");
		        puts("\n\n***********************************************************************************************************\n\n");
	      sleep(3);
		  	MenuGestionVoiture();
			  }
}	
sleep(5);
system("color b4");
 MenuGestionVoiture();  
}	

                //**********************************************
				//***   Rouren a la menu principale         ***
				//**********************************************
void Retourn(){
	printf("  \n\n\n...............revenir au menu principal oui(o)/non(n) .............\n\n\n");
        if(getch()=='o') {
            MenuPrincipal();}

}                 //**********************************************
				//***   Verifier le ID  des voitures       ***
				//**********************************************

int checkid1(int t)  
{
rewind(fp);
system("color b4");
while(fread(&a,sizeof(a),1,fp)==1)
if(a.idVoiture==t)
return 0;  //returns 0 if  exits
return 1; //return 1 if it not
}

                 //**********************************************
				//***   MENU DE GESTION DE VOITURE           ***
				//**********************************************
void MenuGestionClient(void)
{
	int choix;
	system("color b4");

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion client  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    liset client..........................1   \xba");
	printf("\n               \xba    ajoute client.........................2   \xba");
	printf("\n               \xba    Modifier client ......................3   \xba");
	printf("\n               \xba    Supprimer client  ....................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	
  switch(getch())
{
     case '1':
         listeclient();
             break;
     case '2':
          ajouteclient();
             break;
     case '3':
         modifierclient();
             break;
     case '4':
          supprimeclient();
             break;
     case '5':
        Retourn();
             break;
     default:{
     	puts("**************************************************************************************************");
          printf("\a.............Mauvaise entrée !! Veuillez ré-entrer l'option correcte :) .....................");
        puts("**************************************************************************************************");
             if(getch())
                    MenuGestionClient();
             }
}
}
               //**********************************************
				//***   Affichage  Listes des clients        ***
				//**********************************************

void listeclient(void){
    system("cls");
    system("color b4");
    int d1;
      printf("\n\n********************************* Liste de clients *****************************\n\n");
	  fs=fopen("client1.dat","rb");
       while(fread(&b,sizeof(b),1,fs)==1)
		{ 
			printf("\n id de client                :   %d",b.idClient);
			
			printf("\n  nom de client              : %s",b.nom);
		
			printf("\n  prenom de client           :   %s",b.prenom);
		
			printf("\n  le cin de client           :   %d",b.cin);
			
			printf("\n adresse de client           :   %s",b.adresse);
		
			printf("\n   le telephone de client    :  %d",b.telephone);
		

			printf("\n ---------------------------------------------------------------------------------------");	
		  
            }  sleep(10);
             system("cls");
             fclose(fs);  
        MenuGestionClient();
}
               //**********************************************
				//***   Ajouter les client                  ***
				//**********************************************
void ajouteclient(void){
	system("cls");
	system("color b4");
     int d;
   printf("taper ID de client qui vous voulez ajouter :");
   scanf("%d",&d);
    fs=fopen("client1.dat","ab+"); 
	if(checkid2(d) == 0){
        printf("\a  ...........L'identifiant du client existe deja ................\a");
        sleep(4);
          	MenuGestionClient();}

    else{
           system("cls");
           system("color b4");
           
		          puts("\n--------------------------------Ajouter un client  ------------------------------------------------------------");
	                 printf("\n ++++ taper votre Id de client        :");
                     scanf("%d",&b.idClient);	
					 printf("\n ++++ taper votre nom de client       :");
		             scanf("%s",b.nom);
					 printf("\n ++++ taper votre de prenom de client :");
                     scanf("%s",b.prenom);
                    printf("\n ++++ taper votre telephone de client  :");
                     scanf("%ld",&b.telephone);
                    printf("\n ++++ taper adresse de client          : ");
                     scanf("%s",b.adresse);
                     printf("\n ++++ taper votre cin de client       :");
                     scanf("%d",&b.cin);
                printf("-------------------------------------------------------------------------------------------------------");
	        fwrite(&b,sizeof(b),1,fs);
	        fseek(fs,0,SEEK_END);
              fclose(fs);
                  printf("\t\t\t  .L'enregistrement est enregiste avec succes , Merci pour votre participation................\n");
                sleep(5);  
            printf("\n\n*************Économisez plus?(o/ n): *********************\n\n");
               if(getch()=='n')
             MenuGestionClient();
               else
                 system("cls");
                 system("color b4");
                 ajouteclient();      
	} 
}            
              //**********************************************
				//***   Modifier le client                  ***
				//**********************************************
void  modifierclient(void){
	system("cls");
	system("color b4");
		int c=0;
		int d,e;
		
		printf("**\n\n\n***************Modifier la section des clients**********\n\n\n**");
		char another='o';
		while(another=='o')
		{
			system("cls");
		
			printf("***taper le ID  de client qui vous modifieer:***");
			scanf("%d",&d)
			;
			fs=fopen("client1.dat","rb+");
			while(fread(&b,sizeof(b),1,fs)==1)
			{
				if(checkid2(d)==0)
				{
				
					printf("\n\n\n............ le cient est disponible :) .................\n");
					
					printf("\n taper nouveau  ID de client :\n");scanf("%d",&b.idClient);
					
					printf("\n taper nouveau nom de client :\n");scanf("%s",b.nom);
					
					printf("\n taper nouveau prenom de client: \n");scanf("%s",b.prenom);
					
					printf("\n  taper nouveau CIN de client : \n");scanf("%d",&b.cin);
					
					printf("\ntaper nouveau adresss de client:\n");scanf("%s",b.adresse);
					
					printf("\nEnter  nouveau telephone de client :\n");scanf("%d",&b.telephone);
					
					printf("\n*****************L'enregistrement est modifié :) ****************************");
					fseek(fs,ftell(fs)-sizeof(b),0);
					fwrite(&b,sizeof(b),1,fs);
					fclose(fs);
					c=1;
				
				}
				if(c==0)
				{
					
					printf("\n ****************** Aucun Enregistrement Trouve :( **************************");
				}
			}
			
			printf("\n *****************Modifier un autre enregistrement?(o/n) *************************8");
			fflush(stdin);
			another=getch() ;
		}
	MenuGestionClient();
} 
                //**********************************************
				//***   Supprimer le client                  ***
				//**********************************************

void supprimeclient(){
	system("cls");
	system("color b4");
	int h;
	int y=0;
	printf("**************************************************************************************");
	 printf("           \n\n taper ID de client qui vous voulez supprimer  \n\n          ");
	  scanf("\t%d",&h);
	         fs=fopen("client1.dat","rb+");
             rewind(fs);
             while(fread(&b,sizeof(b),1,fs)==1){
	 	        if(checkid2(h)==0){
	 		     printf("\n\\t\t ................ le client est disponible :)...................\t\t");
			        printf("\n\t\t.................Voulez-vous le supprimer?(o/n) : ..................\t\n\t");
                                    if(getch()=='o'){
                            fts=fopen("test2.dat","wb+");  //temporary file for delete
                              rewind(fs);
                                  while(fread(&b,sizeof(b),1,fs)==1){
                                         if(b.idClient!=h){
                                        fseek(fts,0,SEEK_CUR);
                                         fwrite(&b,sizeof(b),1,fts); //write all in tempory file except that
                                     }                            }  //we want to delete
                                          fclose(fts);  
                                          fclose(fs);
                                           remove("client1.dat");
                               rename("test2.dat","client1.dat"); //copy all item from temporary file to fp except that
		                    	y++;
	 		                  printf("\n\t\t *************** L'enregistrement est supprimé avec succes :) ***************************\t\t\t");
	 		 }                    }            sleep(2); 

	 		 if(y==0){
	 		 	puts("\n\n***********************************************************************************************************\n");
	           	printf("  \n      ID de votr client n'existe pas dans la liste :) \a  \n          ");
		        puts("\n\n***********************************************************************************************************\n\n");
			  }
           } sleep(7);
		   system ("cls");      
	MenuGestionClient(); }
	
             //**********************************************
				//***   Verifier le Id de client         ***
				//**********************************************


int checkid2(int s){
	rewind(fs);
	while(fread(&b,sizeof(b),1,fs)==1)

	if(b.idClient==s)
	return 0;
	return 1;
   }
   
                 //**********************************************
				//***   MENU DE LOCATION                   ***
				//**********************************************
void MenuLocation()
{
	int choix;
	system("color b4");


	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Location voiture\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Visualiser contrat....................1   \xba");
	printf("\n               \xba    louer voiture.........................2   \xba");
	printf("\n               \xba    Retourner voiture.....................3   \xba");
	printf("\n               \xba    Modifier contrat......................4   \xba");
	printf("\n               \xba    Supprimer contrat.....................5   \xba");
	printf("\n               \xba    Retour................................6   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	
switch(getch())
{
     case '1':
         Visualisercontrat();
             break;
     case '2':
          louervoiture();
             break;
     case '3':
         Retournervoiture();
             break;
     case '4':
          Modifiercontrat();
             break;
     case '5':
         Supprimercontrat();
             break;
     case '6':
         MenuPrincipal();
             break;
     default:{
     	puts("-------------------------------------------------------------------------------------------------");
          printf("\n Mauvaise entrée !! Veuillez ré-entrer l'option correcte");
        puts("\n-----------------------------------------------------------------------------------------------");
             if(getch())
                    MenuLocation();
             }
}	
}

             //**********************************************
				//***   Visualisercontratt             ***
				//**********************************************
void Visualisercontrat(void){
	 system("cls");
	 system("color b4");
    int d,h=0;
    
    printf("\n ........... taper numero de contrat ...................\n");
    scanf("%d",&d);
    if(checkid3(d)==0){
     // printf("\n\n********************************* Liste de contrat*****************************\n\n");
	     fc=fopen("contrat.dat","rb");
     while(fread(&c,sizeof(c),1,fc)==1)
		{ 
		 printf("\n\n********************************* Liste de contrat*****************************\n\n");
			//	printf("\n\tNumbre de contrat         : %d",&c.numContrat);
              	printf("\n\tID de voiture        : %d\n",c.idVoiture);

	            printf("\t ID de client       : %d\n",c.idClient);
             	//printf("\t\t le cout          : %d",&c.cout);

	            printf("\t le debut de la date  : %d/%d/%d\n",c.debut.dd,c.debut.mm,c.debut.yy);
              //  printf("/t/n/n le dure de voiture :%d",&c.dure);
	            printf("\t la fin de la date : %d/%d/%d\n",c.fin.dd,c.fin.mm,c.fin.yy);
	            printf("    	%d DH",c.cout);
	     printf("\n******************************************************************************\n");
	                 //   printf("\n\n\n");	  
        }fclose(fc); h=1;
        MenuLocation(); 
	}
    if(checkid3(d)==1){
    	printf(" \n\n ............ ce contrat n existe pas dans la liste .........\n");
    	sleep(5);
    	MenuLocation();
	}
} 
                //**********************************************
				//***   Louer  des voitures       ***
				//**********************************************

void louervoiture(void){
	system("cls");
	system("color b4");
	int d=0,aide1=0,aide=0,aide2=0;
	int d2;
	int l=0;
	char n[20],p[30];
	 
	        printf("....... taper votre nom :");
             scanf("%s",n);
            printf(".......  taper votre prenom :");
             scanf("%s",p);    
          
           fs=fopen("client1.dat","rb+"); 
			 rewind(fs); 
            while(fread(&b,sizeof(b),1,fs)==1)
		         {	  
    	           if(strcmp(b.nom,(n))==0 )
				   	{
					   if( strcmp(b.prenom,(p))==0){
	                printf("\n\t ...........vous etes avec nous :) .......\n\n");
	               // listevoiture();
                    printf("\n\n....... taper votre ID de voiture qur vous voulez :)............\n");
                    scanf("%d",&d2); 
			                	fp=fopen("voiture.dat","rb+");
                                 while(fread(&a,sizeof(a),1,fp)==1){
                                if(a.idVoiture==d2)
                                      {    
									  if(a.EnLocation==0)
			                       	{  printf("\n\n\t........... le voiture est disponible :)...........");
									   printf("\n\n  ...............  le voiture en locale   :)............");
									   	printf("\n\n ......... est ce que vous voulez louer le voiture oui(o) /non (n)");
					                        if(getch()=='o')
								            	{
					                           ajoutecontrat();	
					                          a.EnLocation==1;
				                         	    }
					                        else {
					                	       MenuLocation();
					                	       break;
					                              }
                                      
                                      	aide2==1;
		                             }		aide1==1; } 
                                      if(aide2==0)
						            	{   printf(" \n\n................ le voiture a deja alouer :(  ..................\n\n");
									      	printf("	Vous voulez choisir une autre voiture (O/N)?");	
			                        	    
			                                if(getch()=='O')  listevoiture();
											else MenuLocation();	 
			            	            }
				                    if(aide1==0){
				                        	  printf("\n\n..........votre voiture n'existe pas !!!!:(......\n\n ");
                                              MenuLocation();
				                                }  	  
		                        } fclose(fp); 
								}  aide==1; }
		               }fclose(fs); 
								 if(aide==0) 
			            	  {
				    printf("         vous etre pas inscripte avec nous !!!      \n\n");
           	      printf("\n\n........ vous voulez inscrie maintenent   ?? (o/n)................. ");
  	                  if(getch()=='o') 
						{
  	  	                   ajouteclient(); 
						}
  	                  else{
  	                    	MenuLocation();
		                   }       
                }  
}

                //**********************************************
				//***   Modidier contrat                    ***
				//**********************************************
void Modifiercontrat(void){
		system("cls");
		system("color b4");
		int n=0;
		int d,e;
		
		printf("**\n\n\n***************Modifier la section des contrats**********\n\n\n**");
		char another='o';
		while(another=='o')
		{
			system("cls");
		
			printf("***taper le numero de contrat qui vous modifieer:***");
			scanf("%d",&d)
			;
			fc=fopen("contrat.dat","rb+");
			while(fread(&c,sizeof(c),1,fc)==1)
			{
				if(checkid3(d)==0)
				{
				
					printf("\n\n\n............ le contrat est disponible :) .................\n");
					
					printf("\n taper nouveau date de dubet  jj/mm/yy:\n");scanf("%d%d%d",&c.debut.dd,&c.debut.mm,&c.debut.yy);
					
					printf("\n taper nouveau date de fin jj/mm/yy:\n");scanf("%d%d%d",&c.fin.dd,&c.fin.mm,&c.fin.yy);
					
					
					printf("\n*****************L'enregistrement est modifié :) ****************************");
					fseek(fc,ftell(fc)-sizeof(c),0);
					fwrite(&c,sizeof(c),1,fc);
					fclose(fc);
					n=1;
				
				}
				if(n==0)
				{
					
					printf("\n ****************** Aucun Enregistrement Trouve :( **************************");
				}
			}
			
			printf("\n *****************Modifier un autre enregistrement?(o/n) *************************8");
			fflush(stdin);
			another=getch() ;
		}
	
	MenuLocation();
}



//int cout(int d){ 
//	rewind(fc);
//	while(fread(&c,sizeof(c),1,fc)==1);
//		rewind(fp);
//	while(fread(&a,sizeof(a),1,fp)==1);
//	a.prixJour * c.dure =c.cout;
//}return cot;

                 //**********************************************
				//***   Ajouter le contrat              ***
				//**********************************************
void ajoutecontrat(void){
	system("cls");
	system("color b4");
	fc=fopen("contrat.dat","ab");
//	while(fread(&c,sizeof(c),1,fc)==1){
	
puts("/n**************************************************************************************************/n");
	            	printf("\n\ntaper votre numro de contrat \n");
		             scanf("%d",&c.numContrat);
			        printf("\n ID de voiture : \n");
			        scanf("%d",&c.idVoiture);
			        printf("\n ID de client :\n ");
			        scanf("%d",&c.idClient);
                    printf("\ntaper votre dubet de date jj/mm/yy\n");
                     scanf("%d%d%d",&c.debut.dd,&c.debut.mm,&c.debut.yy);
                    printf("\ntaper votre fin de date jj/mm/yy  \n");
                     scanf("%d%d%d",&c.fin.dd,&c.fin.mm,&c.fin.yy);
                     fwrite(&a,sizeof(a),1,fp); 
	               enlocationsupp(c.idVoiture);
                 //   printf("\n\ntaper adresse de client\n ");
                   //  scanf("%d",&c.dure);
printf("\n**************************************************************************************************/n");
		  fwrite(&c,sizeof(c),1,fc);
	        fseek(fc,0,SEEK_END);
              fclose(fc);
                  printf("\t\t\t  ...........L'enregistrement est enregistré avec succes :)................\n");
                  MenuLocation();
} 
                //**********************************************
				//***   Retourner l   es voitures       ***
				//**********************************************

void Retournervoiture(void){
    system("cls");
    
	 	int id_voiture, id_client, num;	 	
	 	int test=0; // Pour tester si la retourne de voiture a ete reussi ou pas.
	 	
	 	fs=fopen("client.dat","rb+");
		fp=fopen("voiture.dat","rb+");
	 	fs=fopen("contrat.dat","rb+");
	 	printf("	** Retour de voiture **");
	 	printf("\n	=> Entrer l'id de voiture a retourner : ");
	 	scanf("%d",&id_voiture);
	 	
	 	if( a.idVoiture == id_voiture ){
	 		
	 		printf("\n	=> Entrer votre id de client  : ");
	 		scanf("%d",&id_client);
	 		if( b.idClient == id_client){
	 			
	 			printf("\n	=> Entrer le numero de votre contrat : ");
	 			scanf("%d",&num);
	 			if( c.numContrat == num  ){
	 					
	 					a.EnLocation=0;
	 					Supprimercontrat();
	 			}else{
			 		printf("	==> Numero de contrat n'existe pas! ");
			 		printf("	Ressayer a nouveau (O/N)? ");
			 		if(getch()=='O') Retournervoiture();
				 }
	 			
	 		}else{
		 		printf("	==> Id n'existe pas! ");
		 		printf("	Ressayer a nouveau (O/N)? ");
		 		if(getch()=='O') Retournervoiture();
			 }
	 		
		 }else{
		 	printf("	==> Id n'existe pas! ");
		 	printf("	Ressayer a nouveau (O/N)? ");
		 	if(getch()=='O') Retournervoiture();
		 }
		 fclose(fc);
		 fclose(fp);
		 fclose(fs);
}   
                //**********************************************
				//***   verifier le numero de contrat     ***
				//**********************************************
int checkid3(int d){
	rewind(fc);
	system("color b4");
	while(fread(&c,sizeof(c),1,fc)==1);

	if(c.numContrat==d)
	return 0;//existe
	return 1;//non existe
   }	
	             //**********************************************
				//***   supprimer contrat             ***
				//**********************************************
	
void Supprimercontrat(void){
	system("cls");
	system("color b4");
	int h;
	int y=0;
	printf("**************************************************************************************");
	 printf("           \n\n taper nemro de contrat qui vous voulez supprimer  \n\n          ");
	  scanf("%d",&h);
	         fc=fopen("contrat.dat","rb+");
             rewind(fc);
             while(fread(&c,sizeof(c),1,fc)==1){
	 	        if(checkid3(h)==0){
	 		     printf("\n\\t\t ................ le contrat est disponible :)...................\t\t");
			        printf("\n\t\t.................Voulez-vous le supprimer?(o/n) : ..................\t\n\t");
                                    if(getch()=='o'){
                            ftc=fopen("test2.dat","wb+");  //temporary file for delete
                              rewind(fc);
                                  while(fread(&c,sizeof(c),1,fc)==1){
                                         if(c.numContrat!=h){
                                        fseek(ftc,0,SEEK_CUR);
                                         fwrite(&c,sizeof(c),1,ftc); //write all in tempory file except that
                                     }                            }  //we want to delete
                                          fclose(ftc);  
                                          fclose(fc);
                                           remove("contrat.dat");
                               rename("test3.dat","contrat.dat"); //copy all item from temporary file to fp except that
			y++;
	 		printf("\n\t\t *************** L'enregistrement est supprimé avec succes :) ***************************\t\t\t");
	 		 }} sleep(5); 
	 		 if(y==0){
	 		 	puts("\n\n***********************************************************************************************************\n");
	           	printf("  \n        le contrat  n'existe pas dans le programe :) \a  \n          ");
		        puts("\n\n***********************************************************************************************************\n\n");
			  }
           }system("cls"); 
		     
	MenuLocation();}	
	
	
               	//**********************************************
				//***   changer location de voiture        ***
				//**********************************************
				
void enlocationsupp(int id){
	int t=1;
	int b=0;
	
  fp=fopen("voiture.dat","ab+");
  	while(fread(&a,sizeof(a),1,fp)==1){
	  
	if(a.EnLocation==t && a.idVoiture==id){
	a.EnLocation==0;
	fwrite(&a,sizeof(a),1,fp); 
	fseek(fp,ftell(fp)-sizeof(a),0);
	fclose(fp);	
	}
	if(a.EnLocation==b && a.idVoiture==id){
		a.EnLocation==1;
	fwrite(&a,sizeof(a),1,fp); 
	fseek(fp,ftell(fp)-sizeof(a),0);
	fclose(fp);	
	}
	 
    }  
	
}
//  La fonction date_a_jour()  prend en parametre une date et la converte a nombre de jour,elle retourne le nombre de jours.  
//int date_a_jour(struct date d) 
//{
//	int  m=(d.mois + 9) % 12;   
//	int  a=d.annee - (m >= 10); 
  //  return 1461*a/4 - a/100 + a/400 + (m*306 + 5)/10 + d.jour;
//}
	
	// La fonction jours() prend en parametre deux dates et retourne le nombre de jours entre ces deux dates.
//int jours( struct date d1 , struct date d2 ) 
//{
//	    return date_a_jour(d2) - date_a_jour(d1);
//	}
	
	/* La fonction cout() prend en parametre deux dates et un prix (prix par jour) , elle calcule la periode
	  entre lesdeux dates en utilisant les fonctions date_a_jour() et jours() ,puis elle retourne (le prix x la periode) = le cout total. */
//float cout(int prixJour,struct date d1, struct date d2)
//{
//	int nbjours;
//	float cout=0;
//	nbjours = jours(d1,d2);
//	cout = nbjours*prixJour;		
//	return cout;
//}
	
	


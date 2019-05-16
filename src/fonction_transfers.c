#include "fonction_transfers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *title (char* source, int id) {
	char *titre;
	int i = 0;
	titre = (char*) malloc(sizeof(char)*400)	;
	FILE* fichier = NULL;
	fichier = fopen(source, "r");
	char stock;
	if (fichier != NULL)
	{

		if (id < 10) 
		{

			while (stock != EOF) {
				if (stock == 48+id) {
					stock = fgetc(fichier);
					if (stock == '.') {
						break;
					}
				}
				stock = fgetc(fichier);

			}			
	 		stock = fgetc(fichier);
	 		stock = fgetc(fichier);
	 		stock = fgetc(fichier);
	 		while ((stock != '(') )
	 			{
	 				titre[i] = stock;
	 				i++;
	 				stock=fgetc(fichier);
	 			}
	 		titre[i]='\0';			
	 	}
	 	else if ((id < 100) && (id >= 10))
	 		{
	 		stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+(id/10)) {
					stock = fgetc(fichier);
					if (stock == 48 + (id%10)) {
						stock = fgetc(fichier);					
						if (stock == '.') {
							break;
						}
					}
				}
			}			
	 		stock = fgetc(fichier);
	 		stock = fgetc(fichier);
	 		stock = fgetc(fichier);
	 		while ((stock != '('))
	 			{
	 				titre[i] = stock;
	 				i++;
	 				stock=fgetc(fichier);
	 			}
	 			titre[i]='\0';		

	 		 }
	 	

	}
	
	 else 
	 {
	 	printf("ficher non trouvé");
	 }
	fclose(fichier);
	return titre;

}





 char **actors (char* source, int id) {
	char* acteur1;
	char* acteur2;
	char* acteur3;
	char** acteurs; 
	int j = 0;
	int i = 0;
	acteur1 = (char*) malloc(sizeof(char)*100);
	acteur2 = (char*) malloc(sizeof(char)*100);
	acteur3 = (char*) malloc(sizeof(char)*100);
	acteurs =  (char **)malloc(sizeof(char*)*3)	;
	FILE* fichier = NULL;
	fichier = fopen(source, "r");
	char stock;
	if (fichier != NULL)
	{
		if (id < 10) 
		{
			stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+id) {
					stock = fgetc(fichier);
					if (stock == '.') {
						break;
					}
				}
			}		
	 		while (stock != EOF )
	 			{
	 				stock = fgetc(fichier);	
	 				if (stock == 'W')
	 				{
	 					stock = fgetc(fichier);	
	 					if (stock == 'i')
	 					{
	 						stock = fgetc(fichier);	
	 						if (stock == 't')
	 						{
	 							stock = fgetc(fichier);
	 							if (stock == 'h')
	 							{
	 								stock = fgetc(fichier);
	 								stock = fgetc(fichier);
	 								if (stock = ':')
	 								{
	 									break;
	 								}
	 							}
	 						}
	 					}
	 				}
	 			}
	 		stock = fgetc(fichier);
	 		stock = fgetc(fichier);
	 		while (stock != ',')
	 			{
	 				acteur1[j] = stock;
	 				j++;
	 				stock = fgetc(fichier);
	 			}
	 				acteur1[j] = '\0';
	 				j=0;
	 				acteurs[0] = acteur1;
	 				stock = fgetc(fichier);
					stock = fgetc(fichier);

	 		while (stock != ',')
	 			{
					acteur2[j] = stock;
	 				j++;
	 				stock = fgetc(fichier);
				}
					acteur2[j] = '\0';
	 				j=0;
	 				acteurs[1] = acteur2;
	 				stock = fgetc(fichier);
	 				stock = fgetc(fichier);
			while (stock != '\n')
	 			{
					acteur3[j] = stock;
	 				j++;
	 				stock = fgetc(fichier);
	 			}
	 				acteur3[j] = '\0';
	 				j=0;
	 				acteurs[2] = acteur3;
	 				stock = fgetc(fichier);
	 	}	
	 	else if ((id < 100) && (id >= 10))
	 		{
	 		stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+(id/10)) {
					stock = fgetc(fichier);
					if (stock == 48 + (id%10)) {
						stock = fgetc(fichier);					
						if (stock == '.') {
							break;
						}
					}
				}
			}				
		 		while (stock != EOF )
	 			{	
	 				stock = fgetc(fichier);	
	 				if (stock == 'W')
	 				{
	 					stock = fgetc(fichier);	
	 					if (stock == 'i')
	 					{
	 						stock = fgetc(fichier);	
	 						if (stock == 't')
	 						{
	 							stock = fgetc(fichier);
	 							if (stock == 'h')
	 							{
	 								stock = fgetc(fichier);
	 								stock = fgetc(fichier);
	 								if (stock = ':')
	 								{
	 									break;	
	 								}
	 							}
	 						}
	 					}
	 				}
	 			}
	 		stock = fgetc(fichier);
	 		stock = fgetc(fichier);
	 		while (stock != ',')
	 			{
	 				acteur1[j] = stock;
	 				j++;
	 				stock = fgetc(fichier);
	 			}
	 				acteur1[j] = '\0';
	 				j=0;
	 				acteurs[0] = acteur1;
	 				stock = fgetc(fichier);
					stock = fgetc(fichier);
	 		while (stock != ',')
	 			{
					acteur2[j] = stock;
	 				j++;
	 				stock = fgetc(fichier);
				}
					acteur2[j] = '\0';
	 				j=0;
	 				acteurs[1] = acteur2;
	 				stock = fgetc(fichier);
	 				stock = fgetc(fichier);
			while (stock != '\n')
	 			{
					acteur3[j] = stock;
	 				j++;
	 				stock = fgetc(fichier);
	 			}
	 				acteur3[j] = '\0';
	 				j=0;
	 				acteurs[2] = acteur3;
	 				stock = fgetc(fichier);
		}
	}
	 else 
	 {
	 	printf("ficher non trouvé");
	 }
	fclose(fichier);
	return acteurs;

 }








 char ** tags (char* source,int id) {
 	char ** tags;
 	tags = malloc(sizeof(char*)*6);
 	int i = 0 ;
 	int j =1 ;
 	char stock;
 	for(int i=0; i<6; i++){
	    tags[i] = malloc(40 * sizeof(char));
	}
 	FILE* fichier = NULL;
 	int longeurlastwith;
 	fichier = fopen(source, "r");
 	if (fichier != NULL)
 	{
 		if (id < 10) 
		{
			stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+id) {
					stock = fgetc(fichier);
					if (stock == '.') {
						break;
					}
				}
			}		

			while(stock != '|'){
				stock = fgetc(fichier);
			}
						tags[0][0]=' ';

 			while (((stock<48)||(stock>57))&&(stock != '.')&&(stock != '\n')&&(stock!=EOF)){
 				stock=fgetc(fichier);
 				while ((stock != '|')&&((stock<48)||(stock>57))&&(stock != '.')&&(stock != '\n')&&(stock!=EOF)) {
 					tags[i][j]=stock;
	 				stock=fgetc(fichier);
 					j++;
 				}
 				tags[i][j]='\0';	
 				j=0;
 				i++;
 			}
 			while (i<6) {
 				tags[i]="NA";
 				i++; 
 			}

 		}

 		else if ((id < 100) && (id >= 10))
	 		{
	 		stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+(id/10)) {
					stock = fgetc(fichier);
					if (stock == 48 + (id%10)) {
						stock = fgetc(fichier);					
						if (stock == '.') {
							break;
						}
					}
				}
			}	

			while(stock != '|'){
				stock = fgetc(fichier);
			}
			tags[0][0]=' ';

 			while (((stock<48)||(stock>57))&&(stock != '.')&&(stock != '\n')&&(stock!=EOF)){
 				stock=fgetc(fichier);
 				while ((stock != '|')&&((stock<48)||(stock>57))&&(stock != '.')&&(stock != '\n')&&(stock!=EOF)) {
 					tags[i][j]=stock;
	 				stock=fgetc(fichier);
 					j++;
 				}
 				tags[i][j]='\0';	
 				j=0;
 				i++;

 			}
 			while (i<6) {
 				tags[i]="NA";
 				i++; 
 			}

 		}
 	}
 	else {
 		printf("ficher non trouvé");
 	}
 	fclose(fichier);
 	return tags;
 }

  int year ( char * source, int id) {
  	int*  year;
  	int *yearint;
  	yearint =malloc(sizeof(int));	
  	int i = 0;
  	year = (int*)malloc(sizeof(int)*4);
  	FILE* fichier = NULL;
  	fichier = fopen(source, "r");
  	char stock;
  	if (fichier != NULL)
	{

		if (id < 10) 
		{
			stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+id) {
					stock = fgetc(fichier);
					if (stock == '.') {
						break;
					}
				}
			}			
	 		while ((stock != '(') && (stock != EOF ))
	 			{
	 				stock=fgetc(fichier);
	 			}
	 		year[0] =  fgetc(fichier)-48;
	 		year[1] =  fgetc(fichier)-48;
	 		year[2] =  fgetc(fichier)-48;
	 		year[3] =  fgetc(fichier)-48;
	 		
	 		
				
	 	}
	 	else if ((id < 100) && (id >= 10))
	 		{
	 		stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+(id/10)) {
					stock = fgetc(fichier);
					if (stock == 48 + (id%10)) {
						stock = fgetc(fichier);					
						if (stock == '.') {
							break;
						}
					}
				}
			}			

	 		while ((stock != '(') && (stock != EOF ))
	 			{
					stock=fgetc(fichier);
	 			}
	 		year[0] =  fgetc(fichier)-48;
	 		year[1] =  fgetc(fichier)-48;
	 		year[2] =  fgetc(fichier)-48;
	 		year[3] =  fgetc(fichier)-48;
	 		 }
	 	

	}
	
	 else 
	 {
	 	printf("ficher non trouvé");
	 }
	fclose(fichier);
	*yearint = year[0]*1000 +year[1]*100 + year[2]*10 + year[3];
  	return *yearint;
  }

char * type(char * source, int id) {
 	char *  type1;
 	char stock;
 	type1 = (char*) malloc(sizeof(char)*50);
 	FILE* fichier = NULL;
 	fichier = fopen(source, "r");
 	if (fichier != NULL)
 	{
 		
		if (id < 10) 
		{
			stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+id) {
					stock = fgetc(fichier);
					if (stock == '.') {
						break;
					}
				}
			}

			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == '(')
				{

					stock = fgetc(fichier);
					stock = fgetc(fichier);
					stock = fgetc(fichier);
					stock = fgetc(fichier);
					stock = fgetc(fichier);

					if (stock == ')')
					{
						type1 = "Movie";
						break;

					}
					else 
					{
						type1 = "Tv Show";
						break;

					}
				}
			}			
	 	}
	 	else if ((id < 100) && (id >= 10))
	 		{
	 		stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+(id/10)) {
					stock = fgetc(fichier);
					if (stock == 48 + (id%10)) {
						stock = fgetc(fichier);					
						if (stock == '.') {
							break;
						}
					}
				}
			}

			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == '(')
				{
					stock = fgetc(fichier);
					stock = fgetc(fichier);
					stock = fgetc(fichier);
					stock = fgetc(fichier);
					stock = fgetc(fichier);

					if (stock == ')')
					{
						type1 = "Movie";
						break;
					}
					else 
					{
						type1 = "Tv Show";
						break;
					}
				}
			}			

		}
	}
	
	 else 
	 {
	 	printf("ficher non trouvé");
	 }
	fclose(fichier);
  	return type1;
 }



 char * director (char* source,int id) {
 	char * director;
 	int i = 0;
 	char stock;
 	director = (char*) malloc(sizeof(char)*100)	;
 	FILE* fichier = NULL;
 	fichier = fopen(source, "r");
 	if (fichier != NULL)
 	{
 		if (id < 10) 
		{
			stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+id) {
					stock = fgetc(fichier);
					if (stock == '.') {
						break;
					}
				}
			}

			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == '.') {
					stock = fgetc(fichier);
					if (stock == ' ') {
						stock = fgetc(fichier);
						if (stock == '\n') {
							stock = fgetc(fichier);
							break;
						}
					}				
				}	
			}
			
			if (stock == 'W') {
				director = "NA";
			}

			else {

				while (stock != EOF )
	 				{
	 					if (stock == 'D')
	 					{
	 						stock = fgetc(fichier);	
	 						if (stock == 'i')
	 						{
	 							stock = fgetc(fichier);	
	 							if (stock == 'r')
	 							{
	 								stock = fgetc(fichier);
	 								if (stock == 'e')
	 								{
	 									stock = fgetc(fichier);
	 									if (stock == 'c')
	 									{
	 										stock = fgetc(fichier);
	 										if (stock == 't')
	 										{
	 											stock = fgetc(fichier);
	 											if (stock == 'o')
	 											{
	 												stock = fgetc(fichier);
	 												if (stock == 'r')
	 												{
	 													stock = fgetc(fichier);
	 													stock = fgetc(fichier);
	 													if (stock = ':')
	 													{
	 														break;
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
	 			stock = fgetc(fichier);
	 			stock = fgetc(fichier);
	 			while (stock != '\n') {
	 				director[i] = stock;
	 				i++;
	 				stock = fgetc(fichier);
	 			}
	 			director[i] = '\0';

	 		}
	 	}		
	 	else if ((id < 100) && (id >= 10))
	 		{
	 		stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+(id/10)) {
					stock = fgetc(fichier);
					if (stock == 48 + (id%10)) {
						stock = fgetc(fichier);					
						if (stock == '.') {
							break;
							}
						}
					}
				}

			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == '.') {
					stock = fgetc(fichier);
					if (stock == ' ') {
						stock = fgetc(fichier);
						if (stock == '\n') {
							stock = fgetc(fichier);
							break;
						}
					}				
				}	
			}
			
			if (stock == 'W') {
				director = "NA";
			}

			else {

				while (stock != EOF )
	 				{
	 					if (stock == 'D')
	 					{
	 						stock = fgetc(fichier);	
	 						if (stock == 'i')
	 						{
	 							stock = fgetc(fichier);	
	 							if (stock == 'r')
	 							{
	 								stock = fgetc(fichier);
	 								if (stock == 'e')
	 								{
	 									stock = fgetc(fichier);
	 									if (stock == 'c')
	 									{
	 										stock = fgetc(fichier);
	 										if (stock == 't')
	 										{
	 											stock = fgetc(fichier);
	 											if (stock == 'o')
	 											{
	 												stock = fgetc(fichier);
	 												if (stock == 'r')
	 												{
	 													stock = fgetc(fichier);
	 													stock = fgetc(fichier);
	 													if (stock = ':')
	 													{
	 														break;
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
	 			stock = fgetc(fichier);
	 			stock = fgetc(fichier);

	 			while (stock != '\n') {
	 				director[i] = stock;
	 				i++;
	 				stock = fgetc(fichier);
	 			}
	 			director[i] = '\0';
	 		}
	 	}				


	}
	
	 else 
	 {
	 	printf("ficher non trouvé");
	 }
	fclose(fichier);
 	return director;
 }

int duration (char* source, int id) {
 	int * duration;
 	char * dur;
 	dur = (char*) malloc(sizeof(char)*4);
 	char stock;
 	duration =  malloc(sizeof(int));
 	FILE* fichier = NULL;
 	fichier = fopen(source, "r");
 	if (fichier != NULL)
 	{

		if (id < 10) 
		{
			stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+id) {
					stock = fgetc(fichier);
					if (stock == '.') {
						break;
					}
				}
			}		

			while(stock != '|'){
				stock = fgetc(fichier);
			}
 			while ((stock != '.')&&(stock != '\n')&&(stock!=EOF)){
 				stock=fgetc(fichier);
 				while ((stock != '.')&&(stock != '\n')&&(stock!=EOF)) {
 					if (((stock>=48)&&(stock<=57)))
 					{
 						dur[0] = stock;
 						stock = getc(fichier);
 						if (stock != ' ')
 						{
 							dur[1]=stock;
 							stock = fgetc(fichier);
 							if (stock != ' ')
 							{
 								dur[2] = stock;
 							}
 						}
 					}
	 				stock=fgetc(fichier);
 				}

 			}
 			*duration = 0;
 			 	dur[3]='\0';
 			 	int i;
 			 	int j = 100;
 			 if ((dur[2] >= 48) && (dur[2]<=57))
 			 {
 			 	
 			 
 			 	for (int i = 0; i < 3; ++i)
 			 	{
 			 		if ((dur[i] >= 48) && (dur[i]<=57))
 			 		{
 			 			*duration = *duration + (dur[i]-48)*j;
 			 			j=j/10;
 			 		}
 			 	}
 			}

 			if (((dur[1] >= 48) && (dur[1]<=57))&&((dur[2] < 48) || (dur[2]>57)))
 			{
 				j=10;
 				for (int i = 0; i < 2; ++i)
 			 	{
 			 		if ((dur[i] >= 48) && (dur[i]<=57))
 			 		{
 			 			*duration = *duration + (dur[i]-48)*j;
 			 			j=j/10;
 			 		}
 			 	}
 			}



 			if(((dur[0] < 48) || (dur[0]>57)))
 			{
 				return 0;
 			}
 		}

 		else if ((id < 100) && (id >= 10))
	 		{
	 		stock = fgetc(fichier);
			while (stock != EOF) {
				stock = fgetc(fichier);
				if (stock == 48+(id/10)) {
					stock = fgetc(fichier);
					if (stock == 48 + (id%10)) {
						stock = fgetc(fichier);					
						if (stock == '.') {
							break;
						}
					}
				}
			}	

			while(stock != '|'){
				stock = fgetc(fichier);
			}
 			while ((stock != '.')&&(stock != '\n')&&(stock!=EOF)){
 				stock=fgetc(fichier);
 				while ((stock != '.')&&(stock != '\n')&&(stock!=EOF)) {
 					if (((stock>=48)&&(stock<=57)))
 					{
 						dur[0] = stock;
 						stock = getc(fichier);
 						if (stock != ' ')
 						{
 							dur[1]=stock;
 							stock = fgetc(fichier);
 							if (stock != ' ')
 							{
 								dur[2] = stock;
 							}
 						}
 					}
	 				stock=fgetc(fichier);
 				}

 			}
 			*duration = 0;
 			 	dur[3]='\0';
 			 	int i;
 			 	int j = 100;
 			 if ((dur[2] >= 48) && (dur[2]<=57))
 			 {
 			 	
 			 
 			 	for (int i = 0; i < 3; ++i)
 			 	{
 			 		if ((dur[i] >= 48) && (dur[i]<=57))
 			 		{
 			 			*duration = *duration + (dur[i]-48)*j;
 			 			j=j/10;
 			 		}
 			 	}
 			}

 			if (((dur[1] >= 48) && (dur[1]<=57))&&((dur[2] < 48) || (dur[2]>57)))
 			{
 				j=10;
 				for (int i = 0; i < 2; ++i)
 			 	{
 			 		if ((dur[i] >= 48) && (dur[i]<=57))
 			 		{
 			 			*duration = *duration + (dur[i]-48)*j;
 			 			j=j/10;
 			 		}
 			 	}
 			}



 			if(((dur[0] < 48) || (dur[0]>57)))
 			{
 				return 0;
 			}

 		} 

 	}
 
 	else {
 		printf("ficher non trouvé");
 	}
 	fclose(fichier);
 	return *duration; 
 }


/*int main(int argc, char const *argv[]) {	
	int i ;
	for (int i = 1; i <100; ++i)
	{
		printf("%d   : \nTitre : %s  \nType :  %s  \nAnnée : %d   \nRéalisateur :  %s   \nActeurs :  %s  %s   %s \nDurée : %d  \nTags :%s,%s,%s,%s,%s,%s \n \n",i,title("BDCSD.txt",i) ,type("BDCSD.txt",i),year("BDCSD.txt",i),director("BDCSD.txt",i),
		actors("BDCSD.txt",i)[0],actors("BDCSD.txt",i)[1],actors("BDCSD.txt",i)[2], duration("BDCSD.txt",i),tags("BDCSD.txt",i)[0],tags("BDCSD.txt",i)[1],
		tags("BDCSD.txt",i)[2],tags("BDCSD.txt",i)[3],tags("BDCSD.txt",i)[4],tags("BDCSD.txt",i)[5] );
	}

	//printf("%s\n",title("BDCSD.txt",1) );

	return 0;
 }*/

/*
Titulo : WeThinkCenter
Autores:
Hugo García Las Heras
Rafael García Gómez
Susana González Miguel
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30
#include <windows.h>
#include <conio.h>
struct persona
{
	int DNI;
	char nombre[N];
	int PIN;
	float dinero;
};
struct evento
{
	char nombre [N];
	int dia;
	char mes;
	float precio;
};
// Aquí habría que poner la función de contrar los digitos (falta de hacer
void main()

{
int DNI,PIN,dia,i,elige,digitos,comp;
float dinero;
char nombre[N];
FILE *registro; 
int contareg=0;
struct persona usuarios [N];

registro = fopen("registro.txt","r");
if (registro==NULL)
{
	printf("No se ha podido abrir el fichero correctamente\n");
	return -1;
}
else 
{
	while (fscanf(registro,"%i  %s\t%i\t%i\t%f\t",&contareg,usuarios[contareg].nombre,&usuarios[contareg].DNI,&usuarios[contareg].PIN,&usuarios[contareg].dinero)!=EOF)
	{
		contareg++;
		if(contareg!=0)
		{
			contrareg=contrareg-1;
		}
	}
}
fclose(registro);
// Aquí faltaria la gestión del fichero de eventos ( ya creado en git hub)

do 
{
	printf("--HOLA! BIENVENIDO AL WE THINK CENTER\n");
	printf("\n");
	printf("Escoja cual es su caso:\n");
	printf("1 No tiene cuenta, desea crear una cuenta:\n");
	printf("2 Dispone de cuenta exisistente, desea iniciar sesion:\n");
	fflush(stdin);
	scanf("%i",&elige);	
	printf("\n");
	volver=0;
	
		switch(elige)
		{
			case 1:
				{
					do
				    {
				      printf("Introduzca su nombre:\n");
					  scanf("%s",usuarios[contareg].nombre);
					  x=contareg;
					  
					  registro= fopen("registro.txt","r");
					  if(registro== NULL)
					  {
					  	printf("Disculpa, el fichero no pudo abrirse correctamente. \n");
					  	return -1;
					  }
					  else
					   {
					  
					    i=0;
					    while(fscanf(registro,"%i  %s\t%i\t%i\t%f\t",&i+1,usuarios[i].nombre,&usuarios[i].DNI,&usuarios[i].pin,&usuarios[i].dinero)!=EOF)
					    {
					     	comp=strcmp(usuarios[i].nombre,usuarios[x].nombre);
					     	//Aqui comparo el nombre introducido por el usuario con los nombres que estan en el fichero de registrados
					     	if(comp==0);
					     	{
					     	   printf("Dicho nombre escrito ya existe, intentelo otra vez con otro nombre.\n");
					     	   break;
							}
							else if (i==x-1 ||contareg==0)
							{
								printf("El nombre introducido ha quedado guardado \n");
								break;
							}
							i++;
						}
					}	
					while(comp==0 && x!=0);
					
					do
					{
						digitos=0;					
						printf("\nIntroduzca su DNI (sin poner la letra):\n");
						scanf("%i",&usuarios[contareg].DNI);
						digitos = cuenta_digitos(usuarios[contareg].DNI);
						if(digitos>=9)
						{
							printf("Su DNI sobrepasa el numero de digitos correcto. Repita con otro\n");
						}
					
					}while(digitos>=9);
					
					digitos=0;
					do
					{
			
						
						printf("\nIntroduzca su PIN (unicamente cuatro cifras):\n");
						scanf("%i",&usuarios[contareg].pin);
						digitos = cuenta_digitos(usuarios[contareg].pin);
						if(digitos>=5)
						{
							printf("Su codigo PIN sobrepasa el numero de digitos admitido. Pruebe con otro mas corto\n");
						}
						
					}while(digitos>=5);
							
					contareg++;
						
					registro = fopen("registro.txt","w");
					if(registro==NULL)
					{
						printf("Error al abrir el fichero\n");
						return -1;
					}
					else
					{
						
						i=0;
						while(i<contareg)
						{
							fprintf(registro,"%i  %s\t%i\t%i\t%.3f\n",i+1,usuarios[i].nombre,usuarios[i].DNI,usuarios[i].pin,usuarios[i].dinero);
							i++;
						}
						printf("Su cuenta ha sido creada correctamente");
						printf("Debe presionar cualquier tecla para pasar al menu");
						getch();
					}
					fclose(registro);
					volver=1;
					break;	
				    
				}
		}
		
		
}
}

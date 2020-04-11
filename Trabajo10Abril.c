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
int DNI,PIN,dia,i,elige,digitos=0,comp;
float dinero;
int dnint,pinint,nombrepos;
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
	printf("HOLA! BIENVENIDO AL WE THINK CENTER\n");
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
		        case 2:
				{
					if(contareg==0)
					{
						printf("No hay ninguna cuenta creada aún.Debe crear una cuenta antes.");
						break;
					}
					else
					{
						registro=fopen("registro.txt","r");
						if(registro==NULL)
						{
							printf("El fichero no se pudo abrir\n");
							return -1;
						}
						else
						{
							i=0;
							do
							{
								do
								{
									printf("Introduzca su nombre de usuario:\n\n");
									scanf("%s",nombre);
									printf("\n");
									//Aqui compara el npmbre metido con los que estan en el fichero de registrados
									for(i=0;i<contareg;i++)
									{
										comp=strcomp(nombre,usuarios[i].nombre);
										if(comp==0)
										{
											printf("El nombre es correcto. Puede continuar\n");
											nombrepos=i;
											break;
										}
										else if(i==contareg-1)
										{
											printf("Su nombre es incorrecto.Pruebe otra vez\n\n");
										}
									}
								}while(comp==1||comp==-1);
								//Si el nombre de usuario no está en el fichero permite meter otro
								
								do
								{
									
									printf("Introduzca su DNI:\n");
									scanf("%i",&dnint);
									printf("Introduzca su codigo PIN:\n");
									scanf("%i",&pinint);
									//Aquí hago lo mismo que antes pero con el dni y el pin, deben cumplir las dos opciones para iniciar sesion
									
									if(pinint == usuarios[nombrepos].PIN && dnint == usuarios[nombrepos].DNI)
									{						
										printf("Ha introducido el PIN y el DNI satisfactoriamente. Bienvenido al menu de usuario del We think center\n");	
									}
									else
									{
									printf("El pin o el dni, o ambos estan mal introducidos.Pruebe otra vez\n");
									}
									
								}while (pinint!=usuarios[nombrepos].pin || dniint!=usuarios[nombrepos].DNI);
								//Permite introducir los dni y el pin mas de una vez al usar este bucle
								fclose(registro);
							
							}while(fscanf(registro,"%i  %s\t%i\t%i\t%f\t",&contareg,usuarios[contareg].nombre,&usuarios[contareg].DNI,&usuarios[contareg].PIN,&usuarios[contareg].dinero)!=EOF);
						}
						//Aquí ya tendriamos la sesion iniciada al usar el while para leer el registro
				
					printf("Presione cualquier tecla para continuar: ");
					getch();
					break;
					
					}	
				}
			}
		}while(elige!=1 && elige!=2);
	    }while(volver==1);
	}
		
//Aquí falta meter el segundo menu con las opciones de eventos y que se repita el menu si no se marca una de las opciones del menu
// Propongo poner 1 consultar eventos, 2comprar entradas de dicho tipo( diferenciando entre nuestros tipos de evento),3 reservar el espacio en una nueva fecha y definiendo nosotros el coste del espacio
		
}
}

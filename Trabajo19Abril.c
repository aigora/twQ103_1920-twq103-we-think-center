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
#define N 100
#define S 200
#include <windows.h>

struct persona
{
	int DNI;
	char nombre[N];
	int PIN;
	float dinero;
};
struct evento
{
	char categoria [10];
	int dia;
	char mes;
	char descripcion[30];
	float precio;

};
// Deberíamos de establecer un numero maximo de entradas para cada evento y que esto haga que no puedan apuntarse todos los usuarios que quieran
void main()

{
int DNI,PIN,dia,i,elige,digitos=0,comp;
float dinero;
int elige;
int dnint,pinint,nombrepos;
char nombre[N];
FILE *registro;
FILE *feventos; 
int contareg=0;
struct persona usuarios [N];
struct evento center [S];
int nEventos=0;

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
		

do{
	printf("Se encuentra en el menú de gestión del sistema\n");
	printf("\n");
	printf("Elija lo que desea hacer\n");
	printf("1-Consulte los eventos disponibles\n");
	printf("2-Reserva de entradas de los eventos disponibles\n");
	printf("3-Creación y reserva de un nuevo evento");
	scanf("%i",&opcion);
	printf("\n");
	
	switch(opcion){
		case 1:
			{
			    printf("A continuación se mostrará un listado de los eventos disponibles\n");
			    printf("Se mostrarán todos, independientemente de la categoría\n");
			    feventos =fopen("eventos.txt","r");
			    if(eventos==NULL)
			    {
			    	printf("Error al abrir el fichero correctamente\n");
			    	return -1;
				}
				else
				{
					while(fscanf(feventos,"%s %i %s %s %f",center[nEventos].categoria,&center[nEventos].dia,center[nEventos].mes,center[nEventos].descripcion,&center[nEventos].precio)!=EOF)
					{
						printf("%s %i %s %s %f\n",center[nEventos].categoria,&center[nEventos].dia,center[nEventos].mes,center[nEventos].descripcion,&center[nEventos].precio);
						nEventos++;
						printf("Presione cualquier tecla para continuar\n");
						getchar();
						break;
					}
				}	
			}
			
		case 2:
		    {
		    	//Aquí es donde hay que meter funcion con algun tipo de descuento si reservas mas de un evento
		    	//Preguntar la duda de como establecer el maximo de entradas disponibles por evento
		    	
			
		
			}	
	}
	
	
} while(opcion!=numero);		
}
}

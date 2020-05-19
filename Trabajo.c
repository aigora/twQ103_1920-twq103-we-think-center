#include<stdio.h>
#include<string.h>
struct persona{
	char DNI[10];
	char nombre[100];
	int PIN;
};
struct calendario{
	int dia;
	int mes;
	char eventos[50];
	float precio;
	
};
int main(){
	int elige,i,comp1,comp2,comp3,opcion,n=0,contEvento=0;
	char eleccion;
	int rebaja;
	FILE*registro;
	FILE*evento;
	struct persona alta[100];
	struct calendario programa[4];
	int contareg=0;
	FILE*descuento;
	char codigo[20],codigo1[20];
	int m,comp4=0;
	
	printf("Bienvenido al We-Think-Center\n\n");
	printf("Escoja cual es su caso:\n");
	printf("1-No tiene cuenta, desea crear una cuenta:\n");
	printf("2-Dispone de cuenta existente, desea iniciar sesion:\n");
	scanf("%i",&elige);	
	printf("\n");
	
	switch (elige){
	
		case 1:
			registro=fopen("Registro2.txt","r");
			if (registro==NULL){
				printf("No se ha podido abrir el fichero Registro2 correctamente\n");				
				return 0;
			}
			while(fscanf(registro,"%d %s %s %d",&contareg+1,alta[contareg].nombre,alta[contareg].DNI,&alta[contareg].PIN)!=EOF){
				printf("%d %s %s %d\n\n",contareg+1,alta[contareg].nombre,alta[contareg].DNI,alta[contareg].PIN);
				contareg++;
			}
			i=contareg+1;
			do{
				
				printf("Introduzca su nombre de usuario:\n");
				scanf("%s",alta[i].nombre);
				for(contareg=0;contareg<i;contareg++){
					comp1=strcmp(alta[contareg].nombre,alta[i].nombre);
					if(comp1==0){
						printf("Ha seleccionado un nombre usuario existente\n");
						break;
					}
					else if(comp1==1){
						printf("El nombre introducido ha quedado guardado\n");
						break;
					}
				}
			}while(comp1==0);
			
			fclose(registro);
				registro=fopen("Registro2.txt","w");
			if (registro==NULL){
				printf("No se ha podido abrir el fichero Registro2 correctamente\n");				
				return 0;
			}
		
			printf("Introduzca su DNI:\n");
			scanf("%s",alta[i].DNI);
			printf("Introduzca su nuevo PIN:\n");
			scanf("%d",&alta[i].PIN);
			printf("%d %s %s %d\n",i,alta[i].nombre,alta[i].DNI,alta[i].PIN);
			
			for(i=0;i<contareg;i++){
				fprintf(registro,"%d %s %s %d\n",i,alta[i].nombre,alta[i].DNI,alta[i].PIN);
				printf("%d %s %s %d\n",i,alta[i].nombre,alta[i].DNI,alta[i].PIN);
			}
			fclose(registro);
			break;
			
		case 2:
			registro=fopen("Registro2.txt","r");
			if (registro==NULL){
				printf("No se ha podido abrir correctamente el fichero\n");
				return 0;
			}
			while(fscanf(registro,"%d %s %s %d",&contareg+1,alta[contareg].nombre,alta[contareg].DNI,&alta[contareg].PIN)!=EOF){
				contareg++;
			}
			i=contareg+1;
			do{
				printf("Introduzca su nombre de usuario:\n");
				scanf("%s",alta[i].nombre);
				for(contareg=0;contareg<i;contareg++){
					comp1=strcmp(alta[contareg].nombre,alta[i].nombre);
					if(comp1==0){
						do{
							printf("Introduzca su codigo PIN para verificar su identidad:\n");
							scanf("%d",alta[i].PIN);
							for(contareg=0;contareg<i;contareg++){
								comp2=strcmp(alta[contareg].PIN,alta[i].PIN);
								if(comp2==0){
									printf("Bienvenido al We-Think-Center\n");
									break;
								}else if(comp2==1){
									printf("Ha introducido un PIN incorrecto, vuelva a introducirlo de nuevo\n");
									break;
								}
							}
						}while(comp2==1);
						break;
					}
					else if(comp1==1){
						printf("Ha introducido un nombre incorrecto\n");
						printf("Vuelva a introducirlo de nuevo\n");
						break;
					}
				}
			}while(comp1==1);
			fclose(registro);
			break;
	}
	
	printf("Se encuentra en el menu de gestion del sistema\n");
	printf("\n");
	printf("Elija lo que desea hacer\n");
	printf("1-Consulte los eventos disponibles\n");
	printf("2-Reserva de entradas de los eventos disponibles\n");
	scanf("%i",&opcion);
	printf("\n");
	
	switch(opcion){
		
		case 1:
			evento=fopen("Eventos.txt","r");
			if(evento==NULL){
				printf("No se ha podido abrir el fichero de eventos\n");
				return 0;
			}
			while(fscanf(evento,"%d %d %d %s %f",&programa[n].dia,&programa[n].mes,2020,programa[n].eventos,&programa[n].precio)!=EOF){
				printf("%0d / %0d / 2020 %s %f\n",programa[n].dia,programa[n].mes,programa[n].eventos,programa[n].precio);
				n++;
			}
			fclose(evento);
		break;
		
		case 2:
			evento=fopen("Eventos.txt","r");
			if(evento==NULL){
				printf("No se ha podido abrir el fichero de eventos\n");
				return 0;
			}
			while(fscanf(evento,"%d %d %s %f",&programa[n].dia,&programa[n].mes,programa[n].eventos,&programa[n].precio)!=EOF){
				n++;
			}
			contEvento=n+1;
			do{
				printf("Introduzca el nombre del evento al que quiere asistir:");	
				scanf("%s",programa[contEvento].eventos);
					for(i=0;i<n;i++){
						comp3=strcmp(programa[contEvento].eventos,programa[n].eventos);
						if(comp3==0){
							printf("Usted ha elegido que quiere ir a %s para el dia %d del %d\n",programa[n].eventos,programa[n].dia,programa[n].mes);
							printf("Esta seguro si(s) o no(n): ");
							scanf("%c",eleccion);
							if(eleccion=='s'){
								printf("El precio de dicho evento es de %.2f\n",programa[n].precio);
								printf("Tiene usted algun tipo de descuento de los siguientes:\n");
								printf("1-Carnet joven\n");
								printf("2-Carnet universitario\n");
								printf("3-Codigo de descuento\n");
								scanf("%d",&rebaja);
								
								switch(rebaja){
									case 1:
										programa[n].precio=programa[n].precio*0.85;
										printf("El precio de su entrada es de %.2f\n",programa[n].precio);
										printf("Debera llevar consigo el carnet joven\n");
										break;
									case 2:
										programa[n].precio=programa[n].precio*0.85;
										printf("El precio de su entrada es de %.2f\n",programa[n].precio);
										printf("Debera llevar consigo el carnet universitario\n");
										break;
									case 3:
											descuento=fopen("DESCUENTOS.txt","r");
											if(descuento==NULL){
												printf("No se ha podido abrir el fichero descuentos correctamente\n");
												return 0;
											}
											while(fscanf(descuento," %d %s",&m,codigo)!=EOF){
												printf("%s\n",codigo);
												m++;
											}
											
											printf("Introduzca el codigo de descuento:\n");
											scanf("%s",codigo1);
											
											for(m=0;m<4;m++){
												comp4=strcmp(codigo1,codigo);
											}
											if(comp4==1){
												printf("Dicho codigo no tiene validez\n");
											}
											else if(comp4==0){
												printf("El codigo %s tiene validez\n",codigo1);
											}
											fclose(descuento);
										
								}
							}
						}
						if(comp3==1){
							printf("No ha elegido un evento existente en el calendario\n");
						}
					}
			}while(comp3==1 || eleccion=='n');
			
			fclose(evento);
			
		break;	
	}
	printf("Muchas gracias por visitarnos!\n");
	printf("Vuelva pronto!\n");
			
	}


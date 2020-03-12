#include<stdio.h>
int main(){
	int opcion;
	
	printf("Bienvenido al WeThinkCenter!\n\n");
	printf("Seleccione a que evento quiere asistir:\n");
	printf("1-CONCIERTOS\n");
	printf("2-BALONCESTO\n");
	printf("3-EVENTO DE EMPRESA\n");
	scanf("%d",&opcion);
	
	switch (opcion){
		case 1: printf("Consulte las fechas de tu artista favorito");
		break;
		case 2: printf("Consulte las fechas para animar a tu equipo");
		break;
		case 3: printf("Consulte las empresas organizadoras");
		
	default:
		printf("Opcion incorrecta");
	}
}

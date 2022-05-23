/*AUTOR:OSCAR VIVALDI PARTIDO RAMIREZ FECHA DE INICIO:17 DE MAYO DEL 2022
		CONTROL DE EQUIPOS DE COMPUTO ASIGNADO A ADMINISTRATIVOS 
		0-	Salir 
		1-	Agregar equipo
		2-	Listar todos los equipos 
		3-	Listar las PCS
		4-	listar las Laptops 
		5- 	Buscar el equipo asignado a un administrativo
		6-	Reasignar equipo 
		7-	Guardar archivo
		8-	Cargar archivo
*/
//LIBRERIAS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "milibreria.h"
#define MAX_BUFFER 20
//declaraciones globales 
#define MAX 5
struct computadora{
	char serie[10];
	char modelo[10];
	char tipoComputadora[10];
	char trabajador[20];
	char edificio[5];
	char area[5];
	char busqueda[10];

};
int n=0;

//prototipos
int menu();
int validarEnteros(int inferior, int superior);
void agregar(struct computadora x[]);
void listarEquipos(struct computadora x[]);
void listarPc(struct computadora x[]);
void listarLaptops(struct computadora x[]);
void guardar(struct computadora x[]);
void cargar(struct computadora x[]);
void buscar_Equipos(struct computadora x[]);
void reasignar_Equipo(struct computadora x[]);


//principal
int main(){
	int opcion;
	struct computadora equipos[MAX];
	
	do{
		opcion=menu();
		switch(opcion){
			case  0:	printf("adios...");
						system("PAUSE");
						break;
			case 1: ;	agregar(equipos);
						break;
				case 2: listarEquipos(equipos);
						system("PAUSE");
						break;
				case 3: listarPc(equipos);
						system("PAUSE");
						break;
				case 4: listarLaptops(equipos);
						system("PAUSE");
						break;
				case 5: buscar_Equipos(equipos);
						system("PAUSE");
						break;
				case 6: reasignar_Equipo(equipos);
						system("PAUSE");
						break;
				case 7: guardar(equipos);
						system("PAUSE");
						break;
				case 8: cargar(equipos);
						system("PAUSE");
						break;
		
		}
	}while(opcion!=0);
	
	return 0;
}

//menu del programa
int menu(){
		int opcion;
		printf("-----CONTROL DE EQUIPOS DE COMPUTO-----\n");
		printf("0-	Salir \n");
		printf("1-	Agregar equipo\n");
		printf("2-	Listar todos los equipos \n");
		printf("3-	Listar las PCS \n");
		printf("4-	Listar las Laptops\n");
		printf("5- 	Buscar el equipo asignado a un administrativo \n");
		printf("6-	Reasignar equipo \n");
		printf("7-	Guardar archivo \n");
		printf("8-	Cargar archivo \n");
		printf("Selecciona una opcion: ");
		opcion=validarEnteros(0,8);
		return opcion;
	}
	//Validamos si esta dentro del rango 0-8 del menu.
	int validarEnteros(int inferior, int superior) {
		int valor;
		do {
			scanf("%d",&valor);
			if(valor<inferior || valor>superior){
				printf("Dato invalido!!! debe estar entre (%d- %d). vuelva a introducirlo:\n",inferior,superior);
			}
		}while(valor<inferior ||valor>superior);
		return valor;
	}
	void agregar(struct computadora x[]){
	int pregunta;
	// ciclo para agregar serie,modelo, tipo de computadora, trabajador encargado,edificio, area. 
	while(n<MAX){
		//leer numero de serie
		leers("numero de serie: ",x[n].serie,10);
		//leer modelo de computadora
		leers("modelo: ",x[n].modelo,10);
		//leer tipo laptop o pc
		leers("tipo de computadora LAPTOP O PC\n INTRODUCE EN MAYUSCULAS:",x[n].tipoComputadora,20);
	
		
		//leer trabajador encargado
		leers("Nombre del encargado de la computadora: ",x[n].trabajador,30);
		//leer edificio 
		leers("Edificio: ",x[n].edificio,15);
		//leer area
		leers("Area:  ",x[n].area,15);
		n++;
			
		pregunta=leerd("agregar a otra computadora? (1-si, 0-no):",0,1);
		//si NO se desea agregar otra computadora se rompe el while
		if(pregunta==0){
			break;
		}
	
	}
}


//LISTAR TODOS LOS EQUIPOS 
void listarEquipos(struct computadora x[]){

	printf("-----------------------------------LISTADO DE COMPUTADORAS------------------------------------------\n");
	printf("No.\tENCARGADO \tSERIE 	\tMODELO 	\t TIPO  \t   EDIFICIO 	\tAREA \n");
	printf("----------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<n; i++){
		printf("%2d\t%-15s\t%-15s\t%-15s %-15s\t%-15s\t%-15s\n",i+1,x[i].trabajador,x[i].serie,x[i].modelo,x[i].tipoComputadora,x[i].edificio,x[i].area);
	}
	printf("----------------------------------------------------------------------------------------------------\n");
	

				
	}

//LISTAR PCS

void listarPc(struct computadora x[]){
	printf("----------------------------------------EQUIPOS PC--------------------------------------------------\n");
	printf("No.\tENCARGADO \tSERIE 	\tMODELO 	\t TIPO  \t   EDIFICIO 	\tAREA \n");
	printf("----------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<n; i++){
		if(strcmp(x[i].tipoComputadora,"PC")==0){
			printf("%2d\t%-15s\t%-15s\t%-15s %-15s\t%-15s\t%-15s\n",i+1,x[i].trabajador,x[i].serie,x[i].modelo,x[i].tipoComputadora,x[i].edificio,x[i].area);
		}
	}
		
}

//LISTAR LAPTOPS 
void listarLaptops(struct computadora x[]){
	printf("--------------------------------------------EQUIPOS LAPTOPS-----------------------------------------\n");
	printf("No.\tENCARGADO \tSERIE 	\tMODELO 	\t TIPO  \t   EDIFICIO 	\tAREA \n");
	printf("----------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<n; i++){
		if(strcmp(x[i].tipoComputadora,"LAPTOP")==0){
			printf("%2d\t%-15s\t%-15s\t%-15s %-15s\t%-15s\t%-15s\n",i+1,x[i].trabajador,x[i].serie,x[i].modelo,x[i].tipoComputadora,x[i].edificio,x[i].area);
		}
	}
		
}
//BUSCAR EQUIPO
void buscar_Equipos(struct computadora x[]){
	printf("-------------------BUSQUEDA DEL EQUIPO DE COMPUTO--------------------------------------------------\n");
	printf("----------------------------------------------------------------------------------------------------\n");
	char busqueda[20];
	leers("Nombre del administrativo:  ",busqueda,20);
	
		for (int i=0; i<n; i++){	
			if(strcmp(busqueda,x[i].trabajador)==0){
				printf("No.\tENCARGADO \tSERIE 	\tMODELO 	\t TIPO  \t   EDIFICIO 	\tAREA \n");
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("%2d\t%-15s\t%-15s\t%-15s %-15s\t%-15s\t%-15s\n",i+1,x[i].trabajador,x[i].serie,x[i].modelo,x[i].tipoComputadora,x[i].edificio,x[i].area);		
			}	
			else{
				printf("no se encontro ningun administrativo con equipo asignado!!!!\n");
			}
		}
		
	
}
//REASIGNAR EQUIPO  
void reasignar_Equipo(struct computadora x[]){
	printf("-------------------------------------REASIGNAR EQUIPOS ------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	char reasignar[20];
	int i=0;
	int numeroSerie;
	numeroSerie=leerd("Numero de serie del equipo: \n",0,9999);
	
for (int i=0; i<n; i++){	
			if(numeroSerie){
					
					printf("No.\tENCARGADO \tSERIE 	\tMODELO 	\t TIPO  \t   EDIFICIO 	\tAREA \n");
					leers("Nuevo Administrador del equipo:  ", x[i].trabajador,20);
					break;
			}
		else{
			printf("no existe computo con numero de serie!!!\n");
		}	
	}
}
	

//GUARDAR ARCHIVO

void guardar(struct computadora x[]) {
	FILE *f;
	f=fopen("ProyectoFinal.dat","w");
	if(f==NULL){
		printf("error al intentar guardar los datos!!!! \n");
	}
	else{
		for(int i=0; i<n; i++){
			fwrite(&x[i],sizeof(x[i]),1,f);
		}
		fclose(f);
		printf("---->se guardaron %d registros \n",n);
		
	}
	
}
//CARGAR ARCHIVO
void cargar(struct computadora x[]){
	FILE*f;
	f=fopen("ProyectoFinal.dat","r");
	n=0;
	if(f==NULL){
		printf("Error al intentar cargar los datos!!!! \n");
	}
	else{
		printf("LEYENDO.....\n");
		while(fread(&x[n], sizeof(x[n]),1,f)==1){
			n++;
		}
		fclose(f);
		printf("---%d registros leidos\n",n);
		
	}
}






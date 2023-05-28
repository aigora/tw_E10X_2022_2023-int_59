#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char tipo[50];
	float enero_21;
	float febrero_21;
	float marzo_21;
	float abril_21;
	float mayo_21;
	float junio_21;
	float julio_21;
	float agosto_21;
	float septiembre_21;
	float octubre_21;
	float noviembre_21;
	float diciembre_21;
	float enero_22;
	float febrero_22;
	float marzo_22;
	float abril_22;
	float mayo_22;
	float junio_22;
	float julio_22;
	float agosto_22;
	float septiembre_22;
	float octubre_22;
	float noviembre_22;
	float diciembre_22;
}fichero_esp;

char* mostrarDatos (void);

double calcularMediaGrupo (char* archivo, char* grupo);

int main()
{
	//Variables para la opcion de calculos estadisticos
	int i, opcionEstadistica = 0;
	char grupo[100];


    fichero_esp esp[300];
	FILE *fichero;
	//Aquí abrimos el fichero y nos aseguramos de que existe
	fichero = fopen("fichero_final.txt", "r");
	if(fichero == NULL)
	{
		printf("Error al abrir el archivo\n");
	}
	else
	{
		//Aquí leemos todos los datos del fichero y los almacenamos en una estructura
		for(i=0; i<18; i++)
		{
			fscanf(fichero, "%s %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",
			esp[i].tipo, &esp[i].enero_21, &esp[i].febrero_21, &esp[i].marzo_21, &esp[i].abril_21, &esp[i].mayo_21,
			&esp[i].junio_21, &esp[i].julio_21, &esp[i].agosto_21, &esp[i].septiembre_21, &esp[i].octubre_21,
			&esp[i].noviembre_21, &esp[i].diciembre_21, &esp[i].enero_22, &esp[i].febrero_22, &esp[i].marzo_22,
			&esp[i].abril_22, &esp[i].mayo_22, &esp[i].junio_22, &esp[i].julio_22, &esp[i].agosto_22,
			&esp[i].septiembre_22, &esp[i].octubre_22, &esp[i].noviembre_22, &esp[i].diciembre_22);
		}
		fclose(fichero);
	}
    
    //Men�
    int OP;
    do
    {
	    do
	    {
	    	printf("1 - Ver Datos \n");
	    	printf("2 - Calculos estadisticos \n");
	    	printf("3 - Datos \n");
	    	printf("4 - Datos \n");
	    	printf("5 - Salir del menu \n");
	    	printf("\n Elige una opcion: ");
	    	scanf("%d", &OP);
	    	printf("\n_____________________________________________________________\n\n");
		}
	    while((OP!=1)&&(OP!=2)&&(OP!=3)&&(OP!=4)&&(OP!=5));
	   
	    switch (OP)
	    {
	    case 1:{
		    char* resultado = mostrarDatos ();
			printf("%s", resultado);
			printf("\n_____________________________________________________________\n\n");
	        break;}
	
	    case 2:
	        printf("1- Media\n2- Varianza\n3- Desviacion Tipica\n");
			printf("\nSelecciona una opcion: ");
			scanf("%i", &opcionEstadistica);
			printf("\n_____________________________________________________________\n\n");
			
			//Codigo para la media
			if (opcionEstadistica = 1)
			{
				char archivo[] = "fichero_final.txt";
				printf("\n 1- Hidraulica\n 2- Turbinacion\n 3- Nuclear\n 4- Carbon\n 5- Gas\n 6- Motores Diesel\n 7- Turbinas de gas\n 8- Turbina de vapor\n 9- Ciclo combinado\n 10- Hidroeolica\n 11- Eolica\n 12- Solar fotovoltaica\n 13- Solar termica\n 14- Otras renovables\n 15- Cogeneracion\n 16- Residuos renovables\n 17- Residuos no renovables\n 18- Generacion total");
				printf("\n\nEscriba el grupo del que desea conocer la media (Si el nombre tiene espacios escribalo asi: ResiduosRenovables): ");
				scanf("%s", grupo);
				double resultadoMedia = calcularMediaGrupo (archivo, grupo);
				printf("\nLa media del grupo %s es: %.2f", grupo, resultadoMedia);
				printf("\n_____________________________________________________________\n\n");
			}
	        break;
	
	    case 3:
	        //Algo
	        break;
	
	    case 4:
	        //Algo
	        break;
	
	    default:
	        printf("Fin del programa \n");
	        break;
	    }
	}
	while (OP!=5);
    return 0;
}

//Función para mostrar los datos del fichero
char* mostrarDatos ()
{
	int OP = 0, linea_seleccionada = 0, counter = 1, mes_seleccionado = 0, i;
	static char linea[5000];
	fichero_esp esp[300];
	FILE *fichero;
	fichero = fopen("fichero_final.txt", "r");
	printf("1- Ver datos de un cierto grupo de energias.\n");
	printf("2- Ver todos los datos.\n");
	printf("\nElige una opcion: ");
	scanf("%i", &OP);
	printf("\n_____________________________________________________________\n\n");
	switch (OP)
	{
	case 1:
		//Ver datos por filas
		printf("\n 1- Hidraulica\n 2- Turbinacion\n 3- Nuclear\n 4- Carbon\n 5- Gas\n 6- Motores Diesel\n 7- Turbinas de gas\n 8- Turbina de vapor\n 9- Ciclo combinado\n 10- Hidroeolica\n 11- Eolica\n 12- Solar fotovoltaica\n 13- Solar termica\n 14- Otras renovables\n 15- Cogeneracion\n 16- Residuos renovables\n 17- Residuos no renovables\n 18- Generacion total");
		printf("\n Datos que quieres ver: ");
		scanf("%i", &linea_seleccionada);
		//Si se pasa o se queda corto lo repite
		while (linea_seleccionada < 1)
		{
			printf("\n 1- Hidraulica\n 2- Turbinacion\n 3- Nuclear\n 4- Carbon\n 5- Gas\n 6- Motores Diesel\n 7- Turbinas de gas\n 8- Turbina de vapor\n 9- Ciclo combinado\n 10- Hidroeolica\n 11- Eolica\n 12- Solar fotovoltaica\n 13- Solar termica\n 14- Otras renovables\n 15- Cogeneracion\n 16- Residuos renovables\n 17- Residuos no renovables\n 18- Generacion total");
		    printf("\n Datos que quieres ver: ");
		    scanf("%i", &linea_seleccionada);
		}
		while (linea_seleccionada > 18)
		{
			printf("1- Hidraulica\n 2- Turbinacion\n 3- Nuclear\n 4- Carbon\n 5- Gas\n 6- Motores Diesel\n 7- Turbinas de gas\n 8- Turbina de vapor\n 9- Ciclo combinado\n 10- Hidroeolica\n 11- Eolica\n 12- Solar fotovoltaica\n 13- Solar termica\n 14- Otras renovables\n 15- Cogeneracion\n 16- Residuos renovables\n 17- Residuos no renovables\n 18- Generacion total");
		    printf("\n Datos que quieres ver: ");
		    scanf("%i", &linea_seleccionada);
		}
		
		//Aquí esta el codigo para mostrarlo en la terminal
		while (fgets(linea, 1000, fichero) != NULL)
		{
			if(counter == linea_seleccionada)
			{
				printf("\n\n");
				return linea;
				break;
			}
			counter++;
		}
		counter = 1;
	case 2:
	    //Ver todos los datos 
		printf("\n\n");
		while(fgets(linea, 1000, fichero) != NULL)
		{
			fgets(linea, 1000, fichero);
		}
		return linea;
		break;
	default:
		break;
	}
	fclose(fichero);
}

double calcularMediaGrupo (char* archivo, char* grupo)
{
	FILE* file = fopen("fichero_final.txt", "r");
	if (file == NULL)
	{
		printf("No se puede abrir el archivo.\n");
		return 0.0;
	}

	char linea[1000];
	double suma = 0.0;
	int contador = 0;

	while(fgets(linea, sizeof(linea), file) != NULL)
	{
		char* parte = strtok(linea, "   ");
		if(strcmp(parte, grupo) == 0)
		{
			parte = strtok(NULL, "   ");
			while(parte != NULL)
			{
				suma += atof(parte);
				contador++;
				parte = strtok(NULL, "   ");
			}
			break;
		}
	}

	fclose(file);

	if(contador == 0)
	{
		printf("No se encontr� el grupo especificado.");
		return 0.0;
	}

	return suma/contador;
}

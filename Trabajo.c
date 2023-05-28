#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	char tipo[50];
	double datos_meses[24];
}fichero_esp;

void tipos_energia();//funcion para imprimir todos los tipos de energia (se utiliza bastante)

char* mostrarDatos (void);

double calcularMediaGrupo (char* archivo, char* grupo);

double media(double datos[], int tam_vector);

double varianza(double datos[], int tam_vector);

int main()
{
	int i, j, eleccion;
	char grupo[100];


    fichero_esp esp[18];
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
			fscanf(fichero, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
			esp[i].tipo, &esp[i].datos_meses[0], &esp[i].datos_meses[1], &esp[i].datos_meses[2], &esp[i].datos_meses[3], &esp[i].datos_meses[4],
			&esp[i].datos_meses[5], &esp[i].datos_meses[6], &esp[i].datos_meses[7], &esp[i].datos_meses[8], &esp[i].datos_meses[9],
			&esp[i].datos_meses[10], &esp[i].datos_meses[11], &esp[i].datos_meses[12], &esp[i].datos_meses[13], &esp[i].datos_meses[14],
			&esp[i].datos_meses[15], &esp[i].datos_meses[16], &esp[i].datos_meses[17], &esp[i].datos_meses[18], &esp[i].datos_meses[19],
			&esp[i].datos_meses[20], &esp[i].datos_meses[21], &esp[i].datos_meses[22], &esp[i].datos_meses[23]);
		}
		fclose(fichero);
	}
    
    //Menu
    int OP;
    printf("_____________________________________________________________\n\n");
	printf("		    GENERACION DE ENERGIA");
	printf("\n_____________________________________________________________\n\n\n");
    do
    {
	    do
	    {
	    	printf("______________________________\n\n");
			printf("             MENU");
			printf("\n______________________________\n\n\n");
	    	printf("1 - Consultar Datos \n");
	    	printf("2 - Calculos estadisticos \n");
	    	printf("3 - Datos \n");
	    	printf("4 - Datos \n");
	    	printf("5 - Salir del menu \n");
	    	printf("\n Elige una opcion: ");
	    	scanf("%d", &OP);
	    	printf("\n_____________________________________________________________\n\n");
		}
	    while((OP<1)||(OP>5));
	   
	    switch (OP)
	    {
	    case 1:{
		    char* resultado = mostrarDatos ();
			printf("%s", resultado);
			printf("\n_____________________________________________________________\n\n");
	        break;}
	
	    case 2:
	        do
	        {
	        	printf("1- Media\n2- Varianza y desviacion tipica\n");
				printf("\nSelecciona una opcion: ");
				scanf("%i", &OP);
				printf("\n_____________________________________________________________\n\n");
			}
			while((OP<1)||(OP>2));
			
			
			//Codigo para la media, varianza y desviacion tipica
			switch (OP)
			{
				case 1:
				{
					char archivo[] = "fichero_final.txt";
					tipos_energia();
					printf("Escriba el grupo del que desea conocer la media (Si el nombre tiene espacios escribalo asi: ResiduosRenovables): ");
					scanf("%s", grupo);
					double resultadoMedia = calcularMediaGrupo (archivo, grupo);
					printf("\nLa media del grupo %s es: %.2f", grupo, resultadoMedia);
					printf("\n_____________________________________________________________\n\n");
					
					break;
				}
				case 2:
				{
					do
			        {
			        	printf("�Que varianza quieres calcular?\n\n1-Varianza total\n2-Por meses\n3-Varios tipos de energia");
						printf("\n\nElige una opcion: ");
						scanf("%i", &OP);
						printf("\n_____________________________________________________________\n\n");
					}
					while((OP<1)||(OP>3));
					
					if (OP==1)
					{
						tipos_energia();
						do
						{
							printf("Elige un tipo de energia: ");
							scanf("%i", &eleccion);	
							printf("\n_____________________________________________________________\n\n");
						}
						while ((eleccion<1)||(eleccion>18));
						
						printf("\nVarianza: %f\n", varianza(esp[eleccion-1].datos_meses, sizeof(esp[eleccion-1].datos_meses)/sizeof(double)));
						printf("Desviacion tipica: %f\n\n", sqrt(varianza(esp[eleccion-1].datos_meses, sizeof(esp[eleccion-1].datos_meses)/sizeof(double))));
					}
					
					if (OP==2)
					{
					}
					
					if (OP==3)
					{
					}
					
					break;
				}
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

void tipos_energia()
{
	printf("\n 1- Hidraulica\n 2- Turbinacion bombeo\n 3- Nuclear\n 4- Carbon\n 5- Fuel y Gas\n 6- Motores Diesel\n 7- Turbinas de gas\n 8- Turbina de vapor\n 9- Ciclo combinado\n 10- Hidroeolica\n 11- Eolica\n 12- Solar fotovoltaica\n 13- Solar termica\n 14- Otras renovables\n 15- Cogeneracion\n 16- Residuos no renovables\n 17- Residuos renovables\n 18- Generacion total\n\n");
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
		tipos_energia();
		printf(" Datos que quieres ver: ");
		scanf("%i", &linea_seleccionada);
		//Si se pasa o se queda corto lo repite
		while (linea_seleccionada < 1)
		{
			tipos_energia();
		    printf(" Datos que quieres ver: ");
		    scanf("%i", &linea_seleccionada);
		}
		while (linea_seleccionada > 18)
		{
			tipos_energia();
		    printf(" Datos que quieres ver: ");
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

double media(double datos[], int tam_vector)
{
	int i;
	double media=0;
	for (i=0;i<tam_vector;i++)
	{
		media=media+datos[i];
	}
	media=media/tam_vector;
	
	return media;
}

double varianza(double datos[], int tam_vector)
{
	int i;
	double varianza=0;
	for (i=0;i<tam_vector;i++)
	{
		varianza=varianza+pow((media(datos,tam_vector)-datos[i]),2);
	}
	varianza=varianza/tam_vector;
	
	return varianza;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	char tipo[50];
	double datos_meses[24];
}fichero_esp;

typedef struct
{
	int tipo_energia;
	int anho;
	int mes;
}info_mes;

void tipos_energia();//funcion para imprimir todos los tipos de energia (se utiliza bastante)

char* mostrarDatos (void);

double calcularMediaGrupo (char* archivo, char* grupo);

double media(double datos[], int tam_vector);

double varianza(double datos[], int tam_vector);

int main()
{
	int i, eleccion;
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
	printf("En este programa estan almacenados los datos de generacion de electricidad de 2021 y 2022 de todas las fuentes de\nenergia en Espana. Los datos estan organizados en meses.\n\n\n");
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
	        	printf("1- Media\n2- Varianza y desviacion tipica\n3- Volver\n");
				printf("\nSelecciona una opcion: ");
				scanf("%i", &OP);
				printf("\n_____________________________________________________________\n\n");
			}
			while((OP<1)||(OP>3));
			
			
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
			        	printf("�Como las quieres calcular?\n\n1-Varianza y desviacion tipica total de un tipo de fuente\n2-Personalizado. Elegir meses\n3-Volver\n");
						printf("\nElige una opcion: ");
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
						printf("\n_____________________________________________________________\n\n");
					}
					
					if (OP==2)
					{
						int num_meses;
						info_mes *meses;
						
						tipos_energia();
						printf("\nEstan disponibles los datos de todos los meses de 2021 y 2022.\n\n");
						printf("Introduce el numero de meses de los que deseas calcular la varianza: ");
						do
						{
							scanf("%i", &num_meses);
						}
						while ((num_meses<1)||(num_meses>24*18));//24 meses de cada tipo de energia por 18 tipos de energia es el maximo numero de meses que tienes para seleccionar
						
						meses=malloc(sizeof(info_mes)*num_meses);
						if (meses==NULL)
						{
							printf("Error: Memoria no disponible");
							return -1;
						}
						
						printf("\nIntroduce los meses que desees de la forma: tipo_energia anho mes (ejemplo, hidraulica 2021 enero: 1 2021 1)\n");
						for(i=0;i<num_meses;i++)//almacena los meses escogidos por el usuario en la variable-estructura meses
						{
							do
							{
								printf("Dato %i: ", i+1);
								scanf("%i %i %i", &meses[i].tipo_energia, &meses[i].anho, &meses[i].mes);
							}
							while ((meses[i].tipo_energia<1)||(meses[i].tipo_energia>18)||(meses[i].anho<2021)||(meses[i].anho>2022)||(meses[i].mes<1)||(meses[i].mes>12));
						}
						
						double *datos;
						datos=malloc(sizeof(double)*num_meses);
						if (datos==NULL)
						{
							printf("Error: Memoria no disponible");
							return -1;
						}
						
						for (i=0;i<num_meses;i++)//traduce la informacion dada por el usuario a el valor de la generacion de energ�a del mes escogido y almacena los datos de todos los meses en un unico vector 
						{
							if (meses[i].anho==2021)
							{
								datos[i]=esp[(meses[i].tipo_energia-1)].datos_meses[(meses[i].mes-1)];
							}
							else
							{
								datos[i]=esp[(meses[i].tipo_energia-1)].datos_meses[(meses[i].mes+12-1)];//si el anho escogido es 2022 hay que sumarle al mes 12 unidades para que sea el mes de 2022. Esto es asi debido a la forma en la que se orgaiza la informacion del fichero en la estructura
							}
						}

						printf("\nVarianza: %f\nDesviacion tipica: %f\n", varianza(datos, num_meses), sqrt(varianza(datos, num_meses)));
						printf("\n_____________________________________________________________\n\n");
						
						free (meses);
						free (datos);
					}
					
					break;
				}
				case 3:
					break;
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
	printf("\nTIPOS DE ENERGIA\n\n 1- Hidraulica\n 2- Turbinacion bombeo\n 3- Nuclear\n 4- Carbon\n 5- Fuel y Gas\n 6- Motores Diesel\n 7- Turbinas de gas\n 8- Turbina de vapor\n 9- Ciclo combinado\n 10- Hidroeolica\n 11- Eolica\n 12- Solar fotovoltaica\n 13- Solar termica\n 14- Otras renovables\n 15- Cogeneracion\n 16- Residuos no renovables\n 17- Residuos renovables\n 18- Generacion total\n\n");
}

//Función para mostrar los datos del fichero
char* mostrarDatos ()
{
	int OP = 0, linea_seleccionada = 0, counter = 1, mes_seleccionado = 0, i;
	static char linea[5000];
	fichero_esp esp[300];
	FILE *fichero;
	fichero = fopen("fichero_final.txt", "r");
	printf("\n_____________________________________________________________\n\n");
	
	//Ver datos por filas
	tipos_energia();
	printf(" Datos que quieres ver: ");
	scanf("%i", &linea_seleccionada);
	//Si se pasa o se queda corto lo repite
	while(linea_seleccionada<1 || linea_seleccionada>18)
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

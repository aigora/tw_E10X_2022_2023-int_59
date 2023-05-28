#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	char tipo[50];
	double datos_meses[4][12];//datos_meses[anhos][meses]
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

void convertir_matriz_a_vector(double datos[4][12], int filas, int columnas, double vector[]);

double media(double datos[], int tam_vector);

double varianza(double datos[], int tam_vector);

double maximo(double datos[], int tam_vector);

void meses();//funcion para imprimir todos los meses 


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
		for(i=0; i<18; i++)//juntamos toda la informacion de generacion en un vector donde cada elemento de este es el valor de generaci�n de un mes, ordenados los meses en orden cronologico teniendo en cuenta el anho
		{
			fscanf(fichero, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
			esp[i].tipo, &esp[i].datos_meses[2][0], &esp[i].datos_meses[2][1], &esp[i].datos_meses[2][2], &esp[i].datos_meses[2][3], &esp[i].datos_meses[2][4],
			&esp[i].datos_meses[2][5], &esp[i].datos_meses[2][6], &esp[i].datos_meses[2][7], &esp[i].datos_meses[2][8], &esp[i].datos_meses[2][9],
			&esp[i].datos_meses[2][10], &esp[i].datos_meses[2][11], &esp[i].datos_meses[3][0], &esp[i].datos_meses[3][1], &esp[i].datos_meses[3][2],
			&esp[i].datos_meses[3][3], &esp[i].datos_meses[3][4], &esp[i].datos_meses[3][5], &esp[i].datos_meses[3][6], &esp[i].datos_meses[3][7],
			&esp[i].datos_meses[3][8], &esp[i].datos_meses[3][9], &esp[i].datos_meses[3][10], &esp[i].datos_meses[3][11]);
		}
		fclose(fichero);
	}
	
	FILE *fichero_0;
	//Aquí abrimos el fichero y nos aseguramos de que existe
	fichero_0 = fopen("generacion_01-01-2019_31-12-2020.csv", "r");
	if(fichero_0 == NULL)
	{
		printf("Error al abrir el archivo\n");
	}
	else
	{
		//Aquí leemos todos los datos del fichero y los almacenamos en una estructura
		for(i=0; i<18; i++)//juntamos toda la informacion de generacion en un vector donde cada elemento de este es el valor de generaci�n de un mes, ordenados los meses en orden cronologico teniendo en cuenta el anho
		{
			fscanf(fichero, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
			esp[i].tipo, &esp[i].datos_meses[0][0], &esp[i].datos_meses[0][1], &esp[i].datos_meses[0][2], &esp[i].datos_meses[0][3], &esp[i].datos_meses[0][4],
			&esp[i].datos_meses[0][5], &esp[i].datos_meses[0][6], &esp[i].datos_meses[0][7], &esp[i].datos_meses[0][8], &esp[i].datos_meses[0][9],
			&esp[i].datos_meses[0][10], &esp[i].datos_meses[0][11], &esp[i].datos_meses[1][0], &esp[i].datos_meses[1][1], &esp[i].datos_meses[1][2],
			&esp[i].datos_meses[1][3], &esp[i].datos_meses[1][4], &esp[i].datos_meses[1][5], &esp[i].datos_meses[1][6], &esp[i].datos_meses[1][7],
			&esp[i].datos_meses[1][8], &esp[i].datos_meses[1][9], &esp[i].datos_meses[1][10], &esp[i].datos_meses[1][11]);
		}
		fclose(fichero);
	}
    
    double vector_datos[48];
	
    //Menu
    int OP;
    printf("_____________________________________________________________\n\n");
	printf("		    GENERACION DE ENERGIA");
	printf("\n_____________________________________________________________\n\n\n");
	printf("En este programa estan almacenados los datos de generacion de electricidad entre 2019 y 2022 de todas las fuentes de\nenergia en Espana. Los datos estan organizados en meses.\n\n\n");
    do
    {
	    do
	    {
	    	printf("______________________________\n\n");
			printf("             MENU");
			printf("\n______________________________\n\n\n");
	    	printf("1 - Consultar Datos \n");
	    	printf("2 - Calculos estadisticos \n");
	    	printf("3 - Analisis de datos\n");
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
			        	printf("Como las quieres calcular?\n\n1-Varianza y desviacion tipica total de un tipo de fuente\n2-Personalizado. Elegir meses\n3-Volver\n");
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
						
						convertir_matriz_a_vector(esp[eleccion-1].datos_meses, 4, 12, vector_datos);
						
						printf("\nVarianza: %f\n", varianza(vector_datos, 48));
						printf("Desviacion tipica: %f\n\n", sqrt(varianza(vector_datos, 48)));
						printf("\n_____________________________________________________________\n\n");
					}
					
					if (OP==2)
					{
						int num_meses;
						info_mes *meses;
						
						tipos_energia();
						printf("\nEstan disponibles los datos de todos los meses entre 2019 y 2022.\n\n");
						printf("Introduce el numero de meses de los que deseas calcular la varianza: ");
						do
						{
							scanf("%i", &num_meses);
						}
						while ((num_meses<1)||(num_meses>48*18));//48 meses de cada tipo de energia por 18 tipos de energia es el maximo numero de meses que tienes para seleccionar
						
						meses=malloc(sizeof(info_mes)*num_meses);
						if (meses==NULL)
						{
							printf("Error: Memoria no disponible");
							return -1;
						}
						
						printf("\nIntroduce los meses que desees de la forma: tipo_energia anho mes (ejemplo, hidraulica 2019 enero: 1 2019 1)\n");
						for(i=0;i<num_meses;i++)//almacena los meses escogidos por el usuario en la variable-estructura meses
						{
							do
							{
								printf("Dato %i: ", i+1);
								scanf("%i %i %i", &meses[i].tipo_energia, &meses[i].anho, &meses[i].mes);
							}
							while ((meses[i].tipo_energia<1)||(meses[i].tipo_energia>18)||(meses[i].anho<2019)||(meses[i].anho>2022)||(meses[i].mes<1)||(meses[i].mes>12));
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
							for (j=0;j<4;j++)
							{
							if (meses[i].anho==(2019+j))
							{
								datos[i]=esp[(meses[i].tipo_energia-1)].datos_meses[j][meses[i].mes-1];
								break;
							}
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
	    {
			//Máximos y mínimos
	        do
			{
			    printf("�Que analisis quieres hacer?\n\n1-Produccion maxima\n2-Produccion minima");
				printf("\n\nElige una opcion: ");
				scanf("%i", &OP);			
				printf("\n_____________________________________________________________\n\n");
			}
			while((OP<1)||(OP>2));
			switch (OP)
			{  
				case 1:
				{
					do
					{
			    		printf("Elige los datos a analizar\n\n1- Produccion maxima total\n2- Produccion maxima por meses\n3- Produccion maxima tipo de energia\n4- Produccion maxima especifica");
						printf("\n\nElige una opcion: ");
						scanf("%i", &OP);			
						printf("\n_____________________________________________________________\n\n");
					}
					while((OP<1)||(OP>4));
					switch (OP)
					{
						case 1:
						{
							float maximotot;
							maximotot= 0;
							for (i=0; i<17; i++)
							{
								if ((maximo(esp[i].datos_meses, sizeof(esp[i].datos_meses)/sizeof(double))) > maximotot)
								{
									maximotot = maximo(esp[i].datos_meses, sizeof(esp[i].datos_meses)/sizeof(double));
								}
								else{}
							}
							printf("\nMaximo: %f\n", maximotot);
				
							break;
						}

						case 2:
						{
							do
							{
								printf("Elige el mes para saber el maximo \n");
								meses();
								printf("Elige el mes: ");
								scanf("%i", &OP);
								printf("\n_____________________________________________________________\n\n");
							} 
							while ((OP<1)||(OP>24));

							double *datos;
							datos = malloc(17);

							if (datos==NULL)
							{
							printf("Error: Memoria no disponible");
							return -1;
							}

							eleccion = OP -1;
							for (i=0; i<17; i++)
							{
								datos[i]=esp[i].datos_meses[eleccion];
							}

							printf("\nMaximo: %f\n", maximo(datos, 17));
							free(datos);
				
							break;
						}

						case 3:
						{
							tipos_energia();
							do
							{
								printf("Elige un tipo de energia: ");
								scanf("%i", &eleccion);	
								printf("\n_____________________________________________________________\n\n");
							}
							while ((eleccion<1)||(eleccion>18));
							printf("\nMaximo: %f\n", maximo(esp[eleccion-1].datos_meses, sizeof(esp[eleccion-1].datos_meses)/sizeof(double)));

							break;
						}

						case 4:
						{
							int num_meses;
							info_mes *meses;
						
							tipos_energia();
							printf("\nEstan disponibles los datos de todos los meses de 2021 y 2022.\n\n");
							printf("Introduce el numero de meses de los que deseas calcular el maximo: ");
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

							printf("\nMaximo: %f\n", maximo(datos, num_meses));
							printf("\n_____________________________________________________________\n\n");
						
							free (meses);
							free (datos);
						    
							break;
						}
					}

					break;
	            } 

				case 2:
				{
					//algo
					break;
				}   

				default:
					break;  
	     
			}

			break;
		}
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

void meses()
{
	printf("\n 1- Enero2021\n 2- Febrero2021\n 3- Marzo2021\n 4- Abril2021\n 5- Mayo2021\n 6- Junio2021\n 7- Julio2021\n 8- Agosto2021\n 9- Septiembre2021\n 10- Octubre2021\n 11- Noviembre2021\n 12- Diciembre2021\n");
	printf("\n 13- Enero2022\n 14- Febrero2022\n 15- Marzo2022\n 16- Abril2022\n 17- Mayo2022\n 18- Junio2022\n 19- Julio2022\n 20- Agosto2022\n 21- Septiembre2022\n 22- Octubre2022\n 23- Noviembre2022\n 24- Diciembre2022\n");
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

void convertir_matriz_a_vector(double datos[4][12], int filas, int columnas, double vector[])
{
	int i, j, k=0, tam=filas*columnas;
	for (i=0;i<filas;i++)
	{
		for (j=0;j<columnas;j++)
		{
			vector[k]=datos[i][j];
			k++;
		}
	}
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

double maximo(double datos[], int tam_vector)
{
	int i; 
	double maximo=0;
	for (i=0; i<tam_vector; i++)
	{
		if (datos[i]>maximo)
		{
			maximo = datos[i];
		}
		else{}

	}
	return maximo;
}
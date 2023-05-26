#include <stdio.h>

typedef struct
{
	char tipo[50];
	float enero;
	float febrero;
	float marzo;
	float abril;
	float mayo;
	float junio;
	float julio;
	float agosto;
	float septiembre;
	float octubre;
	float noviembre;
	float diciembre;
	float enero2;
	float febrero2;
	float marzo2;
	float abril2;
	float mayo2;
	float junio2; 
	float julio2;
	float agosto2;
	float septiembre2;
	float octubre2;
	float noviembre2;
	float diciembre2;
}fichero_esp;

char* mostrarDatos (void);

int main()
{
	int i;
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
			esp[i].tipo, &esp[i].enero, &esp[i].febrero, &esp[i].marzo, &esp[i].abril, &esp[i].mayo,
			&esp[i].junio, &esp[i].julio, &esp[i].agosto, &esp[i].septiembre, &esp[i].octubre,
			&esp[i].noviembre, &esp[i].diciembre, &esp[i].enero2, &esp[i].febrero2, &esp[i].marzo2,
			&esp[i].abril2, &esp[i].mayo2, &esp[i].junio2, &esp[i].julio2, &esp[i].agosto2,
			&esp[i].septiembre2, &esp[i].octubre2, &esp[i].noviembre2, &esp[i].diciembre2);
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
	    	printf("2 - Datos \n");
	    	printf("3 - Datos \n");
	    	printf("4 - Datos \n");
	    	printf("5 - Salir del menu \n");
	    	printf("\n Elige una opcion: ");
	    	scanf("%d", &OP);
		}
	    while((OP!=1)&&(OP!=2)&&(OP!=3)&&(OP!=4)&&(OP!=5));
	   
	    switch (OP)
	    {
	    case 1:{
		    char* resultado = mostrarDatos ();
			printf("%s", resultado);
	        break;}
	
	    case 2:
	        //Algo
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
	printf("1- Ver datos de un cierto grupo de energías.\n");
	printf("2- Ver todos los datos.\n");
	printf("Elige una opción: ");
	scanf("%i", &OP);
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
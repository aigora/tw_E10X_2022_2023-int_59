#include <stdio.h>
struct fechas
{
	int ano;
	int mes;
};
struct datos
{
	struct fechas fecha;
	float hidraulica;
	float turbinacion;
	float nuclear;
	float carbon;
	float gas;
	float motoresDiesel;
	float turbinasDeGas;
	float turbinaDeVapor;
	float cicloCombinado;
	float hidroeolica;
	float eolica;
	float solarFotovoltaica;
	float solarTermica;
	float otrasRenovables;
	float cogeneracion;
	float residuosRenovables;
	float residuosNoRenovables;
	float generacionTotal;
};
int main()
{
	//Lectura del fichero
	char linea[2000];
	char w[10];
	int i, counter = 1, linea_seleccionada;
	struct datos dato[300];
    FILE *pf;
    pf = fopen("generacion_21_22.txt", "r");

    if (pf == NULL)
    {
        printf("Error al abrir el fichero \n");
        return -1;
    }
    else
    {
        printf("Fichero abierto correctamente \n");
		fclose(pf);
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
	    case 1:
		    pf = fopen("generacion_21_22.txt", "r");
		    OP = 0;
	        printf("1 - Ver datos por filas: \n");
			printf("2 - Ver datos de otra forma: \n");
			printf("3 - Ver todos los datos: \n");
			printf("Elige una opcion: ");
			scanf("%i", &OP);
			switch (OP)
			{
			    case 1:
				    //Ver datos por filas
			        printf("\nNumero de fila que se desea leer: ");
			        scanf("%i", &linea_seleccionada);
			        while(fgets(linea, 100, pf) != NULL)
				    {
						if(counter == linea_seleccionada)
						{
							printf("La linea %i es:  %s", counter, linea);
						}
					    counter++;
				    }
				    break;
			    case 2:
				    break;
				case 3: 
				    //Ver todos los datos
		            while(fgets(linea, 2000, pf) != NULL)
		            {
			            fscanf(pf, "%s", linea);
			            printf("%s", linea);
		            }
					break;
			    default:
				    break;
			}
			fclose(pf);
	        break;
	
	    case 2:
	        //algo
	        break;
	
	    case 3:
	        //algo
	        break;
	
	    case 4:
	        //algo
	        break;
	
	    default:
	        printf("Fin del programa \n");
	        break;
	    }
	}
	while (OP!=5);

    
    
    
    return 0;
}



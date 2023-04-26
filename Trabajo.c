#include <stdio.h>
typedef struct
{
	int ano;
	int mes;
}fecha;
typedef struct
{
	int fechaNac = fecha;
	float hidraulica;
	float turbinacion;
	float nuclear;
	float carbon;
	float gas;
	float motores diesel;
	float turbinas de gas;
	float turbina de vapor;
	float ciclo combinado;
	float hidroeolica;
	float eolica;
	float solar fotovoltaica;
	float solar termica;
	float otras renovables;
	float cogeneracion;
	float residuos renovables;
	float residuos no renovables;
	float generacion total;
}datos;
int main()
{
	//Lectura del fichero
	char c;
	char w[10];
	int i;
	datos dato[300];
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
        if(fscanf(pf, "%9", &w) == 'idráulica')
       for(i = 0; i < 24; i++)
       {
       	fscanf(pf, ",%f,", dato.hidraulica[i]);
       }

    }
    
    //Menú
    int OP;
    do
    {
	    do
	    {
	    	printf("1 - Datos \n");
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
	        //algo
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


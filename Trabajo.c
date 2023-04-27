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
	char caracteres[2000];
	char w[10];
	int i;
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
		
		//Aquí se lee el fichero ENTERO, ahora solo queda guardar los datos que se leen de forma ordenada.
		while(fgets(caracteres, 2000, pf))
		{
			fscanf(pf, "%s", caracteres);
			printf("%s", caracteres);
		}
		fclose(pf);
    }
    
    //Men�
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


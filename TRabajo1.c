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
int menu(int seguir);
int seleccion(int seguir);

int main()
{
	//Lectura del fichero
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

    // A partir de aquí, empieza el bucle para poder volver siempre al menú principal 
    // Ó bien para salir del programa

    int seguir = 1;
    
    do
    {
        seguir = menu(seguir);
    }
    while(seguir == 1);
    return 0;
 
}

// En la función menú están las distintas opciones que puede elegir principalmente el usuario
// Dentro de cada opción, implemenntamos las utilidades que veamos convenientes

int menu(int seguir) 
{
    int OP;
    int x;
	do
	{
	    printf("1 - Ver Datos \n");
	    printf("2 - Datos \n");
	    printf("3 - Datos \n");
	    printf("4 - Datos \n");
	    printf("\n Elige una opcion: ");
	    scanf("%d", &OP);
	}
	while((OP!=1)&&(OP!=2)&&(OP!=3)&&(OP!=4));
	   
	switch (OP)
	{
	    case 1:
		    printf("Has seleccionado 1 \n");
            //Meter código para esta opción


            // Esta última parte, te lleva a una función que te permite 
            // volver al menú principal o acabar el programa, 
            // cuando se haya ejecutado el código perteneciente a esta opción.
            seguir = seleccion(x);
            return seguir;
            break;
	
	    case 2:
	        printf("Has seleccionado 2 \n");

            seguir = seleccion(x);
            return seguir;
	        break;
	
	    case 3:
	        printf("Has seleccionado 3 \n");

            seguir = seleccion(x);
            return seguir;
	        break;
	
	    case 4:
	        printf("Has seleccionado 4 \n");

            seguir = seleccion(x);
            return seguir;
	        break;
	
	    default:
	        break;
	}
	
}

// Esta función pregunta al usuario si quiere volver al menu
// ó si quiere finalizar el programa

int seleccion(int seguir)
{
    int OP;
    do
	{
	    printf("Pulse 1 si desea volver al menu principal. \n");
        printf("Pulse 0 si desea salir del programa. \n");
        printf(" \n Seleccione su opcion: ");
        scanf("%d \n", &OP);  
	}
	while((OP!=1)&&(OP!=0));
	   
	switch (OP)
	{
	    case 1:
        {
            printf("Volviendo al menu principal. \n");
            seguir = 1;
            return seguir;
        }
        case 0:
        {
            printf("Saliendo del programa. \n");
            seguir = 0;
            return seguir;
        }
    }
}
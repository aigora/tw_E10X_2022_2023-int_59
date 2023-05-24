#include <stdio.h>
typedef struct
{
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
int menu(int seguir);
int seleccion(int seguir);

int main()
{
	fichero_esp esp[300];
	int i;
	FILE *fichero;
	fichero = fopen("fichero_final.txt", "r");
	if(fichero == NULL)
	{
		printf("Error al abrir el archivo\n");
	}
	else
	{
		for(i=0; i<18; i++)
		{
			fscanf(fichero, "%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f", &esp[i].enero, &esp[i].febrero, &esp[i].marzo, &esp[i].abril, &esp[i].mayo, &esp[i].junio, &esp[i].julio, &esp[i].agosto, &esp[i].septiembre, &esp[i].octubre, &esp[i].noviembre, &esp[i].diciembre,
			       &esp[i].enero2, &esp[i].febrero2, &esp[i].marzo2, &esp[i].abril2, &esp[i].mayo2, &esp[i].junio2, &esp[i].julio2, &esp[i].agosto2, &esp[i].septiembre2, &esp[i].octubre2, &esp[i].noviembre2, &esp[i].diciembre2);
		}
		fclose(fichero);
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

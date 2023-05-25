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

int main()
{
	int i, counter = 1, linea_seleccionada;


    fichero_esp esp[300];
	int i;
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
			fscanf(fichero, "%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f", 
			&esp[i].enero, &esp[i].febrero, &esp[i].marzo, &esp[i].abril, &esp[i].mayo, &esp[i].junio, 
			&esp[i].julio, &esp[i].agosto, &esp[i].septiembre, &esp[i].octubre, &esp[i].noviembre, 
			&esp[i].diciembre, &esp[i].enero2, &esp[i].febrero2, &esp[i].marzo2, &esp[i].abril2, 
			&esp[i].mayo2, &esp[i].junio2, &esp[i].julio2, &esp[i].agosto2, &esp[i].septiembre2, 
			&esp[i].octubre2, &esp[i].noviembre2, &esp[i].diciembre2);
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
	    case 1:
		    //Algo
	        break;
	
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



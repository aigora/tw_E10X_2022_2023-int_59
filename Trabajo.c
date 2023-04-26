#include <stdio.h>

int main()
{
    FILE *pf;
    pf = fopen("generacion_21_22.txt", "r");

    if (pf == NULL)
    {
        printf("Error \n");
        return -1;
    }
    else
    {
        printf("Abierto \n");
        fclose(pf);
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


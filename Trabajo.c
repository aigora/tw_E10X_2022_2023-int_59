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
        return 0;
    }
    
    return 0;
}

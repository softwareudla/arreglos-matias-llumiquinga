#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
    int longitud;
    char estudiantes[5][21];

    for (int i = 0; i < 2; i++)
    {
        fflush(stdin);
        printf("Ingrese el nombre y apellido del estudiante %d:\n", i+1);
        fgets(estudiantes[i], 21, stdin);
        
        longitud = strlen(estudiantes[i]);

        if (estudiantes[i][longitud-1] != '\n')
        {
            printf("Se ha superado el máximo de 20 caracteres. Ingrese solo el nombre del estudiante: %d\n", i+1);
            i--;

            // Limpiar el buffer de entrada si el usuario ingresó más de los caracteres permitidos
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Vaciar el buffer de entrada
        }


    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", estudiantes[i]);
    }
    
    

    return 0;
}
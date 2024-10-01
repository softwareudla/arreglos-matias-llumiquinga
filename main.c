#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
    const int numestudiantes = 5, espacioCadena = 21;
    int longitudCadena, limpiadorBuffer;

    char    estudiantes[numestudiantes][espacioCadena];    

    for (int i = 0; i < numestudiantes; i++)
    {
        printf("Ingrese el nombre y apellido o solo el nombre del estudiante %d (MAX 20 caracteres):\n", i+1);
        fflush(stdin);
        fgets(estudiantes[i], espacioCadena+1, stdin);  //se suma 1 porque fgets deja un espacio para \0 además de \n  ....'\n''\0'
        
        longitudCadena = strlen(estudiantes[i]);

        if (estudiantes[i][longitudCadena-1] != '\n')
        {
            printf("Se ha superado el maximo de 20 caracteres\n");
            i--;

            while ((limpiadorBuffer = getchar()) != '\n' && limpiadorBuffer != EOF);
        }




    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s", estudiantes[i]);
    }
    
    

    return 0;
}
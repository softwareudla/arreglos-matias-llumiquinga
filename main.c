#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
    const int numEstudiantes = 5, espacioCadena = 21;
    int longitudCadena, limpiadorBuffer;

    char estudiantes[numEstudiantes][espacioCadena];


    printf("------------------------REGISTRO DE NOMBRES DE ESTUDIANTES------------------------\n");

    for (int i = 0; i < numEstudiantes; i++)
    {
        printf("Ingrese el nombre y apellido o solo el nombre del estudiante %d (MAX 20 caracteres):\n", i+1);
        fflush(stdin);
        fgets(estudiantes[i], espacioCadena+1, stdin);  //se suma 1 porque fgets deja un espacio para \0 además de \n  ....'\n''\0'
        
        longitudCadena = strlen(estudiantes[i]);

        if (estudiantes[i][longitudCadena-1] != '\n')
        {
            printf("Se ha superado el maximo de 20 caracteres\n");
            i--;

            while ((limpiadorBuffer = getchar()) != '\n' && limpiadorBuffer != EOF); //limpia el buffer de entrada
        }else{
            estudiantes[i][longitudCadena-1] = '\0';
        }

    }
    



    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", estudiantes[i]);
    }
    
    

    return 0;
}
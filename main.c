#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
    const int numEstudiantes = 2, numMaterias = 1, numCalif=6, espacioCadena = 21;
    int longitudCadena, limpiadorBuffer;

    float califEst1[numCalif][numMaterias];

    char estudiantes[numEstudiantes][espacioCadena], materias[numMaterias][espacioCadena];


    printf("----------------------------- REGISTRO DE ESTUDIANTES ----------------------------\n");


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

    printf("------------------------------ REGISTRO DE MATERIAS ------------------------------\n");

    for (int i = 0; i < numMaterias; i++)
    {
        printf("Ingrese el nombre de la materia %d (MAX 20 caracteres):\n", i+1);
        fflush(stdin);
        fgets(materias[i], espacioCadena+1, stdin);
        
        longitudCadena = strlen(materias[i]);

        if (materias[i][longitudCadena-1] != '\n')
        {
            printf("Se ha superado el maximo de 20 caracteres\n");
            i--;

            while ((limpiadorBuffer = getchar()) != '\n' && limpiadorBuffer != EOF);
        }else{
            materias[i][longitudCadena-1] = '\0';
        }
    }

    for (int i = 0; i < numMaterias; i++)
    {
        printf("--------------------------- REGISTRO DE CALIFICACIONES DE %s\n", materias[i]);

        for (int j = 0; j < numEstudiantes; j++)
        {
            printf("-------------- Ingrese las calificaciones de %s\n", estudiantes[j]);
            
            for (int h = 0; h < numCalif; h++)
            {
                printf("Aqui de nuevo\n");
                scanf("%f", &califEst1[h][i]);

                if (califEst1[h][i]>10 || califEst1[h][i]<0)
                {
                    printf("Calificación ingresada fuera de rango.\n");
                    h--;
                }
            }
        }
    }

    printf("%s\n", estudiantes[0]);
    for (int i = 0; i < numMaterias; i++)
    {
        for (int j = 0; j < califEst1; j++)
        {
            printf("%s\t", materias[i]);
            printf("%.2f\t", califEst1[i][j]);
        }
    }




    
    
    




    
    for (int i = 0; i < numEstudiantes; i++)
    {
        printf("%s\n", estudiantes[i]);
    }
    
    for (int i = 0; i < numMaterias; i++)
    {
        printf("%s\n", materias[i]);
    }
    

    return 0;
}
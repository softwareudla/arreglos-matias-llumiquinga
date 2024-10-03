#include <stdio.h>

#define NUM_ESTUDIANTES 5
#define NUM_MATERIAS 3
#define NUM_CALIF 3
#define ESPACIO_CADENA 21

int main (int argc, char *argv[]) 
{
    char estudiantes[NUM_ESTUDIANTES][ESPACIO_CADENA], materias[NUM_MATERIAS][ESPACIO_CADENA];

    int longitudCadena=0, limpiadorBuffer=0, aprobados=0, reprobados=0, contadorEst=0, saltoColumCalif=0;

    float  promGenerales[NUM_ESTUDIANTES], califMinGenerales[NUM_ESTUDIANTES], califMaxGenenerales[NUM_ESTUDIANTES];

    float   califPorMateria[NUM_CALIF][NUM_MATERIAS*NUM_ESTUDIANTES], 
            promPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS], 
            califMinPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS],
            califMaxPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS];

    for (int i = 0; i < NUM_CALIF; i++)
    {
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            califPorMateria[i][j]=0;
            promPorMateria[i][j]=0;
            califMinPorMateria[i][j]=0;
            califMaxPorMateria[i][j]=0;
        }
    }

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        califMinGenerales[i] = 10;
        califMaxGenenerales[i] = 0;
        promGenerales[i] = 0;
    }


    printf("----------------------------- REGISTRO DE ESTUDIANTES ----------------------------\n");


    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("Ingrese el nombre y apellido o solo el nombre del estudiante %d (MAX 20 caracteres):\n", i+1);
        fflush(stdin);
        fgets(estudiantes[i], ESPACIO_CADENA+1, stdin);  //se suma 1 porque fgets deja un espacio para \0 además de \n  ....'\n''\0'
        
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

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("Ingrese el nombre de la materia %d (MAX 20 caracteres):\n", i+1);
        fflush(stdin);
        fgets(materias[i], ESPACIO_CADENA+1, stdin);
        
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

    while ((contadorEst+1) <= NUM_ESTUDIANTES)
    {
        printf("--------------------------- REGISTRO DE CALIFICACIONES DE %s\n", estudiantes[contadorEst]);
        for (int i = saltoColumCalif; i < NUM_MATERIAS*(contadorEst+1); i++)
        {
            printf("-------------- Ingrese las calificaciones de %s\n", materias[i-saltoColumCalif]);
            for (int j = 0; j < NUM_CALIF; j++)
            {
                scanf("%f", &califPorMateria[j][i]);

                if (califPorMateria[j][i] > 10 || califPorMateria[j][i] < 0)
                {
                    printf("Calificacion ingresada fuera de rango.\n");
                    j--;
                }
            }
        }
        contadorEst++;
        saltoColumCalif=NUM_MATERIAS*contadorEst;
    }

    contadorEst=0;
    saltoColumCalif=0;

    while ((contadorEst + 1) <= NUM_ESTUDIANTES)
    {

        for (int i = 0; i < NUM_MATERIAS; i++)
        {
            for (int j = saltoColumCalif; j < NUM_MATERIAS * (contadorEst + 1); j++)
            {
                promPorMateria[contadorEst][i] = promPorMateria[contadorEst][i] + califPorMateria[j][i];
            }

            promPorMateria[contadorEst][i] = promPorMateria[contadorEst][i] / NUM_CALIF;

            promGenerales[contadorEst] = promGenerales[contadorEst] + promPorMateria[contadorEst][i];
        }

        promGenerales[contadorEst] = promGenerales[contadorEst] / NUM_MATERIAS;

        contadorEst++;
        saltoColumCalif = NUM_MATERIAS * contadorEst;
    }

    contadorEst=0;
    saltoColumCalif=0;

    while ((contadorEst + 1) <= NUM_ESTUDIANTES)
    {

        printf("\n\n** Calificaciones de %s **\n\n", estudiantes[contadorEst]);

        for (int i = 0; i < NUM_MATERIAS; i++)
        {
            printf("%-25s", materias[i]);
        }
        printf("\n");

        for (int i = 0; i < NUM_MATERIAS; i++)
        {
            for (int j = 0; j < 22; j++)
            {
                printf("-");
            }
        }

        printf("\n");

        for (int i = 0; i < NUM_CALIF; i++)
        {
            for (int j = saltoColumCalif; j < NUM_MATERIAS*(contadorEst+1); j++)
            {
                printf("%-25.2f", califPorMateria[i][j]);
            }
            printf("\n");
        }
        contadorEst++;
        saltoColumCalif=NUM_MATERIAS*contadorEst;
    }

    return 0;
}
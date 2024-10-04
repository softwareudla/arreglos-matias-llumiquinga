#include <stdio.h>
#include <string.h>

#define NUM_ESTUDIANTES 5
#define NUM_MATERIAS 3
#define NUM_CALIF 1
#define ESPACIO_CADENA 22
#define NUM_MATERIAS_ESTUDIANTES (NUM_MATERIAS*NUM_ESTUDIANTES)

#define SEPARACION_CADENAS 22
#define SEPARACION_CADENAS_ALINEACION -22
#define CANTIDAD_DE_DECIMALES 2

void ImprimirSeparadores();
void ImprimirMateriasConEspacio(char materia[NUM_MATERIAS][ESPACIO_CADENA]);

int main (int argc, char *argv[]) 
{
    char estudiantes[NUM_ESTUDIANTES][ESPACIO_CADENA], materias[NUM_MATERIAS][ESPACIO_CADENA];

    int longitudCadena=0, limpiadorBuffer=0, contadorEst=0, saltoColumCalif=0;

    float  promGenerales[NUM_ESTUDIANTES], califMinGenerales[NUM_ESTUDIANTES], califMaxGenerales[NUM_ESTUDIANTES];

    float   califPorMateria[NUM_CALIF][NUM_MATERIAS_ESTUDIANTES],

            promPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS], 
            califMinPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS],
            califMaxPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS],

            aprobadosPorMateria[NUM_MATERIAS],
            reprobadosPorMateria[NUM_MATERIAS];


    for (int i = 0; i < NUM_CALIF; i++)
    {
        for (int j = 0; j < NUM_MATERIAS_ESTUDIANTES; j++)
        {
            califPorMateria[i][j]=0;
        }
    }

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            promPorMateria[i][j]=0;
            califMinPorMateria[i][j]=10;
            califMaxPorMateria[i][j]=0;
        }
    }

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        reprobadosPorMateria[i]=0;
        aprobadosPorMateria[i]=0;
    }
    

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        califMinGenerales[i] = 10;
        califMaxGenerales[i] = 0;
        promGenerales[i] = 0;
    }


    printf("----------------------------- REGISTRO DE ESTUDIANTES ----------------------------\n");


    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("Ingrese el nombre y apellido o solo el nombre del estudiante %d (MAX 20 caracteres):\n", i+1);
        fflush(stdin);
        fgets(estudiantes[i], ESPACIO_CADENA, stdin);
        
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
        fgets(materias[i], ESPACIO_CADENA, stdin);
        
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


    //---------------------------------------REGISTRO DE CALIFICACIONES
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




    //---------------------------------------CALCULO PROMEDIO
    while ((contadorEst + 1) <= NUM_ESTUDIANTES)
    {

        for (int i = saltoColumCalif; i < NUM_MATERIAS*(contadorEst+1); i++)
        {
            for (int j = 0; j < NUM_CALIF; j++)
            {
                promPorMateria[contadorEst][i-saltoColumCalif] = promPorMateria[contadorEst][i-saltoColumCalif] + califPorMateria[j][i];
            }

            promPorMateria[contadorEst][i-saltoColumCalif] = promPorMateria[contadorEst][i-saltoColumCalif] / NUM_CALIF;

            promGenerales[contadorEst] = promGenerales[contadorEst] + promPorMateria[contadorEst][i-saltoColumCalif];
        }

        promGenerales[contadorEst] = promGenerales[contadorEst] / NUM_MATERIAS;

        contadorEst++;
        saltoColumCalif = NUM_MATERIAS * contadorEst;
    }

    contadorEst=0;
    saltoColumCalif=0;




    //---------------------------------------CALCULO MIN Y MAX
    while ((contadorEst + 1) <= NUM_ESTUDIANTES)
    {
        for (int i = saltoColumCalif; i < NUM_MATERIAS*(contadorEst+1); i++)
        {
            for (int j = 0; j < NUM_CALIF; j++)
            {
                if (califPorMateria[j][i] < califMinPorMateria[contadorEst][i-saltoColumCalif])
                {
                    califMinPorMateria[contadorEst][i-saltoColumCalif] = califPorMateria[j][i];
                }
                if (califPorMateria[j][i] > califMaxPorMateria[contadorEst][i-saltoColumCalif])
                {
                    califMaxPorMateria[contadorEst][i-saltoColumCalif] = califPorMateria[j][i];
                }
            }
        }

        for (int i = saltoColumCalif; i < NUM_MATERIAS*(contadorEst+1); i++)
        {
            for (int j = 0; j < NUM_CALIF; j++)
            {
                if (califPorMateria[j][i] < califMinGenerales[contadorEst])
                {
                    califMinGenerales[contadorEst] = califPorMateria[j][i];
                }
                if (califPorMateria[j][i] > califMaxGenerales[contadorEst])
                {
                    califMaxGenerales[contadorEst] = califPorMateria[j][i];
                }
            }
        }

        contadorEst++;
        saltoColumCalif = NUM_MATERIAS * contadorEst;
    }

    contadorEst=0;
    saltoColumCalif=0;

    //---------------------------------------CALCULO APROBADOS REPROBADOS

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            if (promPorMateria[i][j]>=6)
            {
                aprobadosPorMateria[j]++;
            }else{
                reprobadosPorMateria[j]++;
            }
        }
    }


    //-----------------------------------------IMPRIMIR CALIFICACIONES
    while ((contadorEst + 1) <= NUM_ESTUDIANTES)
    {
        printf("\n\n\n");
        printf("** Calificaciones de %s **\n\n", estudiantes[contadorEst]);

        for (int i = 0; i < NUM_MATERIAS; i++)
        {
            printf("%*s", SEPARACION_CADENAS_ALINEACION, materias[i]);
        }
        printf("\n");

        ImprimirSeparadores();

        for (int i = 0; i < NUM_CALIF; i++)
        {
            for (int j = saltoColumCalif; j < NUM_MATERIAS*(contadorEst+1); j++)
            {
                printf("%*.*f", SEPARACION_CADENAS_ALINEACION, CANTIDAD_DE_DECIMALES, califPorMateria[i][j]);
            }
            printf("\n");
        }
        contadorEst++;
        saltoColumCalif=NUM_MATERIAS*contadorEst;

        ImprimirSeparadores();
    }

    contadorEst=0;
    saltoColumCalif=0;





    //---------------------Impresion Promedios
    printf("\n\n\n");
    printf("PROMEDIOS POR MATERIAS:\n\n");
    
    ImprimirMateriasConEspacio(materias);
    ImprimirSeparadores();

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%*s", SEPARACION_CADENAS_ALINEACION, estudiantes[i]);
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            printf("%*.*f", SEPARACION_CADENAS_ALINEACION, CANTIDAD_DE_DECIMALES, promPorMateria[i][j]);
        }
        printf("\n");
    }

    ImprimirSeparadores();
    printf("\n");
    printf("PROMEDIOS GENERALES:\n\n");



    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%-22s",  estudiantes[i]);
    }
    
    printf("\n");
    ImprimirSeparadores();

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%-22.2f",  promGenerales[i]);
    }
    printf("\n");



    //---------------------Impresion Min Max

    printf("------------Min\n");

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            printf("%.2f\t", califMinPorMateria[i][j]);
        }
        printf("\n");
    }
    printf("------------Max\n");

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            printf("%.2f\t", califMaxPorMateria[i][j]);
        }
        printf("\n");
    }

    printf("------------Min generales\n");

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%.2f\t",  califMinGenerales[i]);
    }
    printf("\n");

    printf("------------Max generales\n");

    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%.2f\t",  califMaxGenerales[i]);
    }

    printf("\n");


    //---------------------Impresion Aprobados y Reprobados
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

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("%-25.2f", aprobadosPorMateria[i]);
    }

    printf("\n");

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("%-25.2f", reprobadosPorMateria[i]);
    }
    return 0;
}

void ImprimirSeparadores()
{
    for (int i = 0; i < NUM_MATERIAS+1; i++)
    {
        for (int j = 0; j < SEPARACION_CADENAS; j++)
        {
            printf("-");
        }
    }

    printf("\n");
}

void ImprimirMateriasConEspacio(char materia[NUM_MATERIAS][ESPACIO_CADENA])
{
    printf("%*s", SEPARACION_CADENAS_ALINEACION, "");
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("%*s", SEPARACION_CADENAS_ALINEACION, materia[i]);
    }
    printf("\n");
}
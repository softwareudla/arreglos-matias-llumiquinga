#include <stdio.h>
#include <string.h>


#define NUM_ESTUDIANTES 5
#define NUM_MATERIAS 3
#define NUM_CALIF 3
#define ESPACIO_CADENA 22
#define NUM_MATERIAS_ESTUDIANTES (NUM_MATERIAS*NUM_ESTUDIANTES)

#define SEPARACION_CADENAS 22
#define SEPARACION_CADENAS_ALINEACION -22
#define CANTIDAD_DE_DECIMALES 2

void ImprimirSeparadoresMaterias();
void ImprimirSeparadoresEstudiantes();
void ImprimirMateriasConEspacio(char materia[NUM_MATERIAS][ESPACIO_CADENA]);
void ImprimirNombres_Notas(char estuadiante[NUM_ESTUDIANTES][ESPACIO_CADENA], float califEstudiante[NUM_ESTUDIANTES][NUM_MATERIAS]);
void ImprimirValoresGenerales(float notasGenerales[NUM_ESTUDIANTES]);
void ImprimirNombresColumnas(char estuadiante[NUM_ESTUDIANTES][ESPACIO_CADENA]);

int main (int argc, char *argv[]) 
{
    char estudiantes[NUM_ESTUDIANTES][ESPACIO_CADENA], materias[NUM_MATERIAS][ESPACIO_CADENA];

    int longitudCadena=0, limpiadorBuffer=0, contadorEst=0, saltoColumCalif=0;

    float  promGenerales[NUM_ESTUDIANTES], califMinGenerales[NUM_ESTUDIANTES], califMaxGenerales[NUM_ESTUDIANTES];

    float   califPorMateria[NUM_CALIF][NUM_MATERIAS_ESTUDIANTES],

            promPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS], 
            califMinPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS],
            califMaxPorMateria[NUM_ESTUDIANTES][NUM_MATERIAS];

    int     aprobadosPorMateria[NUM_MATERIAS],
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
            printf("-------------- Ingrese las calificaciones de %s (0-10)\n", materias[i-saltoColumCalif]);
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

        ImprimirSeparadoresMaterias();

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

        ImprimirSeparadoresMaterias();
    }

    contadorEst=0;
    saltoColumCalif=0;





    //---------------------Impresion Promedios
    printf("\n\n\n");
    printf("PROMEDIOS POR MATERIAS:\n\n");
    ImprimirMateriasConEspacio(materias);
    ImprimirSeparadoresMaterias();
    ImprimirNombres_Notas(estudiantes, promPorMateria);
    ImprimirSeparadoresMaterias();

    printf("\n");
    printf("PROMEDIOS GENERALES:\n\n");
    ImprimirNombresColumnas(estudiantes);
    ImprimirSeparadoresEstudiantes();
    ImprimirValoresGenerales(promGenerales);
    ImprimirSeparadoresEstudiantes();



    //---------------------Impresion Min Max

    printf("\n\n");
    printf("NOTAS MINIMAS POR MATERIAS:\n\n");
    ImprimirMateriasConEspacio(materias);
    ImprimirSeparadoresMaterias();
    ImprimirNombres_Notas(estudiantes,califMinPorMateria);
    ImprimirSeparadoresMaterias();

    printf("\n");
    printf("NOTAS MINIMAS GENERALES:\n\n");
    ImprimirNombresColumnas(estudiantes);
    ImprimirSeparadoresEstudiantes();
    ImprimirValoresGenerales(califMinGenerales);
    ImprimirSeparadoresEstudiantes();

    printf("\n\n");
    printf("NOTAS MAXIMAS POR MATERIAS:\n\n");
    ImprimirMateriasConEspacio(materias);
    ImprimirSeparadoresMaterias();
    ImprimirNombres_Notas(estudiantes,califMaxPorMateria);
    ImprimirSeparadoresMaterias();

    printf("\n");
    printf("NOTAS MAXIMAS GENERALES:\n\n");
    ImprimirNombresColumnas(estudiantes);
    ImprimirSeparadoresEstudiantes();
    ImprimirValoresGenerales(califMaxGenerales);
    ImprimirSeparadoresEstudiantes();




    //---------------------Impresion Aprobados y Reprobados
    printf("\n\n");

    printf("APROBADOS-REPROBADOS POR MATERIAS:\n\n");
    ImprimirMateriasConEspacio(materias);
    ImprimirSeparadoresMaterias();

    printf("%*s", SEPARACION_CADENAS_ALINEACION, "APROBADOS");
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("%*i", SEPARACION_CADENAS_ALINEACION, aprobadosPorMateria[i]);
    }

    printf("\n");

    printf("%*s", SEPARACION_CADENAS_ALINEACION, "REPROBADOS");
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("%*i", SEPARACION_CADENAS_ALINEACION, reprobadosPorMateria[i]);
    }

    printf("\n");
    ImprimirSeparadoresMaterias();

    return 0;
}




void ImprimirSeparadoresMaterias()
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

void ImprimirSeparadoresEstudiantes()
{
    for (int i = 0; i < NUM_ESTUDIANTES; i++)
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

void ImprimirNombres_Notas(char estuadiante[NUM_ESTUDIANTES][ESPACIO_CADENA], float califEstudiante[NUM_ESTUDIANTES][NUM_MATERIAS])
{
    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%*s", SEPARACION_CADENAS_ALINEACION, estuadiante[i]);
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            printf("%*.*f", SEPARACION_CADENAS_ALINEACION, CANTIDAD_DE_DECIMALES, califEstudiante[i][j]);
        }
        printf("\n");
    }
}

void ImprimirValoresGenerales(float notasGenerales[NUM_ESTUDIANTES])
{
    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%*.*f", SEPARACION_CADENAS_ALINEACION, CANTIDAD_DE_DECIMALES,  notasGenerales[i]);
    }
    printf("\n");
}

void ImprimirNombresColumnas(char estuadiante[NUM_ESTUDIANTES][ESPACIO_CADENA])
{
    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        printf("%*s", SEPARACION_CADENAS_ALINEACION, estuadiante[i]);
    }
    printf("\n");
}
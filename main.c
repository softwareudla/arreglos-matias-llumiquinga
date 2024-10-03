#include <stdio.h>
#include <string.h>

#define NUM_ESTUDIANTES 2
#define NUM_MATERIAS 2
#define NUM_CALIF 6
#define ESPACIO_CADENA 21


void RegistrarCalificaciones(   char estudiant[NUM_ESTUDIANTES][ESPACIO_CADENA], int numEst, 
                                char materia[NUM_MATERIAS][ESPACIO_CADENA],
                                float califEst[NUM_CALIF][NUM_MATERIAS]);

void ImprimirResultados(char estudiant[NUM_ESTUDIANTES][ESPACIO_CADENA], int numEst,
                        char materi[NUM_MATERIAS][ESPACIO_CADENA], 
                        float califiEstud[NUM_CALIF][NUM_MATERIAS],
                        float promMaterEst[NUM_MATERIAS],
                        float promGenera[NUM_ESTUDIANTES],
                        float califMinEst[NUM_MATERIAS],
                        float califMaxEst[NUM_MATERIAS],
                        float minEst,
                        float maxEst);



int main (int argc, char *argv[]) 
{
    int longitudCadena, limpiadorBuffer;

    float   califEst1[NUM_CALIF][NUM_MATERIAS], 
            promMateriasEst1[NUM_MATERIAS], califMinEst1[NUM_MATERIAS],califMaxEst1[NUM_MATERIAS], promGenerales[NUM_ESTUDIANTES];

    float minEst1=0, maxEst1=0, min, max;

    char estudiantes[NUM_ESTUDIANTES][ESPACIO_CADENA], materias[NUM_MATERIAS][ESPACIO_CADENA];

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        promMateriasEst1[i] = 0;
        califMinEst1[i] = 10;
        califMaxEst1[i] = 0;
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

    RegistrarCalificaciones(estudiantes,0,materias, califEst1);


    //----------------------CÁLCULO DE PROMEDIOS
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        for (int j = 0; j < NUM_CALIF; j++)
        {
            promMateriasEst1[i]= promMateriasEst1[i]+califEst1[j][i];
        }

        promMateriasEst1[i]=promMateriasEst1[i]/NUM_CALIF;

        promGenerales[0] = promGenerales[0] + promMateriasEst1[i];
    }

    promGenerales[0] = promGenerales[0]/NUM_MATERIAS;

    



    //----------------------CÁLCULO DE MIN Y MAX
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        min=10;
        max=0;

        for (int j = 0; j < NUM_CALIF; j++)
        {
            if (califEst1[j][i]<min)
            {
                min = califEst1[j][i];
                califMinEst1[i]=min;
            }
            if (califEst1[j][i]>max)
            {
                max = califEst1[j][i];
                califMaxEst1[i]= max;
            }
        }       
    }

    min=10;
    max=0;

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        for (int j = 0; j < NUM_CALIF; j++)
        {
            if (califEst1[j][i]<min)
            {
                min = califEst1[j][i];
                minEst1=min;
            }
            if (califEst1[j][i]>max)
            {
                max = califEst1[j][i];
                maxEst1= max;
            }
        }   
    }
    


    ImprimirResultados( estudiantes, 0, materias, califEst1, 
                        promMateriasEst1, promGenerales, califMinEst1, 
                        califMaxEst1, minEst1,maxEst1);
    

    return 0;
}



void RegistrarCalificaciones(   char estudiant[NUM_ESTUDIANTES][ESPACIO_CADENA], int numEst, 
                                char materia[NUM_MATERIAS][ESPACIO_CADENA],
                                float califEst[NUM_CALIF][NUM_MATERIAS])
{
    printf("--------------------------- REGISTRO DE CALIFICACIONES DE %s\n", estudiant[0]);
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("-------------- Ingrese las calificaciones de %s\n", materia[i]);
        for (int j = 0; j < NUM_CALIF; j++)
        {
            scanf("%f", &califEst[j][i]);

            if (califEst[j][i] > 10 || califEst[j][i] < 0)
            {
                printf("Calificacion ingresada fuera de rango.\n");
                j--;
            }
        }
    }


}


















void ImprimirResultados(char estudiant[NUM_ESTUDIANTES][ESPACIO_CADENA], int numEst,
                        char materi[NUM_MATERIAS][ESPACIO_CADENA], 
                        float califiEstud[NUM_CALIF][NUM_MATERIAS],
                        float promMaterEst[NUM_MATERIAS],
                        float promGenera[NUM_ESTUDIANTES],
                        float califMinEst[NUM_MATERIAS],
                        float califMaxEst[NUM_MATERIAS],
                        float minEst,
                        float maxEst)
{
    //----------------------CALIFICACIONES
    printf("** Calificaciones de %s **\n\n", estudiant[numEst]);

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        printf("%-25s", materi[i]);
    }

    printf("\n");

    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    for (int i = 0; i < NUM_CALIF; i++)
    {      
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            printf("%-25.2f", califiEstud[i][j]);
        }
        printf("\n");
    
    }
    
    //----------------------PROMEDIO POR MATERIA

    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("Promedio Por Materia:\n");


    for (int i = 0; i < NUM_MATERIAS; i++)
    {
         printf("%-25s%.2f\n", materi[i], promMaterEst[i]);
    }


    

    //----------------------PROMEDIO GENERAL


    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("%-25s%.2f\n", "Promedio General:", promGenera[numEst]);



    //----------------------CALIFICACIÓN MIN POR MATERIA

    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("Calif Min Por Materia:\n");
    


    for (int i = 0; i < NUM_MATERIAS; i++)
    {
         printf("%-25s%.2f\n", materi[i], califMinEst[i]);
         fflush(stdout);
    }
    

    //----------------------CALIFICACIÓN MAX POR MATERIA

    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("Calif Max Por Materia:\n");


    for (int i = 0; i < NUM_MATERIAS; i++)
    {
         printf("%-25s%.2f\n", materi[i], califMaxEst[i]);
    }


    //----------------------CALIFICACIÓN MIN GENERAL


    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("%-25s%.2f\n", "Calif Min General:", minEst);



    //----------------------CALIFICACIÓN MAX GENERAL


    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("%-25s%.2f\n", "Calif Max General:", maxEst);


    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }
}
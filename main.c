#include <stdio.h>
#include <string.h>

#define NUM_ESTUDIANTES 5
#define NUM_MATERIAS 3
#define NUM_CALIF 5
#define ESPACIO_CADENA 21


void RegistrarCalificaciones(   float califEst[NUM_CALIF][NUM_MATERIAS], int numEst, 
                                char materia[NUM_MATERIAS][ESPACIO_CADENA],
                                char estudiant[NUM_ESTUDIANTES][ESPACIO_CADENA]);

void CalcularPromedios( float promGeneral[NUM_ESTUDIANTES], int numEst, 
                        float promMateriasEst[NUM_MATERIAS],
                        float califEst[NUM_CALIF][NUM_MATERIAS]);

void CalcularMinMax(    float califEst[NUM_CALIF][NUM_MATERIAS], int numEst,
                        float califMinEst[NUM_MATERIAS],
                        float califMaxEst[NUM_MATERIAS],
                        float calfMinGeneral[NUM_ESTUDIANTES],
                        float calfMaxGeneral[NUM_ESTUDIANTES]);

void ImprimirResultados(char estudiant[NUM_ESTUDIANTES][ESPACIO_CADENA], int numEst,
                        char materi[NUM_MATERIAS][ESPACIO_CADENA], 
                        float califiEstud[NUM_CALIF][NUM_MATERIAS],
                        float promMaterEst[NUM_MATERIAS],
                        float promGenera[NUM_ESTUDIANTES],
                        float califMinEst[NUM_MATERIAS],
                        float califMaxEst[NUM_MATERIAS],
                        float minEst[NUM_ESTUDIANTES],
                        float maxEst[NUM_ESTUDIANTES]);



int main (int argc, char *argv[]) 
{
    char estudiantes[NUM_ESTUDIANTES][ESPACIO_CADENA], materias[NUM_MATERIAS][ESPACIO_CADENA];

    int longitudCadena, limpiadorBuffer, aprobados=0, reprobados=0;

    float   promGenerales[NUM_ESTUDIANTES], califMinGenerales[NUM_ESTUDIANTES], califMaxGenenerales[NUM_ESTUDIANTES];


    float   califEst1[NUM_CALIF][NUM_MATERIAS], 
            promMateriasEst1[NUM_MATERIAS], califMinEst1[NUM_MATERIAS],califMaxEst1[NUM_MATERIAS];

    float   califEst2[NUM_CALIF][NUM_MATERIAS], 
            promMateriasEst2[NUM_MATERIAS], califMinEst2[NUM_MATERIAS],califMaxEst2[NUM_MATERIAS];

    float   califEst3[NUM_CALIF][NUM_MATERIAS], 
            promMateriasEst3[NUM_MATERIAS], califMinEst3[NUM_MATERIAS],califMaxEst3[NUM_MATERIAS];

    float   califEst4[NUM_CALIF][NUM_MATERIAS], 
            promMateriasEst4[NUM_MATERIAS], califMinEst4[NUM_MATERIAS],califMaxEst4[NUM_MATERIAS];

    float   califEst5[NUM_CALIF][NUM_MATERIAS], 
            promMateriasEst5[NUM_MATERIAS], califMinEst5[NUM_MATERIAS],califMaxEst5[NUM_MATERIAS];
            


    for (int i = 0; i < NUM_CALIF; i++)
    {
        for (int j = 0; j < NUM_MATERIAS; j++)
        {
            califEst1[i][j]=0;
            califEst2[i][j]=0;
            califEst3[i][j]=0;
            califEst4[i][j]=0;
            califEst5[i][j]=0;
        }
        
    }
    

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        promMateriasEst1[i] = 0;
        califMinEst1[i] = 10;
        califMaxEst1[i] = 0;
        
        promMateriasEst2[i] = 0;
        califMinEst2[i] = 10;
        califMaxEst2[i] = 0;

        promMateriasEst3[i] = 0;
        califMinEst3[i] = 10;
        califMaxEst3[i] = 0;

        promMateriasEst4[i] = 0;
        califMinEst4[i] = 10;
        califMaxEst4[i] = 0;

        promMateriasEst5[i] = 0;
        califMinEst5[i] = 10;
        califMaxEst5[i] = 0;
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


    //-------------------------------------ESTUDIANTE 1
    RegistrarCalificaciones(califEst1,0,materias, estudiantes);
    CalcularPromedios(promGenerales,0,promMateriasEst1,califEst1);
    CalcularMinMax(califEst1, 0, califMinEst1, califMaxEst1,califMinGenerales,califMaxGenenerales);

    //-------------------------------------ESTUDIANTE 2
    RegistrarCalificaciones(califEst2,1,materias, estudiantes);
    CalcularPromedios(promGenerales,1,promMateriasEst2,califEst2);
    CalcularMinMax(califEst2, 1, califMinEst2, califMaxEst2,califMinGenerales,califMaxGenenerales);

    //-------------------------------------ESTUDIANTE 3
    RegistrarCalificaciones(califEst3,2,materias, estudiantes);
    CalcularPromedios(promGenerales,2,promMateriasEst3,califEst3);
    CalcularMinMax(califEst3, 2, califMinEst3, califMaxEst3,califMinGenerales,califMaxGenenerales);

    //-------------------------------------ESTUDIANTE 4
    RegistrarCalificaciones(califEst4,3,materias, estudiantes);
    CalcularPromedios(promGenerales,3,promMateriasEst4,califEst4);
    CalcularMinMax(califEst4, 3, califMinEst4, califMaxEst4,califMinGenerales,califMaxGenenerales);
    
    //-------------------------------------ESTUDIANTE 5
    RegistrarCalificaciones(califEst5,4,materias, estudiantes);
    CalcularPromedios(promGenerales,4,promMateriasEst5,califEst5);
    CalcularMinMax(califEst5, 4, califMinEst5, califMaxEst5,califMinGenerales,califMaxGenenerales);




    //-------------------------------------ESTUDIANTE 1
    ImprimirResultados( estudiantes, 0, materias, califEst1, 
                        promMateriasEst1, promGenerales, califMinEst1, 
                        califMaxEst1, califMinGenerales,califMaxGenenerales);
    
    //-------------------------------------ESTUDIANTE 2
    ImprimirResultados( estudiantes, 1, materias, califEst2, 
                        promMateriasEst2, promGenerales, califMinEst2, 
                        califMaxEst2, califMinGenerales,califMaxGenenerales);

    //-------------------------------------ESTUDIANTE 3
    ImprimirResultados( estudiantes, 2, materias, califEst3, 
                        promMateriasEst3, promGenerales, califMinEst3, 
                        califMaxEst3, califMinGenerales,califMaxGenenerales);

    //-------------------------------------ESTUDIANTE 4
    ImprimirResultados( estudiantes, 3, materias, califEst4, 
                        promMateriasEst4, promGenerales, califMinEst4, 
                        califMaxEst4, califMinGenerales,califMaxGenenerales);

    //-------------------------------------ESTUDIANTE 5
    ImprimirResultados( estudiantes, 4, materias, califEst5, 
                        promMateriasEst5, promGenerales, califMinEst5, 
                        califMaxEst5, califMinGenerales,califMaxGenenerales);
    
    for (int i = 0; i < NUM_ESTUDIANTES; i++)
    {
        if (promGenerales[i]>=6)
        {
            aprobados++;
        }else
        {
            reprobados++;
        }
        
    }

    printf("\nAlumnos APROBADOS: %d\n",aprobados);
    printf("Alumnos REPROBADOS: %d\n",reprobados);


    


    return 0;
}



void RegistrarCalificaciones(   float califEst[NUM_CALIF][NUM_MATERIAS], int numEst, 
                                char materia[NUM_MATERIAS][ESPACIO_CADENA],
                                char estudiant[NUM_ESTUDIANTES][ESPACIO_CADENA])
{
    printf("--------------------------- REGISTRO DE CALIFICACIONES DE %s\n", estudiant[numEst]);
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




void CalcularPromedios( float promGeneral[NUM_ESTUDIANTES], int numEst, 
                        float promMateriasEst[NUM_MATERIAS],
                        float califEst[NUM_CALIF][NUM_MATERIAS])
{
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        for (int j = 0; j < NUM_CALIF; j++)
        {
            promMateriasEst[i]= promMateriasEst[i]+califEst[j][i];
        }

        promMateriasEst[i]=promMateriasEst[i]/NUM_CALIF;

        promGeneral[numEst] = promGeneral[numEst] + promMateriasEst[i];
    }

    promGeneral[numEst] = promGeneral[numEst]/NUM_MATERIAS;
}



void CalcularMinMax(    float califEst[NUM_CALIF][NUM_MATERIAS], int numEst,
                        float califMinEst[NUM_MATERIAS],
                        float califMaxEst[NUM_MATERIAS],
                        float calfMinGeneral[NUM_ESTUDIANTES],
                        float calfMaxGeneral[NUM_ESTUDIANTES])
{
    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        for (int j = 0; j < NUM_CALIF; j++)
        {
            if (califEst[j][i]<califMinEst[i])
            {
                califMinEst[i]=califEst[j][i];
            }
            if (califEst[j][i]>califMaxEst[i])
            {
                califMaxEst[i]=califEst[j][i];
            }
        }       
    }

    for (int i = 0; i < NUM_MATERIAS; i++)
    {
        for (int j = 0; j < NUM_CALIF; j++)
        {
            if (califEst[j][i]<calfMinGeneral[numEst])
            {
                calfMinGeneral[numEst]=califEst[j][i];
            }
            if (califEst[j][i]>calfMaxGeneral[numEst])
            {
                calfMaxGeneral[numEst]=califEst[j][i];
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
                        float minEst[NUM_ESTUDIANTES],
                        float maxEst[NUM_ESTUDIANTES])
{
    //----------------------CALIFICACIONES
    printf("\n\n** Calificaciones de %s **\n\n", estudiant[numEst]);

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

    printf("%-25s%.2f\n", "Calif Min General:", minEst[numEst]);



    //----------------------CALIFICACIÓN MAX GENERAL


    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("%-25s%.2f\n", "Calif Max General:", maxEst[numEst]);


    for (int i = 0; i < NUM_MATERIAS; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

}
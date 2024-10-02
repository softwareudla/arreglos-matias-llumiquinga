#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
    const int numEstudiantes = 2, numMaterias = 2, numCalif=6, espacioCadena = 21, filasResultados=1;
    int longitudCadena, limpiadorBuffer;

    float   califEst1[numCalif][numMaterias], promMateriasEst1[numMaterias],
            califMinEst1[numMaterias],califMaxEst1[numMaterias];

    float promEst1=0, minEst1=0, maxEst1=0, min, max;

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


    printf("--------------------------- REGISTRO DE CALIFICACIONES DE %s\n", estudiantes[0]);
    for (int i = 0; i < numMaterias; i++)
    {
        printf("-------------- Ingrese las calificaciones de %s\n", materias[i]);
        for (int j = 0; j < numCalif; j++)
        {
            scanf("%f", &califEst1[j][i]);

            if (califEst1[j][i] > 10 || califEst1[j][i] < 0)
            {
                printf("Calificación ingresada fuera de rango.\n");
                j--;
            }
        }

    }

    //----------------------CÁLCULO DE PROMEDIOS
    for (int i = 0; i < numMaterias; i++)
    {
        for (int j = 0; j < numCalif; j++)
        {
            promMateriasEst1[i]= promMateriasEst1[i]+califEst1[j][i];
        }
        promMateriasEst1[i]=promMateriasEst1[i]/numCalif;

        promEst1 = promEst1 + promMateriasEst1[i];
    }

        promEst1 =promEst1/numMaterias;




    //----------------------CÁLCULO DE MIN Y MAX
    for (int i = 0; i < numMaterias; i++)
    {
        min=10;
        max=0;

        for (int j = 0; j < numCalif; j++)
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

    for (int i = 0; i < numMaterias; i++)
    {
        for (int j = 0; j < numCalif; j++)
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
    







    //----------------------CALIFICACIONES
    printf("** Calificaciones de %s **\n\n", estudiantes[0]);

    for (int i = 0; i < numMaterias; i++)
    {
        printf("%-25s", materias[i]);
    }

    printf("\n");

    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    for (int i = 0; i < numCalif; i++)
    {      
        for (int j = 0; j < numMaterias; j++)
        {
            printf("%-25.2f", califEst1[i][j]);
        }
        printf("\n");
    
    }
    
    //----------------------PROMEDIO POR MATERIA

    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("Promedio Por Materia:\n");


    for (int i = 0; i < numMaterias; i++)
    {
         printf("%-25s%.2f\n", materias[i], promMateriasEst1[i]);
    }


    

    //----------------------PROMEDIO GENERAL


    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("%-25s%.2f\n", "Promedio General:", promEst1);



    //----------------------CALIFICACIÓN MIN POR MATERIA

    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("Calificacion Minima Por Materia:\n");


    for (int i = 0; i < numMaterias; i++)
    {
         printf("%-25s%.2f\n", materias[i], califMinEst1[i]);
    }
    

    //----------------------CALIFICACIÓN MAX POR MATERIA

    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("Calificacion Maxima Por Materia:\n");


    for (int i = 0; i < numMaterias; i++)
    {
         printf("%-25s%.2f\n", materias[i], califMaxEst1[i]);
    }


    //----------------------CALIFICACIÓN MIN GENERAL


    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("%-25s%.2f\n", "Calif Min General:", minEst1);



    //----------------------CALIFICACIÓN MAX GENERAL


    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }

    printf("\n");

    printf("%-25s%.2f\n", "Calif Max General:", maxEst1);


    for (int i = 0; i < numMaterias; i++) 
    {
        for (int j = 0; j < 22; j++) {
            printf("-");
        }
    }
    

    

    return 0;
}
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


#define MAX_PALABRAS 10
#define MAX_LONGITUD 50

int main () {

    printf(" --------------------------------------------------------------------\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf("|                                                                    |\n");
    printf(" --------------------------------------------------------------------\n");

   
   

    /*FILE *archivo = fopen("comida.txt", "r");
    if (archivo == NULL) {
    printf("No se pudo abrir el archivo\n");
    return 1;
    }*/
    //char c;
    char palabras[MAX_PALABRAS][MAX_LONGITUD]; 

    int contador = 0;

     // Leer el contenido del archivo carácter por carácter y mostrarlo en pantalla
    /*while ((c = fgetc(archivo)) != EOF) {
        printf("%c", c);
    }*/
   /*//elije una palabra sola que en este caso es la primera 
   if (fgets(palabra, sizeof(palabra), archivo) != NULL) {
        // Eliminar el salto de línea
        palabra[strcspn(palabra, "\n")] = 0;
        
        // Imprimir la palabra guardada
        printf("Palabra guardada: %s\n", palabra);
    } else {
        printf("El archivo está vacío\n");
    }*/
 
   // lee el arreglo y lo guarda en un arreglo 
    /*while (fgets(palabras[contador], sizeof(palabras[contador]), archivo) != NULL) {
        // Eliminar el salto de línea
        palabras[contador][strcspn(palabras[contador], "\n")] = 0;
        contador++;
        if (contador >= MAX_PALABRAS) break; // Limitar el número de palabras
    }

    

    fclose(archivo);*/
   
    int dificultad, temática;

    printf("ingrese la dificualtad =     facil(1)   medio(2)     hardcore(3)");
    scanf("%d",&dificultad);

    switch (dificultad)
    {
    case 1:
        FILE *archivo1 = fopen("comidafacil.txt", "r");
        if (archivo1 == NULL) {
            printf("No se pudo abrir el archivo\n");
        return 1;
        }
        char palabras1[MAX_PALABRAS][MAX_LONGITUD]; 
        srand(time(NULL));
        int random1 = rand() % MAX_PALABRAS; 
        int contador1 = 0;
        
        while (fgets(palabras1[contador1], sizeof(palabras1[contador1]), archivo1) != NULL) {
            
            palabras1[contador1][strcspn(palabras1[contador1], "\n")] = 0;
            contador1++;
            if (contador1 >= MAX_PALABRAS) break; // Limitar el número de palabras
        }
        printf("%s",palabras1[random1]);
        fclose(archivo1);
        break;


    case 2:
        FILE *archivo2 = fopen("comidamedio.txt", "r");
        if (archivo2 == NULL) {
            printf("No se pudo abrir el archivo\n");
        return 1;
        }

        char palabras2[MAX_PALABRAS][MAX_LONGITUD]; 
        srand(time(NULL));
        int random2 = rand() % MAX_PALABRAS; 
        int contador2 = 0;
        // lee el arreglo y lo guarda en un arreglo 
        while (fgets(palabras2[contador2], sizeof(palabras2[contador2]), archivo2) != NULL) {
        // Eliminar el salto de línea
        palabras2[contador2][strcspn(palabras2[contador2], "\n")] = 0;
        contador2++;
        if (contador2 >= MAX_PALABRAS) break; // Limitar el número de palabras
        }
        printf("%s",palabras2[random2]);
        fclose(archivo2);
        break;    
    case 3:
        FILE *archivo3 = fopen("comidadificil.txt", "r");
        if (archivo3 == NULL) {
            printf("No se pudo abrir el archivo\n");
        return 1;
        }
        char palabras3[MAX_PALABRAS][MAX_LONGITUD]; 
        srand(time(NULL));
        int random3 = rand() % MAX_PALABRAS; 

        int contador3 = 0;
        // lee el arreglo y lo guarda en un arreglo 
        while (fgets(palabras3[contador3], sizeof(palabras3[contador3]), archivo3) != NULL) {
        // Eliminar el salto de línea
        palabras3[contador3][strcspn(palabras3[contador3], "\n")] = 0;
        contador3++;
        if (contador3 >= MAX_PALABRAS) break; // Limitar el número de palabras
        }
        printf("%s",palabras3[random3]);

        fclose(archivo3);
        break;

    default:
        printf("Recurede es  1 facil 2 medio 3 dificil.");
        break;
    }


    return 0;
 
}

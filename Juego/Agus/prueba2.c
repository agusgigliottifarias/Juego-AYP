#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


#define MAX_PALABRAS 20
#define MAX_LONGITUD 50

void intento (FILE *archivo,char palabras1[MAX_PALABRAS][MAX_LONGITUD],char palabraEnJuego[MAX_LONGITUD]){
    if (archivo == NULL) {
            printf("No se pudo abrir el archivo\n");
        return;
        }
        
        srand(time(NULL));
        int random1 = rand() % MAX_PALABRAS; 
        int contador1 = 0;
        
        while (fgets(palabras1[contador1], sizeof(palabras1[contador1]), archivo) != NULL) {
            
            palabras1[contador1][strcspn(palabras1[contador1], "\n")] = 0;
            contador1++;
            if (contador1 >= MAX_PALABRAS){
            fclose(archivo);
            break; 
            }
        }
        fclose(archivo);
       
        strcpy(palabraEnJuego, palabras1[random1]);
}




int main () {
    char palabras[MAX_PALABRAS][MAX_LONGITUD],palabraEnJuego[MAX_LONGITUD];

    int contador = 0;

    int dificultad, temática;

    printf("ingrese la dificualtad =     facil(1)   medio(2)     hardcore(3)");
    scanf("%d",&dificultad);

    switch (dificultad)
    {
    case 1:
        FILE *archivo1 = fopen("comidafacil.txt", "r");
        intento(archivo1,palabras,palabraEnJuego);
        break;
    case 2:
        FILE *archivo2 = fopen("comidamedio.txt", "r");
        intento(archivo2,palabras,palabraEnJuego);
        break;
    case 3:
        FILE *archivo3 = fopen("comidadificil.txt", "r");
        intento(archivo3,palabras,palabraEnJuego);
        break;
    default:
        printf("Recuerde es  1 facil, 2 medio, 3 dificil.");
        break;
    }

    
    
    //pasa la palabra cada caracter al indice dle arreglo
    
    char caracteres[MAX_LONGITUD]; 
    int tamanio = strlen(palabraEnJuego);
    
    for (int i = 0; i < tamanio; i++) {
        caracteres[i] = palabraEnJuego[i];
    }
    
    
    caracteres[strlen(palabraEnJuego)] = '\0'; //ver que hace esto

    
    printf("La palabra en juego es: %s\n", palabraEnJuego);
    printf("Los caracteres en el arreglo son:\n");

     printf("La palabra en juego es: %s\n", palabraEnJuego);
      for (int i = 0; i < (tamanio-1); i++) {
        printf("Caracter %d: %c\n", i, caracteres[i]);
    }


    //función de juego en si




    
    return 0;
 
}

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


#define MAX_PALABRAS 20
#define MAX_LONGITUD 50

//función jugador y reglas de juego
void reglasDeJuego(void){
    char name[100];
    printf("Ingrese su nombre: ",name);
    scanf("%s",&name);
    printf("Bienvenido %s al ahorcado\n",name);
    printf("\n");
    printf("Presione enter para continuar");
    while (getchar() != '\n');
    getchar();
};

//función para elección palabra
void eleccionDificultad (FILE *archivo,char palabras1[MAX_PALABRAS][MAX_LONGITUD],char palabraEnJuego[MAX_LONGITUD]){
    if (archivo == NULL) {
            printf("No se pudo abrir el archivo\n");
        return;
        }
        
        srand(time(NULL));
        int random1 = rand() % (MAX_PALABRAS+1); 
        int contador1 = 0;
        
        while (fgets(palabras1[contador1], sizeof(palabras1[contador1]), archivo) != NULL) {
            
            palabras1[contador1][strcspn(palabras1[contador1], "\n")] = 0;
            contador1++;
            if (contador1 >= MAX_PALABRAS){
            fclose(archivo);
            break; 
            }
        }
        printf("%s",palabras1[random1]);
        fclose(archivo);
       
        strcpy(palabraEnJuego, palabras1[random1]);
}


int main () {

    reglasDeJuego();

    char palabras[MAX_PALABRAS][MAX_LONGITUD],palabraEnJuego[MAX_LONGITUD];

    int contador = 0;

    int dificultad, temática;
    printf("ingrese la temática que desea jugar = paises(1) marcas(2) objetos (3) ");
    scanf("%d",&temática);
    printf("ingrese la dificualtad =     facil(1)   medio(2)     hardcore(3) ");
    scanf("%d",&dificultad);

    FILE *archivo = NULL;

    switch (temática) {
    case 1:  // Caso de países
        switch (dificultad) {
            case 1:
                archivo = fopen("tematicas/paises/paisesfacil.txt", "r");
                break;
            case 2:
                archivo = fopen("tematicas/paises/paisesmedio.txt", "r");
                break;
            case 3:
                archivo = fopen("tematicas/paises/paiseshardcore.txt", "r");
                break;
            default:
                printf("Recuerde que 1 es fácil, 2 es medio, 3 es difícil.\n");
                break;
        }
        break;

    case 2:  // Caso de marcas
        switch (dificultad) {
            case 1:
                archivo = fopen("tematicas/marcas/marcafacil.txt", "r");
                break;
            case 2:
                archivo = fopen("tematicas/marcas/marcamedio.txt", "r");
                break;
            case 3:
                archivo = fopen("tematicas/marcas/marcahardcore.txt", "r");
                break;
            default:
                printf("Recuerde que 1 es fácil, 2 es medio, 3 es difícil.\n");
                break;
        }
        break;

    case 3:  // Caso de comidas
        switch (dificultad) {
            case 1:
                archivo = fopen("tematicas/objetos/objetosfacil.txt", "r");
                break;
            case 2:
                archivo = fopen("tematicas/objetos/objetosmedio.txt", "r");
                break;
            case 3:
                archivo = fopen("tematicas/objetos/objetoshardcore.txt", "r");
                break;
            default:
                printf("Recuerde que 1 es fácil, 2 es medio, 3 es difícil.\n");
                break;
        }
        break;

    default:
        printf("Recuerde que 1 es países, 2 es marcas, 3 es comidas, 4 es objetos.\n");
        break;
}


    if (archivo != NULL) {
        eleccionDificultad(archivo, palabras, palabraEnJuego);
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo. Verifique la temática y la dificultad.\n");
    }
    
    char caracteres[MAX_LONGITUD]; 
    int tamanio = strlen(palabraEnJuego)-1;
    
    for (int i = 0; i < tamanio; i++) {
        caracteres[i] = palabraEnJuego[i];
    }
    
    
    //caracteres [strlen(palabraEnJuego)] = '\0'; ver que hace esto bien
    //printf("%d",tamanio);
    
    printf("La palabra en juego es: %s\n", palabraEnJuego);
    printf("Los caracteres en el arreglo son:\n");

    printf("La palabra en juego es: %s\n", palabraEnJuego);
        for (int i = 0; i <= (tamanio-1); i++) {
        printf("Caracter %d: %c\n", i, caracteres[i]);
    }
    
    
    //Juego en si


    for (int i = 0; i <= tamanio; i++){
        printf("-");
    }
    
    
    
    
    return 0;
 
}

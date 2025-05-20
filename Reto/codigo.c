#include <stdio.h>
#include <string.h>

void menu()
{
    printf(" MENU ");
    printf("1. Abrir archivo\n");
    printf("2. Ver estadisticas\n");
    printf("3. Contar vocales\n");
    printf("4. Salir\n");
    printf("Opcion: ");
}

// Cargar archivo
int cargar(char texto[])
{
    char nombre[];
    printf("Nombre del archivo (ej: texto.txt): ");
    scanf("%s", nombre);

    FILE *archivo = fopen(nombre, "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

     int max = 10000;
    char *texto = (char*)malloc(max);
    if (texto == NULL)
    {
        printf("Error de memoria.\n");
        fclose(archivo);
        return NULL;
    }

    int i = 0;
    char c;
    while ((c = fgetc(archivo)) != EOF && i < max - 1)
    {
        texto[i++] = c;
    }
    texto[i] = '\0';
    
    
// Estadísticas
void estadisticas(char texto[])
{
    int letras = 0, palabras = 0, lineas = 1;

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (isalpha(texto[i])) letras++;
        if (texto[i] == ' ') palabras++;
        if (texto[i] == '\n') lineas++;
    }

    printf(" ESTADISTICAS");
    printf("Letras: %d\n", letras);
    printf("Palabras: %d\n", palabras + 1);
    printf("Lineas: %d\n", lineas);
}

void contar_vocales(char texto[]) {
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (int j = 0; texto[j] != '\0'; j++)
    {
        if (texto[j] == 'a' || texto[j] == 'A') a++;
        else if (texto[j] == 'e' || texto[j] == 'E') e++;
        else if (texto[j] == 'i' || texto[j] == 'I') i++;   //se cuentan las vocales tanto M como m
        else if (texto[j] == 'o' || texto[j] == 'O') o++;
        else if (texto[j] == 'u' || texto[j] == 'U') u++;
    }

    printf("VOCALES:");
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
}
int main() {
    char *texto = NULL;
    int opcion;

    do {
        menu();
        scanf("%d", &opcion);
        getchar(); // Limpiar el salto de línea que queda en el buffer

        switch (opcion) {
            case 1:
                if (texto != NULL) free(texto);
                texto = cargar();
                break;
                 case 2:
                if (texto != NULL) estadisticas(texto);
                else printf("Primero debes cargar un archivo.\n");
                break;
            case 3:
                if (texto != NULL) contar_vocales(texto);
                else printf("Primero debes cargar un archivo.\n");
                break;
            case 4:
                printf("Saliendo\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }

    } while (opcion != 4);

    if (texto != NULL) free(texto);
    return 0;
}
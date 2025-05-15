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
void estadisticas(char texto[]) {
    int letras = 0, palabras = 0, lineas = 1;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) letras++;
        if (texto[i] == ' ') palabras++;
        if (texto[i] == '\n') lineas++;
    }

    printf(" ESTADISTICAS");
    printf("Letras: %d\n", letras);
    printf("Palabras: %d\n", palabras + 1);
    printf("Lineas: %d\n", lineas);
}
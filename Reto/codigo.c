#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>:


void menu()
{
    printf("MENU");
    printf("1. Abrir archivo\n");
    printf("2. Ver estadisticas\n");
    printf("3. Contar las vocales\n");
    printf("4. Reemplazar las palabra\n");
    printf("5. Guardar en archivo\n");
    printf("6. Salir\n");
    printf("Opcion: ");
}

char* cargar()
{
    char nombre[100];
    printf("Nombre del archivo (ej: texto.txt): ");
    scanf("%s", nombre);

    FILE *archivo = fopen(nombre, "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
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
    fclose(archivo);

    return texto;
}

void estadisticas(char texto[])
{
    int letras = 0, palabras = 0, lineas = 1;
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if ((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z')) letras++;
        if (texto[i] == ' ') palabras++;
        if (texto[i] == '\n') lineas++;
    }

    printf("Estadisticas");
    printf("Letras: %d\n", letras);
    printf("Palabras: %d\n", palabras + 1);
    printf("Lineas: %d\n", lineas);
}

void contar_vocales(char texto[])
{
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (int j = 0; texto[j] != '\0'; j++)
    {
        char c = texto[j];
        if (c == 'a' || c == 'A') a++;
        else if (c == 'e' || c == 'E') e++;
        else if (c == 'i' || c == 'I') i++;
        else if (c == 'o' || c == 'O') o++;
        else if (c == 'u' || c == 'U') u++;
    }

    printf("VOCALES");
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
}

void reemplazar_palabra(char **texto)
{
    char buscar[100], reemplazo[100];
    printf("Palabra a buscar: ");
    scanf("%s", buscar);
    printf("Palabra para reemplazar: ");
    scanf("%s", reemplazo);

    char *nuevo = (char*)malloc(10000);
    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }
    nuevo[0] = '\0';

    char *pos = *texto;
    while (*pos)
    {
        if (strncmp(pos, buscar, strlen(buscar)) == 0 &&
            (pos[strlen(buscar)] == ' ' || pos[strlen(buscar)] == '\0' || pos[strlen(buscar)] == '\n')) {
            strcat(nuevo, reemplazo);
            pos += strlen(buscar);
        } 
        else
        {
            int len = strlen(nuevo);
            nuevo[len] = *pos;
            nuevo[len + 1] = '\0';
            pos++;
        }
    }

    free(*texto);
    *texto = nuevo;
}

void guardar_resultado(char texto[]) 
{
    char nombre[100];
    printf("Nombre del archivo de salida: ");
    scanf("%s", nombre);

    FILE *salida = fopen(nombre, "w");
    if (salida == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    int letras = 0, palabras = 0, lineas = 1, a = 0, e = 0, i = 0, o = 0, u = 0;

    for (int j = 0; texto[j] != '\0'; j++)
    {
        char c = texto[j];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) letras++;
        if (c == ' ') palabras++;
        if (c == '\n') lineas++;
        if (c == 'a' || c == 'A') a++;
        if (c == 'e' || c == 'E') e++;
        if (c == 'i' || c == 'I') i++;
        if (c == 'o' || c == 'O') o++;
        if (c == 'u' || c == 'U') u++;
    }

    fprintf(salida, "Letras: %d\n", letras);
    fprintf(salida, "Palabras: %d\n", palabras + 1);
    fprintf(salida, "Lineas: %d\n", lineas);
    fprintf(salida, "Vocales:\n");
    fprintf(salida, "a: %d\n", a);
    fprintf(salida, "e: %d\n", e);
    fprintf(salida, "i: %d\n", i);
    fprintf(salida, "o: %d\n", o);
    fprintf(salida, "u: %d\n", u);
    fprintf(salida, "Texto modificado:\n%s\n", texto);

    fclose(salida);
    printf("Archivo guardado exitosamente.\n");
}

int main()
{
    char *texto = NULL;
    int opcion;

    do 
    {
        menu();
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
            case 1:
                if (texto != NULL) free(texto);
                texto = cargar();
                if (texto == NULL)
                {
                    printf("Error al cargar el archivo.\n");
                }
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
                if (texto != NULL) reemplazar_palabra(&texto);
                else printf("Primero debes cargar un archivo.\n");
                break;
            case 5:
                if (texto != NULL) guardar_resultado(texto);
                else printf("Primero debes cargar un archivo.\n");
                break;
            case 6:
                printf("Saliendo\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } 
    while (opcion != 6);

    if (texto != NULL) free(texto);
    return 0;
}

//'w'
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char Nombre[30];
    int edad;
    FILE *p_archivo; 
    p_archivo = fopen ("texto.txt", "w");
    fprintf(stdout, "Ingrese su nombre: \n"); //Escribit el archivo en la "pantalla"
    fgets(Nombre, sizeof(Nombre),stdin);
    Nombre[sizeof(Nombre)-1] = '\0'; //Remplazo \n por \0
    fprintf(stdout, "cuantos años tienes ? \n");
    scanf("%d", &edad);
    if(p_archivo != NULL)
    {
    printf("se cea el archivo \n");
    //Escribir una cadena de caracteres
    fprintf(p_archivo, "Este texto de pruebapara el archivo texto.txt");
    //Escribir texto y variable
    fprintf(p_archivo, "Hola %s bienvenido al curso\n",Nombre);
}
    fclose(p_archivo);
    return 0;
}




//'a'
#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE  *pfile;
    int letra = '1'
    char caracter;
    pfile = fopen ("Texto2.txt", "a");
    if (pfile) //NULL es falso, cualquier valor diferente es verdader 
    {
        while (letra != '?')
        {
            caracter = fgetc(stdin);
            fputc(caracter, pfile);
        }
    }
    fclose(pfile);
    return 0;
}
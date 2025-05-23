# Sustentación reto unidad 4 
1. Explicación del análisis del problema

El objetivo del reto fue crear un programa en C en el cual el usuario pueda meter un archivo de texto y mostrar cosas básicas sobre el, como contar cuantas letras tiene cuantas palabras, cuantas líneas y cuantas vocales hay en el texto. El programa se divide en 3 partes el cual se ejecuta desde un menú principal, se empieza pidiendo al usuario que monte el archivo que quiere analizar y luego las opciones de: contar la cantidad de letras, la cantidad de palabras o la cantidad de líneas y otra opción para contar todas las vocales. Además de dos funciones que sirven para reemplazar una palabra por otra dentro del texto y otra que gurda el archivo.

2.Estrategia de solución.

Es un programa con un menú principal desde el cual el usuario puede elegir qué acción quiere realizar. La opción 1, se solicita el nombre del archivo y este se abre y se carga en memoria usando malloc. Las opciones 2 y 3 permiten analizar el contenido del archivo cargado: se cuentan letras, palabras, líneas y también cuántas veces aparece cada vocal, sin importar si está en mayúscula o minúscula. Además, una nueva opción que permite al usuario ingresar una palabra que desea buscar y reemplazarla por otra en el texto, modificando el contenido en la memoria. Además, de otra opción que permite guardar los resultados del análisis (estadísticas, repeticiones de vocales y texto nuevos o modificados) en un nuevo archivo. El menú se repite usando un ciclo do while hasta que el usuario quiera salir. Todo el programa se organiza con funciones para cada uno: una para mostrar el menú, una para cargar el archivo, otra para mostrar estadísticas, otra para contar vocales, una para hacer el reemplazo de palabras y una más para guardar los resultados.

3.Tabla de variables.

# Función: `cargar()`

| Función  | Variable  | Tipo       | Rol                                          |
|----------|-----------|------------|----------------------------------------------|
| `cargar` | `nombre`  | `char[]`   | Entrada - Nombre del archivo a leer          |
| `cargar` | `archivo` | `FILE*`    | Interno - Puntero al archivo abierto         |
| `cargar` | `texto`   | `char*`    | Salida - Contenido del archivo               |
| `cargar` | `c`       | `char`     | Interno - Carácter leído                     |  
| `cargar` | `i`       | `int`      | Interno - Índice para recorrer el texto      |
| `cargar` | `max`     | `int`      | Interno - Tamaño máximo reservado con malloc |

# Función: `estadisticas()`

| Función        | Variable   | Tipo     | Rol                                        |
|----------------|------------|----------|--------------------------------------------|
| `estadisticas` | `texto`    | `char[]` | Entrada - Texto a analizar                 |
| `estadisticas` | `letras`   | `int`    | Interno - Contador de letras               |
| `estadisticas` | `palabras` | `int`    | Interno - Contador de palabras             |
| `estadisticas` | `lineas`   | `int`    | Interno - Contador de líneas               |
| `estadisticas` | `i`        | `int`    | Interno - Índice para recorrer el texto    |

# Función: `contar_vocales()`

| Función          | Variable | Tipo     | Rol                                             |
|------------------|----------|----------|-------------------------------------------------|
| `contar_vocales` | `texto`  | `char[]` | Entrada - Texto sobre el que se cuentan vocales |
| `contar_vocales` | `a`      | `int`    | Interno - Contador de la vocal 'a'              |
| `contar_vocales` | `e`      | `int`    | Interno - Contador de la vocal 'e'              |
| `contar_vocales` | `i`      | `int`    | Interno - Contador de la vocal 'i'              |
| `contar_vocales` | `o`      | `int`    | Interno - Contador de la vocal 'o'              |
| `contar_vocales` | `u`      | `int`    | Interno - Contador de la vocal 'u'              |
| `contar_vocales` | `j`      | `int`    | Interno - Índice para recorrer el texto         |

# reemplazar_palabra

| Función              | Variable  | Tipo     | Rol                                   |
|----------------------|-----------|----------|---------------------------------------|
| `reemplazar_palabra` | texto     | char[]   | Entrada/Salida - Texto                |
| `reemplazar_palabra` | palabra   | char[]   | Entrada - Palabra a buscar            |
| `reemplazar_palabra` | nueva     | char[]   | Entrada - Palabra nueva               |
| `reemplazar_palabra` | nuevo     | char*    | Interna - Texto modificado            |
| `reemplazar_palabra` | ptr       | char*    | Interna - Posición de coincidencia    |
| `reemplazar_palabra` | inicio    | int      | Interna - Índice en el texto          |

4.Diagramas, esquemas o pseudocódigo.

Inicio

    Definir variables: texto, opcion, palabra, nueva_palabra, nombre_archivo

        Mostrar menú:
            1. Cargar archivo
            2. Ver estadísticas
            3. Contar vocales
            4. Reemplazar palabra
            5. Guardar resultados
            6. Salir

        Leer opción del usuario

        Segun la opción que el usuario meta:
            Caso 1:
                Pedir el nombre del archivo
                Abrir archivo
                Leer contenido y guardarlo en texto
            Caso 2:
                Si texto existe:
                    Contar letras, palabras y líneas
                    Mostrar resultados
                Sino:
                    Mostrar mensaje de error
            Caso 3:
                Si texto existe:
                    Contar cuántas veces aparece cada vocal
                    Mostrar resultados
                Sino:
                    Mostrar mensaje de error
            Caso 4:
                Si texto existe:
                    Pedir palabra a buscar y palabra nueva
                    Cambiar esa palabra por la nueva en todo el texto
                Sino:
                    Mostrar mensaje de error
            Caso 5:
                Si texto existe:
                    Pedir nombre del archivo nuevo
                    Guardar estadísticas, vocales y texto modificado
                Sino:
                    Mostrar mensaje de error
            Caso 6:
                Mostrar mensaje de salida

    Hasta que opción sea 6

    Liberar memoria usada

Fin
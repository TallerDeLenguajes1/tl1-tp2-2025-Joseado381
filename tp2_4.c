#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct compu
{
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu;
};

// funciones
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);


int main(){
  srand(time(NULL));
  char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};
  struct compu pcs[5];

  // generamos los datos aleatoriamente
  for (int i = 0; i < 5; i++)
  {
    pcs[i].velocidad = rand()% 3 + 1;
    pcs[i].anio = rand()% 10 + 2015;
    pcs[i].cantidad_nucleos = rand() % 8 + 1;
    pcs[i].tipo_cpu= tipos[rand() % 6];
  }
  printf("\nLISTA DE PCs\n");
  listarPCs(pcs,5);
  printf("\nPC MAS VIEJA \n");
  mostrarMasVieja(pcs,5);
  printf("\nPC MAS RAPIDA \n");
  mostrarMasVeloz(pcs,5);

  return 0;
}

void listarPCs(struct compu pcs[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("PC #%d:\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Año: %d\n", pcs[i].anio);
        printf("  Núcleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n", pcs[i].tipo_cpu);
        printf("-----------------------\n");
    }
}
void mostrarMasVieja(struct compu pcs[], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[indice].anio) {
            indice = i;
        }
    }

    printf("  Velocidad: %d GHz\n", pcs[indice].velocidad);
    printf("  Año: %d\n", pcs[indice].anio);
    printf("  Núcleos: %d\n", pcs[indice].cantidad_nucleos);
    printf("  Tipo CPU: %s\n", pcs[indice].tipo_cpu);
}

// FUNCION PARA PC MAS RAPIDA
void mostrarMasVeloz(struct compu pcs[], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > pcs[indice].velocidad) {
            indice = i;
        }
    }

    printf("  Velocidad: %d GHz\n", pcs[indice].velocidad);
    printf("  Año: %d\n", pcs[indice].anio);
    printf("  Núcleos: %d\n", pcs[indice].cantidad_nucleos);
    printf("  Tipo CPU: %s\n", pcs[indice].tipo_cpu);
}
/*
4) Desarrollar una aplicación en C que permita gestionar información sobre computadoras (PC) utilizando estructuras y funciones. 
La aplicación deberá generar datos aleatorios para un conjunto de PCs y luego implementar funciones para mostrar la información y encontrar características específicas.
 a. Definición de la Estructura de Datos Deberás declarar un tipo de dato struct para representar una PC.
  La estructura se llamará compu y contendrá los siguientes campos: 
 b. Generación de Datos Aleatorios 
  La aplicación no requerirá ingreso de datos por teclado. 
  En su lugar, generará aleatoriamente las características para 5 PCs.
   ● Valores Numéricos Aleatorios: 
      ○ Velocidad: Generar un valor entero aleatorio entre 1 y 3 (inclusive).
      ○ Año: Generar un valor entero aleatorio entre 2015 y 2024 (inclusive). 
      ○ Cantidad de Núcleos: Generar un valor entero aleatorio entre 1 y 8 (inclusive). 
   ● Tipos de Procesador: 
      ○ Utiliza el siguiente arreglo predefinido de cadenas de caracteres para los tipos de CPU: 
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; 
      ○ Para cada PC generada, el campo tipo_cpu de la estructura deberá apuntar a una cadena seleccionada aleatoriamente de este arreglo tipos. 
 c. Almacenamiento de Datos 
   ● Define una variable que sea un arreglo de 5 elementos del tipo struct compu. 
    Este arreglo almacenará las características de las 5 PCs generadas. 
 d. Funciones a Implementar Deberás escribir e implementar las siguientes funciones: 
 ● void listarPCs(struct compu pcs[], int cantidad): 
  ○ Recibe el arreglo de PCs y la cantidad de elementos. 
  ○ Muestra por pantalla la lista completa de las PCs, presentando todas las características de cada una de forma clara. 
 ● void mostrarMasVieja(struct compu pcs[], int cantidad): 
  ○ Recibe el arreglo de PCs y la cantidad de elementos. 
  ○ Busca la PC con el menor año de fabricación (la más vieja). 
  ○ Muestra por pantalla las características de la PC más vieja encontrada. Si hay varias con el mismo año más antiguo, puedes mostrar la primera que encuentres. 
 ● void mostrarMasVeloz(struct compu pcs[], int cantidad): 
  ○ Recibe el arreglo de PCs y la cantidad de elementos. 
  ○ Busca la PC con la mayor velocidad de procesamiento. 
  ○ Muestra por pantalla las características de la PC más rápida encontrada. Si hay varias con la misma velocidad máxima, puedes mostrar la primera que encuentres. 
    El código fuente completo de la aplicación debe guardarse en un archivo llamado tp2_4.c. 
    No se olvide de ir haciendo commit a medida que vaya avanzando.
     Por ej. cada vez que defina una función. Página 7 
*/
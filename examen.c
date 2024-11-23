#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Variables para manejar la entrada de los números
    int numeros[2];

    // Bucle para repetir las operaciones hasta que el usuario decida salir
    do
    {
        // 1. Validar rango.
        numeros[0] = get_int("Ingrese el primer numero: ");
        numeros[1] = get_int("Ingrese el segundo numero: ");

        // Asegurarse de que el primer número sea menor o igual al segundo
        while (numeros[0] > numeros[1])
        {
            printf("El primer número debe ser menor o igual al segundo. Intenta de nuevo.\n");

            numeros[0] = get_int("Ingrese el primer numero: ");
            numeros[1] = get_int("Ingrese el segundo numero: ");
        }

        printf("Los números son válidos.\n");

        // Menú de opciones
        printf("1. Mostrar todos los numeros pares en el rango y calcular la suma \n");
        printf("2. Mostrar todos los numeros impares en el rango y calcular la suma\n");
        printf("3. Mostrar tanto los numeros pares como los impares en el rango y calcular la suma\n");
        printf("4. Salir\n");

        // Leer la opción seleccionada
        int op = get_int("Ingrese una opcion: ");

        // Variables para la suma
        int suma_pares = 0;
        int suma_impares = 0;

        // Bucle para recorrer el rango de números
        for (int i = numeros[0]; i <= numeros[1]; i++)
        {
            if (i % 2 == 0) // Número par
            {
                suma_pares += i;
                if (op == 1 || op == 3) // Opción 1 o 3
                {
                    printf("%d es par\n", i);
                }
            }
            else // Número impar
            {
                suma_impares += i;
                if (op == 2 || op == 3) // Opción 2 o 3
                {
                    printf("%d es impar\n", i);
                }
            }
        }

        // Mostrar la suma según la opción seleccionada
        if (op == 1)
        {
            printf("La suma de los números pares es: %d\n", suma_pares);
        }
        else if (op == 2)
        {
            printf("La suma de los números impares es: %d\n", suma_impares);
        }
        else if (op == 3)
        {
            printf("La suma de los números pares es: %d\n", suma_pares);
            printf("La suma de los números impares es: %d\n", suma_impares);
        }
        else if (op == 4)
        {
            printf("Saliendo del programa.\n");
        }
        else
        {
            printf("Opción no válida.\n");
        }

        // Preguntar al usuario si desea realizar otra operación
        char respuesta = get_char("¿Deseas realizar otra operación? (s/n): ");
        if (respuesta == 'n' || respuesta == 'N')
        {
            break; // Salir del ciclo si el usuario ingresa 'n' o 'N'
        }

    } while (true); 

    return 0;
}

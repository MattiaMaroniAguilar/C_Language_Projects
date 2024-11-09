/******************************************************************************
Crear un programa para calcular las áreas y perímetros de algunas figuras geométricas
Los datos para el cálculo de las áreas y los perímetros (datos de entrada) 
se pedirán al usuario antes de entrar al menú principal
Se programará un menú principal que contenga las siguientes opciones:
1. Áreas
2. Perímetros
3. Salir
*******************************************************************************/
#include <stdio.h>
#include <math.h>

#define PI 3.14159
// Funcion Area con 3 casos de figuras
// Dependiendo del valor en figura se regresa una opcion con switch
float calcularArea(int figura, float lado, float baseMayor, float baseMenor, float altura, float radio) {
    switch (figura) {
        case 1: // Cuadrado
            return lado * lado;
        case 2: // Trapecio
            return 0.5 * (baseMayor + baseMenor) * altura;
        case 3: // Esfera
            return 4 * PI * radio * radio;
        default:
            printf("Figura no válida para el cálculo de área.\n");
            return 0;
    }
}
// Funcion PERIMETRO con 3 casos de figuras
// Dependiendo del valor en figura se regresa una opcion con switch
// Definimos el tipo de dato de la funcion y el tipo de dato y la lista dividida con comas de los parametros a ingresar.
float calcularPerimetro(int figura, float lado, float baseMayor, float baseMenor, float altura, float radio) {
    switch (figura) {
        case 1: // Rectángulo
            return 2 * (lado + altura);
        case 2: // Triángulo equilátero (asumiendo lados iguales)
            return 3 * lado;
        case 3: // Círculo
            return 2 * PI * radio;
        default:
            printf("Figura no válida para el cálculo de perímetro.\n"); //  Si no se cumple 1-2-3 entonces default
            return 0;
    }
}
// Se inicia el programa principal en main()
int main() {
    // Definimos las variables y su tipo de datos a en el main.
    int opcion_menuP, figura_Area, figura_Perimetro;
    float lado, baseMayor, baseMenor, altura, radio;

    // Pedimos al usuario los datos necesarios antes del menu almacenados en variables con su tipo de dato correspondiente
    printf("Ingrese los siguientes datos:\n");
    printf("Lado: ");
    scanf("%f", &lado);
    printf("Base mayor: ");
    scanf("%f", &baseMayor);
    printf("Base menor: ");
    scanf("%f", &baseMenor);
    printf("Altura: ");
    scanf("%f", &altura);
    printf("Radio: ");
    scanf("%f", &radio);

    // Menú principal para obtener la decision del usuario almanacenada en opcion_menuP
    printf("\n -- Menú Principal --\n");
    printf("Selecciona el número según la opción de cálculo:\n");
    printf("1. Áreas\n");
    printf("2. Perímetros\n");
    scanf("%d", &opcion_menuP);
    
    // Dependiendo de la opcion ingresada 1 o 2 se entra en el submenu area o perimetro para preguntar la figura que quiere calcular el usuario
    switch (opcion_menuP) {
        case 1:
            // Submenú de área
            printf("\n -- Submenú de Área -- \n");
            printf("\n Selecciona una figura:\n");
            printf("\n 1. Cuadrado\n");
            printf("\n 2. Trapecio\n");
            printf("\n 3. Esfera\n");
            scanf("%d", &figura_Area);
            
            // Dependiendo del valor ingresado en el submenu, se entra en un condicional para aplicar la funcion AREA con sus parametros de calculo
            // Estructura de control condicional donde el valor del submenu ingresado es de 1 a 3, de lo contrario no es opcion valida y termina.
            if (figura_Area >= 1 && figura_Area <= 3) {
                float area = calcularArea(figura_Area, lado, baseMayor, baseMenor, altura, radio);
                printf("El área es: %.2f\n", area);
            } else {
                printf("Opción no válida.\n");
            }
            break;

        case 2:
            // Submenú de perímetro
            printf("\n -- Submenú de Perímetro -- \n");
            printf("\n Selecciona una figura:\n");
            printf("\n 1. Rectángulo\n");
            printf("\n 2. Triángulo equilátero\n");
            printf("\n 3. Círculo\n");
            scanf("%d", &figura_Perimetro);

            if (figura_Perimetro >= 1 && figura_Perimetro <= 3) {
                float perimetro = calcularPerimetro(figura_Perimetro, lado, baseMayor, baseMenor, altura, radio);
                printf("El perímetro es: %.2f\n", perimetro);
            } else {
                printf("Opción no válida.\n");
            }
            break;

        default:
            printf("Opción de menú no válida.\n");
    }

    return 0;
}
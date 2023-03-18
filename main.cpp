#include <iostream>
#include <ctime>
#include <locale>
#include <windows.h>
#include <cmath>

using namespace std;

void menu(int arr[], int);

void limpiarConsola();
void imprimirArregloFor(int arr[], int);
void imprimirArregloWhile(int arr[], int);
int numeroMitad(int arr[], int);
void numeroPares(int arr[], int);
bool esPrimo(int);
void numeroPrimos(int arr[], int);
int numeroMayorArreglo(int arr[], int);
void ordenarArregloMenorMayor(int arr[], int);

int main(){
    setlocale(LC_ALL, "spanish");

    char opcion;
    int tamanoArr = 0;

    do{
        cout << "\n  Ingrese el tamaño del arreglo: ";
        cin >> tamanoArr;

        int arr[tamanoArr];

        cout << "\n  1. Llenado automático.\n  2. Llenado manual." << endl;
        cout << "\n  Seleccione una opción: ";
        cin >> opcion;

        switch(opcion){
            case '1':
                srand(time(NULL));
                for(int i = 0; i < tamanoArr; i++)
                    arr[i] = rand() % 101 + 100;
                limpiarConsola();
                menu(arr, tamanoArr);
                break;
            case '2':
                cout << endl;
                for(int i = 0; i < tamanoArr; i++){
                    int valor;
                    do{
                        cout << "  Número " << i + 1 << ": ";
                        cin >> valor;
                        if(valor < 0 || valor > 99)
                            cout << "\n  El número debe estar entre 0 y 99. Inténtelo de nuevo.\n" << endl;
                    }while(valor < 0 || valor > 99);
                    arr[i] = valor;
                }
                limpiarConsola();
                menu(arr, tamanoArr);
                break;
            default:
                cout << "\n  Opción invalida. Inténtelo de nuevo." << endl;
                limpiarConsola();
                break;
        }
    }while(opcion != '2');

    return 0;
}

void menu(int arr[], int tamanoArr){
    char opcion;
    int valorMedio = 0;
    int numeroMayor = 0;

    do{
        cout << "\n\t\t***MENÚ***" << endl;
        cout << "\n  1. Imprimir arreglo con ciclo for.\n  2. Imprimir arreglo con ciclo while.\n  3. Número contenido en la posición media." <<
        "\n  4. Números pares del arreglo.\n  5. Números primos del arreglo.\n  6. Número mayor del arreglo.\n  7. Ordenar arreglo de menor a mayor." <<
        "\n  8. Redefinir arreglo." << endl;
        cout << "\n  Seleccione una opción: ";
        cin >> opcion;

        switch(opcion){
            case '1':
                imprimirArregloFor(arr, tamanoArr);
                cout << "\n  ";
                system("pause");
                limpiarConsola();
                break;
            case '2':
                imprimirArregloWhile(arr, tamanoArr);
                cout << "\n  ";
                system("pause");
                limpiarConsola();
                break;
            case '3':
                valorMedio = numeroMitad(arr, tamanoArr);
                cout << "\n  Número de la posición media: " << valorMedio << endl;
                cout << "\n  ";
                system("pause");
                limpiarConsola();
                break;
            case '4':
                numeroPares(arr, tamanoArr);
                cout << "\n  ";
                system("pause");
                limpiarConsola();
                break;
            case '5':
                numeroPrimos(arr, tamanoArr);
                cout << "\n  ";
                system("pause");
                limpiarConsola();
                break;
            case '6':
                numeroMayor = numeroMayorArreglo(arr, tamanoArr);
                cout << "\n  Número mayor del arreglo: " << numeroMayor << endl;
                cout << "\n  ";
                system("pause");
                limpiarConsola();
                break;
            case '7':
                ordenarArregloMenorMayor(arr, tamanoArr);
                cout << "\n  ";
                system("pause");
                limpiarConsola();
                break;
            case '8':
                limpiarConsola();
                break;
            default:
                cout << "\n  Opción invalida. Inténtelo de nuevo." << endl;
                limpiarConsola();
                break;
            }
        }while(opcion != '8');
}

void limpiarConsola(){
    Sleep(1500);
    system("cls");
}

void imprimirArregloFor(int arr[], int tamanoArr){
    cout << "\n  Arreglo: [";
    for(int i = 0; i < tamanoArr; i++){
        cout << arr[i];
        if(i != tamanoArr - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void imprimirArregloWhile(int arr[], int tamanoArr){
    int i = 0;

    cout << "\n  Arreglo: [";
    while(i < tamanoArr){
        cout << arr[i];
        if(i != tamanoArr - 1)
            cout << ", ";
        i++;
    }
    cout << "]" << endl;
}

int numeroMitad(int arr[], int tamanoArr){
    return arr[tamanoArr / 2];
}

void numeroPares(int arr[], int tamanoArr){
    cout << "\n  Números pares: ";
    for(int i = 0; i < tamanoArr; i++){
        if(arr[i] % 2 == 0)
            cout << arr[i] << "  ";
    }
    cout << endl;
}

void numeroPrimos(int arr[], int tamanoArr){
    cout << "\n  Números primos: ";
    for(int i = 0; i < tamanoArr; i++){
        if(esPrimo(arr[i]))
            cout << arr[i] << "  ";
    }
    cout << endl;
}

bool esPrimo(int n){
    if (n <= 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int numeroMayorArreglo(int arr[], int tamanoArr){
    int temp = 0;
    int mayor = 0;

    for(int i = 0; i < tamanoArr; i++){
        temp = arr[i];
        if(temp > mayor){
            mayor = temp;
        }
    }

    return mayor;
}

void ordenarArregloMenorMayor(int arr[], int tamanoArr){
    for (int i = 0; i < tamanoArr - 1; i++) {
        for (int j = 0; j < tamanoArr - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\n  El arreglo ordenado es: ";
    for (int i = 0; i < tamanoArr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#include <iostream>
#include <vector>

using namespace std;

// Función para combinar dos subarreglos ordenados en uno solo ordenado
void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño del primer subarreglo
    int n2 = right - mid;    // Tamaño del segundo subarreglo

    // Crear dos subarreglos temporales para almacenar los valores
    vector<double> L(n1);
    vector<double> R(n2);

    // Copiar datos a los subarreglos temporales L y R
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0; // Índice para recorrer el subarreglo L
    int j = 0; // Índice para recorrer el subarreglo R
    int k = left; // Índice para recorrer el arreglo original

    // Combinar los subarreglos L y R en el arreglo original de manera ordenada
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L, si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R, si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calcular el punto medio

        // Llamadas recursivas para ordenar los subarreglos izquierdo y derecho
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combinar los subarreglos ordenados en uno solo
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cin >> N; // Leer la cantidad de valores

    vector<double> values(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i]; // Leer los valores
    }

    mergeSort(values, 0, N - 1); // Llamar a la función de Merge Sort

    // Imprimir los valores ordenados
    for (int i = 0; i < N; i++) {
        cout << values[i] << endl;
    }

    return 0;
}

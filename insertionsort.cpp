/*
Insertionsort: funciona de la siguiente manera 
se  tiene una lista de elementos desordenados en un arreglo:
    12, 11, 13, 5, 7, 1
Lo que se hace en este elementoes que toma los primeros dos elementos y los compara 
si el valor del elemento de la derecha es mayor que el de la izquierda se cambia por el anterior
se van acumulando los valores en una minilisra, lo que le da un tiempo de ejecucion de O(n~2) 
Ejemplo:
    12
No tiene elementos a su izquierda (arr[j]) por lo que no hace nada, por lo que pasa al siguiente elemento
    12, 11
    -------
    11, 12
Se pasa al siguiente elemento y se agrega un segundo elemento al miniarreglo 
Se compara el elemento en el que se esta, arr[i], con el valor de el elemento anterior arr[j]
Va retrocediendo 
    11, 12, 13
Se pasa al siguiente agregando el tercer elmento al miniarreglo
Se compara el elemento en el que se esta, y no se cambia debido a que ya cumple con la condicion
por lo que ya esta ordenado
Va retricendiendo
*/

#include <iostream>

void insertionsort(int arr[], int n){
    for(int i = 1; i < n; i++){//primer ciclo que recorre todos los elementos del arreglo
        int value = arr[i];//valores dentro del arreglo en la funcion
        int j = i - 1;// se crea la variable j que es igual al indice el el que se esta menos uno, ej: i=1, j = 1-1, i=2, j = 2-1
        while (j >= 0 && arr[j] > value){// se entra al segundo bucle del arreglo que consta de los elementos que se encuentran a la izquierda del elemento en el que se esta trabjando 
            arr[j+1] = arr[j];// el valor en la posicion 1 de j es el elemento en 1
            j = j - 1;
        }
        arr[j+1] = value;
    } 
}

void printarray(int n, int arr[]){
    for(int i = 0; i < n ; i++ ){
        std::cout<<""<<arr[i]<<"\n";
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout<<"Arreglo no ordenado: \n";
    printarray(n, arr);
    insertionsort(arr, n);
    std::cout<<"Arreglo ordenado: \n";
    printarray(n, arr);
    return 0;
}
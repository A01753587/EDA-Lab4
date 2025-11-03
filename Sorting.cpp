/*

Bubblesort:

Es una forma de ordenamiento donde en la lista se tienen elementos desordenados, se comparan dos elementos de un arreglo de izquierda a derecha
la comparacion es ver si el numero actual es mayor al numero siguiente, por lo que va recorriendo los elementos de mayor a menor 

proceso de creacion de un algoritmo de bubblesort: 
se declara la funcion en las que se escribe el codigo
si crea ujn arreglo de enteros en este caso se llama arr
se inicia con un loop que va desde el indice cero hasta uno menos del total de la capacidad del array
Se crea unciclo for nuevamente, dentro de este se hara el recorrido de los elementos desde el numero 0 hasta el numero de elementos menos 1(j<Nelementos-i-1
pasamos al condicional if, donde se crea una comparacion de eel cual se determinan si el elemento siguiente al del indice j es mayor o es menor, si eeste es menor 
si es menor se crea una variable que almacena el valor en el indice j,
se mueve el valor del indice j a la derecha, estableciendolo como a[j]=a[j+1]
se iguala el elemento en el siguiente elemento 
*/



#include <iostream>
#include "Sorting.h"

// Complexity: O(n^2)
Sorting::Sorting(){};
Sorting::~Sorting(){};
// Bubblesort
void Sorting::bubblesort(std::vector<int>& vect){
    int n = vect.size();
    for (int i = 0; i < n-1; i++){
        for(int j = 0; j < n -i -1 ; j++){
            if(vect[j] > vect[j+1]){
                std::swap(vect[j],vect[j+1]);
            }
        }
    }
}

// Selection sort
void Sorting::selectionsort(std::vector<int>& vect){
    for (int i=0; i<vect.size()-1; i++){ 
        int min_index = i; 
        for (int j= i+1; j<vect.size(); j++){
            if (vect.at(j)<vect.at(min_index)){
                min_index = j;
            } 
        }
        std::swap(vect.at(i), vect.at(min_index));
    }
}

// Insertion sort
void Sorting::insertionsort(std::vector<int> &vect){
    int n=vect.size();
    for(int i = 1; i < n; i++){//primer ciclo que recorre todos los elementos del arreglo
        int value = vect[i];//valores dentro del arreglo en la funcion
        int j = i - 1;// se crea la variable j que es igual al indice el el que se esta menos uno, ej: i=1, j = 1-1, i=2, j = 2-1
        while (j >= 0 && vect[j] > value){// se entra al segundo bucle del arreglo que consta de los elementos que se encuentran a la izquierda del elemento en el que se esta trabjando 
            std::swap(vect[j],vect[j+1]);//el valor en la posicion 1 de j es el elemento en 1
            j = j - 1;
        }
    } 
}

// Complexity: O(n Log n)

// Heapsort
void Sorting::heapsort(std::vector<int> &vect){
    for (int i = 0 ; i < vect.size() ; i++){
        int index = i;
        while(index != 0 ){
            int parent = (index)/2;
            if(vect[index] >= vect[parent]) break;
            std::swap(vect[index],vect[parent]);
            index = parent;
        }
    }
}

// Quicksort
void Sorting::quicksort(std::vector<int> &vect){
    
}

// Mergesort




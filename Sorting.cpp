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

void merge(std::vector<int>& vect, int start, int mid, int end){
    //divide de size vector into 2 integers
    int size1 = mid - start + 1;
    int size2 = end - mid;

    //create two vectors that togheter will have the same size of the original one 
    std::vector<int> v1(size1);

    std::vector<int> v2(size2);
    
    //fill the two vectors with the original values
    int cntr = 0;
    int idx1 = 0;
    int idx2 = 0;
    while(cntr != size1+size2){
        if(cntr < size1){
            v1[idx1] = vect[start + idx1];
            cntr++;
            idx1++;
        }else{
            v2[idx2] = vect[start+idx1+idx2];
            cntr++;
            idx2++;
        }
    }
    cntr = start;
    idx1 = 0;
    idx2 = 0;
    //sort the two vectors in the original one
    int i = 0, j = 0, k = start;

    while (i < size1 || j < size2) {
        if (i < size1 && (j >= size2 || v1[i] <= v2[j])) {
            vect[k++] = v1[i++];
        } else {
            vect[k++] = v2[j++];
        }
    }
}

void Sorting::mergesort(std::vector<int>& vect, int start, int end){
    //Check the base case where the vector has only one element
    if(start >= end){
        return;
    }
    //Find the index of the element on the mid 
    int mid = start + (end - start) / 2;
    //Recursively find the mid of the sub-vectors
    mergesort(vect, start, mid);
    mergesort(vect, mid+1, end);
    //After having all the index of our sub-vectors we merge them whit a helper funcition
    merge(vect, start, mid, end);   
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
void Sorting::quicksort(std::vector<int> &vect, int start, int end){
    if(start>=end) return;
    int pivot = vect[end];
    int sorted = start-1;
    for(int i=start; i<end;i++){
        if(vect[i]<pivot){
            sorted++;
            std::swap(vect[sorted],vect[i]);
        }
    }
    std::swap(vect[sorted + 1], vect[end]);
    quicksort(vect,start,sorted-1);
    quicksort(vect,sorted+1,end);
}

// Mergesort

// Countingsort
void Sorting::countingsort(std::vector<int>& vect, int max_value){
    std::vector<int> count(max_value,0);
    for(int i=0;i<vect.size();i++){
        count[vect[i]]++;
    }
    vect.clear();
    for(int j=0;j<max_value;j++){
        while (count[j]!=0){
        vect.push_back(j);
        count[j]--;
        }
    }
}




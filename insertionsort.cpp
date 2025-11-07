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

void insertionsort(std::vector<int> &vect){
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

void print_vector(std::vector<int> &vect){
    int n=vect.size();
    for(int i = 0; i < n ; i++ ){
        std::cout<<""<<vect[i]<<"\n";
    }
}

void fill_random(std::vector<int>& values, int max_value){
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}


int main(){
    // std::vector<int> vect = {12, 11, 13, 5, 7, 1};
    // std::cout<<"Arreglo no ordenado: \n";
    // printarray(vect);
    // insertionsort(vect);
    // std::cout<<"Arreglo ordenado: \n";
    // printarray(vect);
    // return 0;


    std::vector<int> b(100);
    fill_random(b, 1000);
    print_vector(b);
    auto start = std::chrono::high_resolution_clock::now();
    selection_sort(b);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout<<"El tiempo total de ejecucion es de: "<<total_time<<" segundos\n";
    print_vector(b); 
    if (std::is_sorted(b.begin(), b.end())) {
        std::cout << "The vector is sorted." << std::endl;
    } else {
        std::cout << "The vector is not sorted." << std::endl;
    }
    


}
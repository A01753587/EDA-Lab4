//Ordenamiento por seleccion 8 oct  25
/*
Se selecciona el elemento con el valor mas bajo

Se tiene una seria de numeros en un erreglo y se busca ordenarlos
Ordenamiento por seleccion busca el numero mas pequeño de los elementos, caomparando cada elemento y descatando, seleccionando el meas pequeño

los elementos se van registrando conforme se encuentran valores mas pequeños y se guarda el indice del valos maspequeño del arreglo

Este vslor se intercambia (swap) por el elemento mas pqeueño, una vez hecho el cambio s vuelve a realizar el proceso

7-5-3-8-2-4 min_index = 4

2-5-3-8-7-4 min_index = 

2-3-5-8-7-4

2-3-4-8-7-5

2-3-4-5-7-8 una vez llegado en este punto se realiza un swap a la misma posicion del 7 ya que esra en el mismo  lugar

cuando se termina de procesar el elemento mas grande se hace  size - 2 que nos indica el lugar donde se encontro el valor donde ya no se necesita ordenar

La funcion sort nos permite indicarle la manera de ordenar los elementos de una lsita

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CODIGO: 
// en el caso de poner 1<= vec.size()
//es la primera posicion porque i se declara desde cero para ir desde el primer elemento del arrreglo
*/

#include <iostream>
#include<utility>
#include<vector>

template<typename T>
void print_vector(const std::vector<T>& vec){
    for(T elem: vec){ //trabaja como los elementos especificos del vector
        std::cout<<elem<<" ";
    }
    std::cout<<"\n";
}

//Complexity O(n«2)
void selection_sort(std::vector<int>& vec){
    for (int i=0; i<vec.size()-1; i++){ 
        //find smallest value in vector "vec" starting at i
        int min_index = i; 
        for (int j= i+1; j<vec.size(); j++){
            if (vec.at(j)<vec.at(min_index)){
                min_index = j;
            } 
        }
        std::swap(vec.at(i), vec.at(min_index));
    }
}

void fill_random(std::vector<int>& values, int max_value)
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}


int main(){
    std::vector<int> a {7, 5, 3, 8, 4, 2};
    print_vector(a);
    selection_sort(a);
    print_vector(a);

    std::vector<int> b(10000);
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
    
}
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
#include <vector>


void bubblesort(std::vector<int> &vect){
    int n = vect.size();
    for (int i = 0; i < n-1; i++){
        for(int j = 0; j < n -i -1 ; j++){
            if(vect[j] > vect[j+1]){
                std::swap(vect[j],vect[j+1]);
            }
        }
    }
}

std::ostream& operator<<(std::ostream& out,const std::vector<int>& vect){
    out<<"[";
    bool first_time {true};
    for(int n: vect){
        if(first_time){
            out<<n;
            first_time=false;
        }else{
            out<<","<<n;
        }   
    }
    out<<"]";
    return out;
}

// void printvector(int arr[], int n){
//     for(int i = 0; i < n; i++){
//         std::cout<<arr[i]<<"\n";
//     }
// }

int main(){
    std::vector<int> data {10,5,44,7,89,6,5,3,2,1};
    std::cout<<"Elementos del arreglo desordenados: \n";
    std::cout<<data<<"\n";
    std::cout<<"Elementos del arreglo ordenados: \n";
    bubblesort(data);
    std::cout<<data<<"\n";
}
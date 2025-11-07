#include "Sorting.h"
#include <chrono>

// Print function
std::ostream& operator<<(std::ostream& out, std::vector<int> &vect){
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

int main(){

    Sorting s;
    int n{0}, opc;
    std::vector<int> data(n);
    s.fill_random(data,n);
    // auto maxRes=std::max_element(data.begin(),data.end());
    // int max=*maxRes;
    // s.countingsort(data,max);

    do{
        std::cout<<"\n1. Selectionsort\n2. Insertionsort\n3. Bubblesort\n4. Quicksort\n5. Mergesort\n6. Countingsort\n7. Funcion sorting de la libería estándar\n\n\t";
        switch (opc)
        {
        case 1:
            
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
    
        }
    }while (opc!=8);
    


    return 0;
}
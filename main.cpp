#include "Sorting.h"
#include <chrono>
#include<algorithm>

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
void fill_vector(){
    int opcInit,n, max_value{999}; 
    Sorting fill_vect;
    std::cout<<"\nSize of vector: ";
    std::cin>>n;
    data.resize(n);
    std::cout<<"\n1. Random\n2. Incremental\n 3. Decremental\n\t";
    std::cin>>opcInit;
    switch (opcInit)
    {
    case 1:
        fill_vect.fill_random(data,max_value);
        break;

    case 2:
        fill_vect.fill_incremental(data,max_value);
        break;

    case 3:
        fill_vect.fill_decremental(data,max_value);
        break;
    
    }
}

std::vector<int> data;

int main(){

    Sorting sort;
    int opc;

    do{
        std::cout<<"\n1. Selectionsort\n2. Insertionsort\n3. Bubblesort\n4. Quicksort\n5. Mergesort\n6. Countingsort\n7. Funcion sorting de la libería estándar\n\n\t";
        std::cin>>opc;
        switch (opc)
        {
        case 1:
            fill_vector();
            auto start_selection = std::chrono::high_resolution_clock::now();
            sort.selectionsort(data);
            auto stop_selection = std::chrono::high_resolution_clock::now();
            auto duration_selection = std::chrono::duration_cast<std::chrono::microseconds>(stop_selection - start_selection);
            double total_time_selection = duration_selection.count() / 1'000'000.0;
            break;
        case 2:
            fill_vector();
            auto start = std::chrono::high_resolution_clock::now();
            sort.insertionsort(data);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            double total_time = duration.count() / 1'000'000.0;
            break;
        case 3:
            fill_vector();
            auto start = std::chrono::high_resolution_clock::now();
            sort.bubblesort(data);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            double total_time = duration.count() / 1'000'000.0;
            break;
        case 4:
            fill_vector();
            auto start = std::chrono::high_resolution_clock::now();
            sort.quicksort(data,0,data.size());
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            double total_time = duration.count() / 1'000'000.0;
            break;
        case 5:
            fill_vector();
            auto start = std::chrono::high_resolution_clock::now();
            sort.mergesort(data);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            double total_time = duration.count() / 1'000'000.0;
            break;
        case 6:
            fill_vector();
            auto iterator=std::max_element(data.begin(),data.end());
            int max_value= *iterator;
            auto start_counting = std::chrono::high_resolution_clock::now();
            sort.countingsort(data,max_value);
            auto stop_counting = std::chrono::high_resolution_clock::now();
            auto duration_counting = std::chrono::duration_cast<std::chrono::microseconds>(stop_counting - start_counting);
            double total_time_counting = duration_counting.count() / 1'000'000.0;
            break;
        case 7:
            fill_vector();
            auto start_sort = std::chrono::high_resolution_clock::now();
            std::sort(data.begin(),data.end());
            auto stop_sort = std::chrono::high_resolution_clock::now();
            auto duration_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop_sort - start_sort);
            double total_time_sort = duration_sort.count() / 1'000'000.0;
            break;    
        }
        if (std::is_sorted(data.begin(), data.end())) std::cout << "The vector is sorted.\n";
        else std::cout << "The vector is not sorted.\n";
        data.clear();
    }while (opc!=8);

    return 0;
}
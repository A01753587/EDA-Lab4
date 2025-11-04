#include "Sorting.h"
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
    std::vector<int> data={10,36,1,5,2,2,15,49,50,4,3};
    // auto maxRes=std::max_element(data.begin(),data.end());
    // int max=*maxRes;
    // s.countingsort(data,max);
    s.quicksort(data, 0, data.size()-1);
    std::cout<<data;
    return 0;
}
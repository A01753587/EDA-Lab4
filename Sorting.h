#pragma once
#include <vector>
#include <iostream>
#include<ostream>
class Sorting
{
public:
    Sorting();
    ~Sorting();
    void bubblesort(std::vector<int>& vect);
    void selectionsort(std::vector<int>& vect);
    void insertionsort(std::vector<int>& vect);
    void heapsort(std::vector<int>& vect);
    void quicksort(std::vector<int>& vect);
    void mergesot(std::vector<int>& vect);
};


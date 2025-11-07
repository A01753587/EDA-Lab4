#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
class Sorting
{
public:
    Sorting();
    ~Sorting();
    void bubblesort(std::vector<int>& vect);
    void mergesort(std::vector<int>& vect, int start, int end);
    void selectionsort(std::vector<int>& vect);
    void insertionsort(std::vector<int>& vect);
    void heapsort(std::vector<int>& vect);
    void quicksort(std::vector<int>& vect, int start, int end);
    void mergesot(std::vector<int>& vect);
    void countingsort(std::vector<int>& vect, int max_value);
};


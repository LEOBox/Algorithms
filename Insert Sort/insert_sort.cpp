/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void insert_sort(std::vector<T>& V) {
    for (size_t i = 1; i < V.size(); ++i) {
        auto key = V[i];
        size_t j = i - 1;
        while (j >= 0 && key < V[j]) {
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = key;
    }
}

template <typename T>
void insert_sort_advanced(std::vector<T>& V) {
    for (size_t i = 1; i < V.size(); ++i) {
        auto key = V[i];
        auto position = std::lower_bound(V.begin(), V.begin() + i, key);
        for (auto iter = V.begin()+i; iter > position; --iter) {
            *iter = *(iter - 1);
        }
        *position = key;
    }
}

int main()
{
    std::vector<int> V = {9,8,7,6,5,4,3,2,1,0};
    //insert_sort(V);
    insert_sort_advanced(V);
    
    for (size_t i = 0; i < V.size(); ++i) {
        std::cout << V[i] << std::endl;
    }
    
    return 0;
}

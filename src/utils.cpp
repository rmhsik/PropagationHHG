#include "utils.h"
#include "debug.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <complex>
#include <stdlib.h>

int calc_n_elem(const std::string &path){
    std::ifstream file;
    file.open(path);
    std::string line;
    int n_elem = 0;
    if(file.is_open()){
        while(getline(file,line)){
            n_elem++;
        }
        file.close();
    }
    else{debug0("[calc_n_elem] Error opening file.\n"); exit(1);} 
   return n_elem;
} 

template <class T>
std::tuple<std::vector<T>,double> linspace(T xi, T xf, int n){
    double dx = abs(xf -xi)/(double)(n-1); 
    std::vector<T> grid(n);
    if (n==0){}
    else if(n==1){ grid[0]==xi;}
    else{
        for(int i=0; i<n-1;i++){
            grid[i] = xi + i*dx;
        }
        grid[n-1] = xf;
    }
    return std::make_tuple(grid, dx);
}

template std::tuple<std::vector<int>,double> linspace<int>(int, int, int);
template std::tuple<std::vector<double>,double> linspace<double>(double, double, int);
template std::tuple<std::vector<std::complex<double>>,double> linspace<std::complex<double>>(std::complex<double>, std::complex<double>, int);

#include "utils.h"
#include <fstream>
#include <iostream>
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
    else{ }//debug("[calc_n_elem] Error opening file.\n")} 
   return n_elem;
} 

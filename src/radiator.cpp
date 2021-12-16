#include <cmath>
#include "radiator.h"
#include <iostream>
#include <fstream>

Radiator::Radiator(){

}

Radiator::Radiator(Vec2<double> &v, double wl,
                   const std::string &filepathAcc,
                   const std::string &filepathQ){
    pos_ = v;
    wl_ = wl;
    filepathAcc_ = filepathAcc;
    filepathQ_ = filepathQ;
    
    load_acc();
}

void Radiator::set_pos(const Vec2<double> &v){
    pos_ = v;
}

void Radiator::load_acc(){
    std::ifstream accFile;
    accFile.open(filepathAcc_);
    std::string line;
    std::complex<double> temp;
    n_elem_ = 0;
    if(accFile.is_open()){
        while(getline(accFile,line)){
            n_elem_++;
            std::istringstream is(line); 
            is>>temp;
            accF_.push_back(temp);
            //std::cout<<line<<std::endl;
            //std::cout<<accF_[n_elem_-1]<<std::endl;
        }
        std::cout<<"Number of elements: "<<n_elem_<<std::endl;
        accFile.close();
    }
    else{ std::cout<<"Error opening acceleration file.\n";} 
    
    std::ifstream qFile;
    qFile.open(filepathQ_);
    int temp_n_elem = 0; 
    if(qFile.is_open()){
        while(getline(qFile,line)){
            temp_n_elem++;
            q_.push_back(stod(line));
            //std::cout<<line<<std::endl;
            //std::cout<<q_[temp_n_elem-1]<<std::endl;
        }
        std::cout<<"Number of elements: "<<temp_n_elem<<std::endl;
        qFile.close();
        if (temp_n_elem != n_elem_){
            std::cout<<"Acc file and orders file have different number of elements.\n";
        }
    }
    else{ std::cout<<"Error opening orders file.\n";} 
   
}

void Radiator::optical_path(Vec2<double> &detector){
    opt_path_ = detector-pos_;
}   

std::vecrot<std::complex<double>> propagation(){
    optical_path(detector);
    std::vector<std::complex<double>> propAcc(n_elem_);
    std::complex<double> I(0.0,1.0);

    for (int i=0; i<n_elem; i++){
        std::complex<double> acc_q = accF_[i];
        double q = q_[i];

        // TODO: define wavector k
        acc_q *= exp(I*q*k*opt_path_)*exp(I*q*k*pos_);
        propAcc[i] = acc_q;
    }
    return propAcc;
}

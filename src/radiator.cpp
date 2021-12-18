#include <cmath>
#include "radiator.h"
#include "detector.h"
#include "utils.h"
#include "debug.h"
#include <iostream>
#include <fstream>
#include<stdlib.h>

Radiator::Radiator(){

}

Radiator::Radiator(Vec2<double> &v, double wl,
                   const std::string &filepathAcc,
                   const std::string &filepathQ,
                   Detector *detector,
                   const int idx){
    pos_ = v;
    wl_ = wl;
    filepathAcc_ = filepathAcc;
    filepathQ_ = filepathQ;
    detector_ = detector;
    idx_ = idx;
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
        }
        debug2("[Radiator->load_acc] n_elem_: "<<n_elem_);
        accFile.close();
    }
    else{ debug0("[Radiator->load_acc] Error opening acceleration file.\n");exit(1);} 
    
    std::ifstream qFile;
    qFile.open(filepathQ_);
    int temp_n_elem = 0; 
    if(qFile.is_open()){
        while(getline(qFile,line)){
            temp_n_elem++;
            q_.push_back(stod(line));
        }
        debug2("[Radiator->load_acc] temp_n_elem: "<<temp_n_elem);
        qFile.close();
        if (temp_n_elem != n_elem_){
            debug0("[Radiator->load_acc] Acc file and orders file have different number of elements.\n");
            exit(1);
        }
    }
    else{ debug0("[Radiator->load_acc] Error opening orders file.\n");exit(1);} 
   
}

void Radiator::optical_path(Vec2<double> &detector){
    opt_path_ = detector-pos_;
}   

void Radiator::propagation(){
    Vec2<double> d_pos = detector_->get_pos();
    optical_path(d_pos);
    std::vector<std::complex<double>> propAcc(n_elem_);
    std::complex<double> I(0.0,1.0);
    //debug3("[Radiator->propagation] Optical path: ");
    //opt_path_.print();
    //debug3(std::endl); 
    // Temporal wavevector declaration 
    // until field class 
    Vec2<double> k(1.0,0.0);
    for (int i=0; i<n_elem_; i++){
        std::complex<double> acc_q = accF_[i];
        double q = q_[i];
        std::complex<double> phi1, phi2;
        phi1 = std::complex<double>(1.0,0.0)*(k*opt_path_);
        phi2 = std::complex<double>(1.0,0.0)*(k*pos_);
        // TODO: define wavector k
        acc_q *= exp(I*q*phi1)*exp(I*q*phi2);
        debug4("[Radiator->propagation] acc_q: "<<acc_q);
        propAcc[i] = acc_q;
    }
    detector_->add_emission(propAcc);
}

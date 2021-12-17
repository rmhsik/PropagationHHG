#include "detector.h"
#include "utils.h"
#include <complex>
#include <string>
#include <fstream>
#include <iostream>


Detector::Detector(){}

Detector::Detector(int n_elem, const Vec2<double> &pos, const int idx){
    idx_ = idx;
    n_elem_ = n_elem;
    pos_ = pos;
    accF_.resize(n_elem_);
}

Vec2<double> Detector::get_pos(){
    return pos_;
}

void Detector::add_emission(const std::vector<std::complex<double>> &accF){
    std::cout<<"[Detector] *accF: "<<&accF_<<std::endl;
    for (int i=0; i<n_elem_; i++){
        std::complex<double> temp = accF[i];
        accF_[i] += temp;
    }
    for (int i=0; i<n_elem_; i++){
        std::cout<<"[Detector] accF_: "<<accF_[i]<<std::endl; 
    }
    std::cout<<"[Detector] *accF: "<<&accF_<<std::endl;
}

void Detector::print_acc(){
    for (int i=0; i<n_elem_; i++){
        std::cout<<"[Detector] accF_: "<<accF_[i]<<std::endl; 
    }
    std::cout<<"[Detector] *accF: "<<&accF_<<std::endl;
}


void Detector::write_to_file(){
    std::string basepath = "results/prop_acc";
    std::string ext = ".dat";
    std::string path = basepath + std::to_string(idx_) + ext;
    std::cout<<"[Detector] Path: "<<path<<std::endl;
    std::ofstream outfile;
    outfile.open(path);

    std::cout<<"[Detector] *accF: "<<&accF_<<std::endl;
    if(outfile.is_open()){
        for(int i=0; i<n_elem_; i++){
            std::cout<<"[Detector] accF_: "<<this->accF_[i]<<std::endl; 
            outfile<<accF_[i]<<std::endl;
        }
        outfile.close();
    }
    else{ std::cout<<"[Detector] Error opening outfile.\n";}

}

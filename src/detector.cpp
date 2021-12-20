#include "detector.h"
#include "utils.h"
#include "debug.h"
#include <complex>
#include <string>
#include <fstream>
#include <iostream>


Detector::Detector(){}

Detector::Detector(int n_elem, const Vec2<double> &pos, const std::string &filepath, const int idx){
    idx_ = idx;
    n_elem_ = n_elem;
    pos_ = pos;
    accF_.resize(n_elem_);
    filepath_ = filepath;
    debug2("[Detector] n_elem_: "<< n_elem_);
    debug2("[Detector] filepath: "<< filepath_);
}

int Detector::get_n_elem(){
    return n_elem_;
}

Vec2<double> Detector::get_pos(){
    return pos_;
}

void Detector::add_emission(const std::vector<std::complex<double>> &accF){
    debug3("[Detector -> add_emision] n_elem_: "<< n_elem_);
    for (int i=0; i<n_elem_; i++){
        std::complex<double> temp = accF[i];
        accF_[i] += temp;
    }
    for (int i=0; i<n_elem_; i++){
        debug4("[Detector->add_emission] accF_: "<<accF_[i]); 
    }
    debug3("[Detector->add_emission] *accF: "<<&accF);
}

void Detector::print_acc(){
    for (int i=0; i<n_elem_; i++){
        std::cout<<"[Detector->print_acc] accF_: "<<accF_[i]<<std::endl; 
    }
    debug3("[Detector->print_acc] *accF: "<<&accF_);
}


void Detector::write_to_file(){
    debug2("[Detector->write_to_file] Path: "<<path);
    std::ofstream outfile;
    outfile.open(filepath_,std::ofstream::app);

    debug3("[Detector->write_to_file] *accF: "<<&accF_);
    debug3("[Detector->write_to_file]Outfile status: "<<outfile.is_open());
    if(outfile.is_open()){
        debug3("[Detector -> write_to_file] Writing to file...");
        debug2("[Detector -> write_to_file] n_elem_: "<< n_elem_);
        outfile<<idx_<<" ";
        for(int i=0; i<n_elem_; i++){
            debug4("[Detector] accF_: "<<accF_[i]); 
            outfile<<accF_[i]<<" ";
        }
        outfile<<std::endl;
        outfile.close();
    }
    else{ debug1("[Detector->write_to_file] Error opening outfile.\n");}

}

#include "detector.h"
#include "utils.h"
#include "debug.h"
#include <complex>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

Detector::Detector(){}

Detector::Detector(Parameters &param, const Vec2<double> &pos, const int idx){
    idx_ = idx;
    n_elem_ = param.n_elem;
    pos_ = pos;
    counter_ = 0;
    accF_.resize(n_elem_);
    std::fill(accF_.begin(),accF_.end(),std::complex<double>(0.0,0.0));
    filepath_ = param.outprop;
    debug2("[Detector] n_elem_: "<< n_elem_);
    debug2("[Detector] filepath: "<< filepath_);
}

int Detector::get_n_elem(){
    return n_elem_;
}

Vec2<double> Detector::get_pos(){
    return pos_;
}

void Detector::update_pos(const Vec2<double> &pos, const int idx){
    pos_ = pos;
    idx_ = idx;
    counter_=0;
    std::fill(accF_.begin(),accF_.end(),std::complex<double>(0.0,0.0));
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
    std::ofstream outfile;
    outfile.open(filepath_,std::ofstream::app);
    std::ostringstream doubleStr;

    debug3("[Detector->write_to_file] *accF: "<<&accF_);
    debug3("[Detector->write_to_file]Outfile status: "<<outfile.is_open());
    if(outfile.is_open()){
        debug3("[Detector -> write_to_file] Writing to file...");
        outfile<<idx_<<" ";
        for(int i=0; i<n_elem_; i++){
            doubleStr<<std::fixed<<std::setprecision(12);
            doubleStr<<accF_[i];
            debug4("[Detector] accF_: "<<accF_[i]); 
            outfile<<doubleStr.str()<<" ";
        }
        outfile<<std::endl;
        outfile.close();
    }
    else{ debug1("[Detector->write_to_file] Error opening outfile.\n");}

}

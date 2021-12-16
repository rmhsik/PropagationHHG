#include "detector.h"
#include <complex>
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
    for (int i=0; i<n_elem_; i++){
        accF_[i] += accF[i]; 
    }
}

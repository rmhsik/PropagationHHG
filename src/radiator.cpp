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

Radiator::Radiator(Vec2<double> &v,
                   double wl,
                   double inc_theta,
                   const std::vector<std::complex<double>> &accF_vec,
                   const std::vector<double> &q_vec,
                   Detector *detector,
                   const int idx){
    pos_ = v;
    wl_ = wl;
    inc_theta_ = inc_theta;
    q_vec_ = q_vec;
    accF_ = accF_vec;
    detector_ = detector;
    idx_ = idx;
    n_elem_ = detector_->get_n_elem();
}

void Radiator::set_pos(const Vec2<double> &v){
    pos_ = v;
}

void Radiator::optical_path(Vec2<double> &detector){
    opt_path_ = detector-pos_;
}   

void Radiator::propagation(Detector* detector){
    Vec2<double> d_pos = detector->get_pos();
    optical_path(d_pos);
    debug3("[Radiator->propagation] n_elem_ : "<<n_elem_ );
    std::vector<std::complex<double>> propAcc(n_elem_);
    std::complex<double> I(0.0,1.0);
    Vec2<double> k(cos(inc_theta_),sin(inc_theta_));
    k *= 2.0*M_PI/wl_;
    Vec2<double> x_vec(1.0,0.0);
    double angle = opt_path_.angle(x_vec);
    int sign = opt_path_.y() > 0.0 ? 1 : -1;
    Vec2<double> k_hhg(cos(sign*angle),sin(sign*angle));
    k_hhg *= 2.0*M_PI/wl_;
    debug3("[Radiator->propagation] Start loop...\n");
    for (int i=0; i<n_elem_; i++){
        debug3("[Radiator->propagation] Get acc...\n");
        std::complex<double> acc_q = accF_[i];
        debug3("[Radiator->propagation] Get q...\n");
        double q = q_vec_[i];
        Vec2<double> kq = k_hhg*q;
        debug3("[Radiator->propagation] Declare phases\n");
        std::complex<double> phi1, phi2;
        debug3("[Radiator->propagation] Calc phases\n");
        phi1 = std::complex<double>(1.0,0.0)*(kq*opt_path_);
        phi2 = std::complex<double>(1.0,0.0)*(k*pos_)*q;
        // TODO: define wavector k
        acc_q *= exp(I*phi1)*exp(I*phi2);
        debug4("[Radiator->propagation] acc_q: "<<acc_q);
        propAcc[i] = acc_q;
    }
    debug3("[Radiator->propagation] Adding emission...\n");
    detector->add_emission(propAcc);
}

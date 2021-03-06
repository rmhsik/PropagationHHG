#ifndef RADIATOR_H
#define RADIATOR_H

#include <string>
#include <vector>
#include <complex>
#include "vec2.h"
#include "detector.h"
#include "param.h"

class Radiator{
    private:
        Vec2<double> pos_;
        Vec2<double> opt_path_;
        std::vector<std::complex<double>> accF_;
        std::vector<double> q_vec_;
        double wl_;
        int n_elem_,idx_;
        double inc_theta_;
        //std::string filepathAcc_, filepathQ_;
        Detector *detector_;
    public:
        Radiator();
        Radiator(Vec2<double> &v,
                 double wl,
                 double inc_theta,
                 const std::vector<std::complex<double>> &accF_vec,
                 const std::vector<double> &q_vec,
                 Detector *detector,
                 const int idx);
        void set_pos(const Vec2<double> &v);
        void optical_path(Vec2<double> &detector);
        void propagation(Detector *detector);


};

#endif

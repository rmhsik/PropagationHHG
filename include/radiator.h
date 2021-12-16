#ifndef RADIATOR_H
#define RADIATOR_H

#include <string>
#include <vector>
#include <complex>
#include "vec2.h"
#include "detector.h"

class Radiator{
    private:
        Vec2<double> pos_;
        Vec2<double> opt_path_;
        std::vector<std::complex<double>> accF_;
        std::vector<double> q_;
        double wl_;
        int n_elem_;
        std::string filepathAcc_, filepathQ_;
        Detector detector_;
    public:
        Radiator();
        Radiator(Vec2<double> &v, double wl,
                 const std::string &filepathAcc, 
                 const std::string &filepathQ,
                 const Detector &detector);
        void set_pos(const Vec2<double> &v);
        void load_acc();
        void optical_path(Vec2<double> &detector);
        void propagation();


};

#endif

#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "param.h"
#include <string>
#include <vector>
#include <complex>
class Interpolation{

    private:
        std::string path_interp_;
        std::string path_node_;
        std::string path_q_;
        int n_nodes_, n_interpolations_;
        
        std::vector<std::vector<std::vector<std::complex<double>>>> data_;
        std::vector<double> node_vec_;
        std::vector<double> q_vec_;
    public:
        Interpolation();
        Interpolation(const Parameters &param);
        void read_data();
        std::vector<std::complex<double>> interp(double phi);
};

#endif

#ifndef PARAM_H
#define PARAM_H

#include <string>

struct Parameters{

    int n_radiators      = 10000;
    int n_slabs          = 20; 
    int n_theta          = 1;
    double wl            = 0.8;
    double xmax          = 100;
    double ymax          = 100;
    double slab_width    = 1e-3;
    std::string pathAcc  = "data/testAcc.dat"

}

#endif

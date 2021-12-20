#ifndef PARAM_H
#define PARAM_H

#include <string>
#include <iostream>
#include "utils.h"

class Parameters{
    
    private:
    public:
        std::string pathAcc  = "data/testAcc.dat";
        std::string pathQ    = "data/testQ.dat";
        std::string outprop  = "results/prop_acc";
        int n_radiators      = 10000;
        int n_slabs          = 20; 
        int n_theta          = 400;
        int n_elem           = calc_n_elem(pathQ);
        double L             = 1e4; 
        double wl            = 0.8;
        double xmax          = 100;
        double ymax          = 100;
        double slab_width    = 1e-3;

        Parameters();
        
        void print();
    //outprop              = define_filepath(outprop);
};

#endif

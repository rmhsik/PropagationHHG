#ifndef PARAM_H
#define PARAM_H

#include <string>
#include <iostream>
#include "utils.h"

class Parameters{
    
    private:
    public:
        std::string pathAcc     = "data/testAcc.dat";
        std::string pathQ       = "data/testQ.dat";
        std::string pathNode    = "data/nodelist.dat";
        std::string pathInterp  = "data/interp.dat";
        std::string outprop     = "results/prop_acc";
        int n_radiators         = 10000;
        int n_slabs             = 250; 
        int n_theta             = 400;
        int n_elem              = calc_n_elem(pathQ);
        double L                = 1e3; 
        double wl               = 0.8;
        double xmax             = 0.4;
        double ymax             = 100;
        double slab_width       = 1e-3;

        Parameters();
        
        void print();
    //outprop              = define_filepath(outprop);
};

#endif

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
        int n_radiators         = 20000;
        int n_slabs             = 1; 
        int n_theta             = 400;
        int n_elem              = calc_n_elem(pathQ);
        double L                = 1e3; 
        double wl               = 0.8;
        double xmax             = 500;
        double ymax             = 100;
        double slab_width       = 30e0;

        Parameters();
        
        void print();
    //outprop              = define_filepath(outprop);
};

#endif

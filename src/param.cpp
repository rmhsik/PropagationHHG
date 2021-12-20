#include "param.h"
#include <iostream>

Parameters::Parameters(){
    outprop = define_filepath(outprop);
    n_elem  = calc_n_elem(pathQ);

}

void Parameters::print(){
    std::cout<<"Parameters: \n";
    std::cout<<"---------------\n";
    std::cout<<std::endl;
    std::cout<<"L: "<<L<<std::endl;
    std::cout<<"xmax: "<<xmax<<std::endl;
    std::cout<<"ymax: "<<ymax<<std::endl;
    std::cout<<"wl: "<<wl<<std::endl;
    std::cout<<"slab_width: "<<slab_width<<std::endl;
    std::cout<<"n_radiators: "<<n_radiators<<std::endl;
    std::cout<<"n_slabs: "<<n_slabs<<std::endl;
    std::cout<<"n_theta: "<<n_theta<<std::endl;
    std::cout<<"n_elem: "<<n_elem<<std::endl;
    std::cout<<"pathAcc: "<<pathAcc<<std::endl;
    std::cout<<"pathQ: "<<pathQ<<std::endl;
    std::cout<<"outprop: "<<outprop<<std::endl;
    std::cout<<std::endl;
}

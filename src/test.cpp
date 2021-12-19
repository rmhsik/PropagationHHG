#include "vec2.h"
#include "radiator.h"
#include "detector.h"
#include "target.h"
#include "test.h"
#include "utils.h"
#include "debug.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

void test_vec2(){
    Vec2<double> vecD1(1,3);
    Vec2<double> vecD2(2,4);
    Vec2<double> vecTemp;

    std::cout<<"vecD1: "; 
    vecD1.print();
    std::cout<<std::endl;
    std::cout<<"vecD2: ";
    vecD2.print();
    std::cout<<std::endl;

    std::cout<<"vecD1 norm: "<<vecD1.norm()<<std::endl;
    std::cout<<"vecD2 norm: "<<vecD2.norm()<<std::endl;

    std::cout<<"Operator+: ";
    vecTemp = vecD1 + vecD2;
    vecTemp.print(); 
    std::cout<<std::endl;

    std::cout<<"Operator-: ";
    vecTemp = vecD1 - vecD2;
    vecTemp.print();
    std::cout<<std::endl;

    std::cout<<"Operator* scalar: ";
    vecTemp = vecD1 * -2.2;
    vecTemp.print();
    std::cout<<std::endl;

    std::cout<<"Operator* dot: ";
    double dot = vecD1 * vecD2;
    std::cout<<dot;
    std::cout<<std::endl;

    std::cout<<"Operator/: ";
    vecTemp = vecD1/vecD1.norm();
    vecTemp.print();
    std::cout<<std::endl;

    std::cout<<"Distance: ";
    std::cout<<vecD1.distance(vecD2)<<std::endl;
    
    std::cout<<"Angle: ";
    std::cout<<vecD1.angle(vecD2)<<std::endl;
}

/*
void test_radiator(){
    #ifdef DEBUG
        std::cout<<"Debug enabled.\n";
    #else
        std::cout<<"Debug disabled\n";
    #endif


    debug2("[test_radiator]");
    double L = 1e4;
    double theta = 0.0;
    int n_elem, n_theta, n_radiators;
    double dtheta;
    std::vector<double> theta_vec;
    n_theta = 1;
    n_radiators =1000; 
    std::tie (theta_vec, dtheta) = linspace<double>(0,2,n_theta);

    std::string pathAcc = "data/testAcc.dat";
    std::string pathQ = "data/testQ.dat";
    n_elem = calc_n_elem("data/testQ.dat");
   

    std::ofstream pos_file;
    pos_file.open("results/radiator_pos.dat");     
    std::vector<Vec2<double>> pos_vec(n_radiators);
    
    if(!pos_file.is_open()){
        debug1("[test_radiator] Not storing radiator positions.")
    }
    for(int i=0;i<n_radiators;i++){
        double x,y;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0,1.0);
        pos_vec[i] = Vec2<double>(dis(gen)*100,dis(gen)*1E-3);
        if(pos_file.is_open()){
            pos_file<<pos_vec[i].x()<<" "<<pos_vec[i].y()<<std::endl;
        }
    }
    pos_file.close();

    for(int i=0;i<n_theta;i++){
        Vec2<double> d_pos(L*cos(theta_vec[i]),L*sin(theta_vec[i]));
        Detector detector(n_elem,d_pos,i);
        for (int j=0;j<n_radiators;j++){
            Radiator r1(pos_vec[j],0.8,pathAcc,pathQ,&detector,j);
            r1.propagation();
            detector.write_to_file();
        }
    }

   
    Detector detector(n_elem,d_pos,0);
    Radiator r1(pos,0.8,pathAcc,pathQ,&detector,0);
    r1.propagation();
    detector.print_acc();
    detector.write_to_file();
}
*/
void test_target(){
    int n_radiators, n_slabs, n_elem;
    double xmax, ymax, wl, slab_width, L, theta;

    n_radiators = 10000;
    n_slabs= 20;
    xmax = 100.0;
    ymax = 100.0;
    wl = 0.8;
    slab_width=1e-3;
    L = 1e4;
    theta = 0.0;
   
    Vec2<double> d_pos(L*cos(theta),L*sin(theta)); 
    n_elem = calc_n_elem("data/testQ.dat");
  
    std::string pathq = "data/testQ.dat";
    std::string pathacc = "data/testAcc.dat";
     
    Detector detector(n_elem,d_pos,0);

    debug2("[test_target] Initializing target...\n"); 
    Target target(n_radiators, n_slabs, xmax, ymax, slab_width, wl,pathq,pathacc, &detector);
    debug2("[test_target] Target finished.\n");

    debug2("[test_target] Generating radiator positions...\n");
    target.generate_pos();
    debug2("[test_target] Finished calculating radiator positions,\n");
    
    debug2("[test_target] Generating radiators...\n");
    target.generate_radiators();
    debug2("[test_target] Finished generating radiators.\n");

    debug2("[test_target] Propagating...\n");
    target.propagate();
    debug2("[test_target] Finished propagation.\n");

}


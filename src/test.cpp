#include "vec2.h"
#include "radiator.h"
#include "detector.h"
#include "test.h"
#include <iostream>
#include <string>

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


void test_radiator(){
    double L = 1e4;
    double theta = 0.0;    
    Vec2<double> d_pos(L*cos(theta),L*sin(theta));
    // TODO: function to determine number of entries
    Detector detector(3,d_pos,0);
    Vec2<double> pos(1.0,0.0);
    std::string pathAcc = "data/test.dat";
    std::string pathQ = "data/q.dat";
    Radiator r1(pos,0.8,pathAcc,pathQ,detector);
    r1.propagation(); 
}

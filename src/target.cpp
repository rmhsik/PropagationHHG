#include "target.h"
#include "debug.h"
#include "utils.h"
#include <random>
#include <string>
#include <fstream>

Target::Target(){}

Target::Target(int n_radiators, int n_slabs, double xmax, double ymax, double slab_width, double wl, std::string &pathq, std::string &pathacc, Detector *detector){
    n_radiators_ = n_radiators;
    n_slabs_ = n_slabs;
    xmax_ = xmax;
    ymax_ = ymax;
    slab_width_ = slab_width;
    wl_ = wl;
    pathq_ = pathq;
    pathacc_ = pathacc;
    detector_ = detector;
   
    q_vec_= load_q();
    acc_vec_ = load_acc();
     
    radiators_vec_.resize(n_radiators);
    pos_vec_.resize(n_radiators);
}

std::vector<double> Target::load_q(){
    std::vector<double> q_vec;
    std::ifstream qfile;
    qfile.open(pathq_);
    std::string line;
    int counter = 0;
    if(qfile.is_open()) {
        while(getline(qfile,line)){
            q_vec.push_back(stod(line));
            counter++;
        }
        debug2("[Target->load_q] q file loaded. Counter: "<<counter<< " \n");
        return q_vec;
    }
    else{debug0("[Target->load_q] Error opening q file.\n"); exit(1);}
}

std::vector<std::complex<double>> Target::load_acc(){
    std::vector<std::complex<double>> acc_vec;
    std::ifstream accfile;
    accfile.open(pathacc_);
    std::string line;
    std::complex<double> temp;
    if(accfile.is_open()) {
        while(getline(accfile,line)){
            std::istringstream is(line); 
            is>>temp;
            acc_vec.push_back(temp);
        }
        debug2("[Target->load_acc] acc file loaded. \n");
        return acc_vec;
    }
    else{debug0("[Target->load_acc] Error opening q file.\n"); exit(1);}

}

void Target::generate_pos(){
    std::string pos_path = "results/radiator_pos.dat";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0,1.0);
    
    int k = 0;
    for(int i=-n_slabs_/2; i<n_slabs_/2;i++){
        for(int j=0; j<(int)(n_radiators_/n_slabs_);j++){
            double x,y;
            x = dis(gen)*xmax_; 
            y = i*wl_/2.0-slab_width_/2.0 + dis(gen)*slab_width_;
            debug4("[Target->generate_pos]"<<x<<" "<<y<<"\n");
            pos_vec_[k] = Vec2<double>(x,y);
            k++;
        }    
    }
    if(k != n_radiators_){debug1("[Target->generate_pos] k != n_radiators");}
    write_vector<Vec2<double>> (pos_vec_, pos_path); 
}

void Target::generate_radiators(){
    std::vector<std::complex<double>> accF = acc_vec_;
    std::vector<double> q_vec = q_vec_;

    for(int i=0; i<n_radiators_;i++){
        radiators_vec_[i] = Radiator (pos_vec_[i],0.8,accF,q_vec_, detector_, i); 
    }
    debug3("[Target->generate_radiators] Radiators generated.\n");
}

void Target::propagate(){
    for(int i=0; i<n_radiators_;i++){
        radiators_vec_[i].propagation();
    }
    detector_->write_to_file();
}

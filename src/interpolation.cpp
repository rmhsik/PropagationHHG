#include "interpolation.h"
#include "param.h"
#include "debug.h"
#include <fstream>
#include <string>
#include <vector>
#include <complex>
#include <stdlib.h>


Interpolation::Interpolation(){}

Interpolation::Interpolation(const Parameters &param){
    path_interp_= param.pathInterp;
    path_node_ = param.pathNode;
    path_q_ = param.pathQ;

    int n_nodes_ = calc_n_elem(path_node_)-1;
    int n_interpolations_ = calc_n_elem(path_q_);

    data_.resize(n_interpolations_,std::vector<std::vector<std::complex<double>>>(n_nodes_,std::vector<std::complex<double>>(4)));

    read_data();
}

void Interpolation::read_data(){
    std::string line;

    std::ifstream qfile;
    qfile.open(path_q_);
    if(qfile.is_open()){
        while(getline(qfile,line)){
            q_vec_.push_back(stod(line));
        }
        qfile.close();
    }
    else{debug0("[Interpolation->read_data] Unable to open q_file"); exit(1);}
    
    std::ifstream nodefile;
    nodefile.open(path_node_);
    if(nodefile.is_open()){
        while(getline(nodefile,line)){
            node_vec_.push_back(stod(line));
        }
        nodefile.close();
    }
    else{debug0("[Interpolation->read_data] Unable to open node_file"); exit(1);}


    std::ifstream datafile;
    datafile.open(path_interp_);
    int node_counter = 0;
    int q_counter = 0;
    debug3("[Interpolation->read_data] Starting interp file reading...");
    if(datafile.is_open()){
        while(getline(datafile,line)){
            std::stringstream s(line);
            std::complex<double> c0,c1,c2,c3;
            std::string temp;
            getline(s,temp,' ');
            std::stringstream k_c0(temp);
            k_c0>>c0;
            getline(s,temp,' ');
            std::stringstream k_c1(temp);
            k_c1>>c1;
            getline(s,temp,' ');
            std::stringstream k_c2(temp);
            k_c2>>c2;
            getline(s,temp,' ');
            std::stringstream k_c3(temp);
            k_c3>>c3;
            data_[q_counter][node_counter%39][0] = c0;
            data_[q_counter][node_counter%39][1] = c1;
            data_[q_counter][node_counter%39][2] = c2;
            data_[q_counter][node_counter%39][3] = c3;
            node_counter++;
            q_counter = node_counter%39==0 ? q_counter += 1 : q_counter; 
        }
    }
    else{debug0("[Interpolation->read_data] Unable to open interp_file");exit(1);}

}

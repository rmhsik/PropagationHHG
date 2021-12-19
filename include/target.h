#ifndef TARGET_H
#define TARGET_H

#include "radiator.h"
#include "vec2.h"
#include "radiator.h"
#include <string>

class Target{
    private: 
        int n_radiators_, n_slabs_, n_elem_;
        double xmax_, ymax_, slab_width_, wl_;
        Detector *detector_;
        std::vector<Radiator> radiators_vec_;
        std::vector<Vec2<double>> pos_vec_;
        std::vector<double> q_vec_;
        std::vector<std::complex<double>> acc_vec_;
        std::string pathq_, pathacc_;
    public:
        Target();
        Target(int n_radiators, int n_slabs, double xmax, double ymax, double slab_width, double wl, std::string &pathq, std::string &pathacc, Detector *detector);
        std::vector<double> load_q();
        std::vector<std::complex<double>> load_acc();
        void generate_pos();
        void generate_radiators();
        void propagate();
};

#endif

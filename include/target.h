#ifndef TARGET_H
#define TARGET_H

#include "radiator.h"
#include "vec2.h"
#include "radiator.h"
#include "param.h"
#include "interpolation.h"
#include <string>

class Target{
    private: 
        int n_radiators_, n_slabs_, n_elem_;
        double xmax_, ymax_, slab_width_, wl_;
        Detector *detector_;
        Interpolation interp_;
        std::vector<Radiator> radiators_vec_;
        std::vector<Vec2<double>> pos_vec_;
        std::vector<double> q_vec_;
        std::vector<std::complex<double>> acc_vec_;
        std::string pathq_, pathacc_;
    public:
        Target();
        Target(Parameters &param, Detector *detector);
        std::vector<double> load_q();
        std::vector<std::complex<double>> load_acc();
        void generate_pos();
        void generate_radiators();
        void update_detector(Detector *detector);
        void propagate();
};

#endif

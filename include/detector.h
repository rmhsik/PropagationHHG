#ifndef DETECTOR_H
#define DETECTOR_H

#include <vector>
#include <complex>
#include "vec2.h"

class Detector{
    private:
        std::vector<std::complex<double>> accF_;
        Vec2<double> pos_;
        int n_elem_,idx_;
        std::string filepath_;
    public:
        Detector();
        Detector(int n_elem, const Vec2<double> &pos, const std::string &filepath, const int idx);
        Vec2<double> get_pos();
        int get_n_elem();
        void add_emission(const std::vector<std::complex<double>> &accF);
        void write_to_file();
        void print_acc();
};

#endif

#ifndef UTILS_H
#define UTILS_H


#include<iostream>
#include <string>
#include <tuple>
#include <vector>


int calc_n_elem(const std::string &path);

template <class T>
void write_vector(const std::vector<T> &vec, const std::string &path);

template <class T>
std::tuple<std::vector<T>,double> linspace(T xi, T xf, int n);
#endif

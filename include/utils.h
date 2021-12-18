#ifndef UTILS_H
#define UTILS_H


#ifdef DEBUG
#   define debug(x) std::cout<<x<<std::endl;
#else
#   define debug(x)
#endif

#include <string>
#include <tuple>
#include <vector>


int calc_n_elem(const std::string &path);

template <class T>
std::tuple<std::vector<T>,double> linspace(T xi, T xf, int n);
#endif

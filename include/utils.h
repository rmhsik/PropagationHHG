#ifndef UTILS_H
#define UTILS_H

#ifdef DEBUG
#   define debug(x) std::cout<<x
#else
#   define debug(x)
#endif


#include <string>

int calc_n_elem(const std::string &path);

#endif

#include <iostream>
#include <complex>
#include <cmath>
#include "vec2.h"

template <class T>
Vec2<T>::Vec2(){
    x_ = y_ = 0.0;
}

template <class T>
Vec2<T>::Vec2(T x, T y){
    x_ = x; y_ = y;
}

template <class T>
void Vec2<T>::print(){
    std::cout<<"("<<x_<<","<<y_<<")\n";
}

template <class T>
T Vec2<T>::x(){
    return x_;
}

template <class T>
T Vec2<T>::y(){
    return y_;
}

template <class T>
void Vec2<T>::x(const T xval){
    x_ = xval;
}

template <class T>
void Vec2<T>::y(const T yval){
    y_ = yval;
}

template <class T>
void Vec2<T>::set(const T xval, const T yval){
    x_ = xval;
    y_ = yval;
} 

template <class T>
void Vec2<T>::zero(){
    x_ = y_ = 0;
}

template <class T>
T Vec2<T>::norm(){
    T norm = sqrt(x_*x_ + y_*y_);
    return norm;
}

template <class T>
Vec2<T> Vec2<T>::operator+(const Vec2 &v){
    return Vec2(x_+v.x_, y_+v.y_);
}

template <class T>
void Vec2<T>::operator+=(const Vec2 &v){
    x_ = v.x_;
    y_ = v.y_;
}

template <class T>
Vec2<T> Vec2<T>::operator-(const Vec2 &v){
    return Vec2(x_ - v.x_, y_ -v.y_);;
}

template <class T>
void Vec2<T>::operator-=(const Vec2 &v){
    x_ -= v.x_;
    y_ -= v.y_;
}

template <class T>
Vec2<T> Vec2<T>::operator*(const T val){
    return Vec2(x_*val,y_*val);
}

template <class T>
void Vec2<T>::operator*=(const T val){
    x_ *= val;
    y_ *= val;
}

template <class T>
T Vec2<T>::operator*(const Vec2 &v){
    return x_*v.x_ + y_*v.y_;
}

template <class T>
Vec2<T> Vec2<T>::operator/(const T val){
    return Vec2(x_/val,y_/val);
}

template <class T>
void Vec2<T>::operator/=(const T val){
    x_ /= val;
    y_ /= val;
}

template class Vec2<int>;
template class Vec2<double>;
template class Vec2<std::complex<double>>;

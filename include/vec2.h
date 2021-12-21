#ifndef VEC2_H
#define VEC2_H

#include<iostream>
#include<iomanip>

template <class T> 
class Vec2{
    private:
        T x_,y_;
    public:
        Vec2();
        Vec2(T x, T y);
        void print();
        T norm();
        T x();
        T y();
        void x(const T xval);
        void y(const T yval);
        void set(const T x, const T y); 
        void zero();
        T distance(Vec2 &v);
        T angle(Vec2 &v);
        Vec2 operator+(const Vec2 &v);
        void operator+=(const Vec2 &v);
        Vec2 operator-(const Vec2 &v);
        void operator-=(const Vec2 &v);
        Vec2 operator*(const T val);
        void operator*=(const T val); 
        T operator*(const Vec2 &v);
        Vec2 operator/(const T val);
        void operator/=(const T val);
       
         
        friend std::ostream & operator<< (std::ostream &out,const Vec2<T> &v){
            out<<std::fixed<<std::setprecision(12);
            out<<v.x_<<" "<<v.y_<<std::endl;
            return out;
        }
        friend std::istream & operator>> (std::istream &in, Vec2<T> &v){ 
            in>>v.x_>>" ">>v.y_>>std::endl;
            return in;
        }
};


#endif

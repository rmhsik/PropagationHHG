#ifndef VEC2_H
#define VEC2_H

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
    
};


#endif

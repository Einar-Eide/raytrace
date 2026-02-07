#pragma once

#include <cmath>

class vec3{
public:

    vec3() : x(0), y(0), z(0) {}
    vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    double set(double in_x, double in_y, double in_z){
        x = in_x;
        y = in_y;
        z = in_z;
    }

    double get_x(){ return x; }
    double get_y(){ return y; }
    double get_z(){ return z; }

    double length_squared(){
        return x*x + y*y + z*z;
    }

    double length(){
        return std::sqrt(length_squared());
    }

    friend vec3 operator*(vec3 vec, double k);
    friend vec3 operator+(vec3 u, vec3 v);
    friend vec3 operator-(vec3 u);

private:

    double x;
    double y;
    double z;

};

vec3 operator+(vec3 u, vec3 v) { return vec3(u.x+v.x, u.y+v.y, u.z+v.z); }
vec3 operator-(vec3 u) { return vec3(-u.x, -u.y, -u.z); }
vec3 operator-(vec3 u, vec3 v) { return u + (-v); }

vec3 operator*(vec3 u, double k) { return vec3( u.x*k, u.y*k, u.z*k ); }
vec3 operator*(double k, vec3 vec) { return vec*k; }

vec3 operator/(vec3 vec, double k) { return vec * (1/k); }






using pos = vec3;
#ifndef _SHAPE_H
#define _SHAPE_H
#include "ray.hpp"

class Shape {
public:
	Shape(): spu(0), spv(0), sp(0) { }
	my_vec<3, float> ka;
	my_vec<3, float> ks;
	my_vec<3, float> kd;
	my_vec<3, float> kr;
    float spu;
    float spv;
    float sp;

    void report() {
        std::cout << "-ka: " << std::endl;
        ka.report();
        std::cout << "-ks: " << std::endl;
        ks.report();
        std::cout << "-kd: " << std::endl;
        kd.report();
        std::cout << "-kr: " << std::endl;
        kr.report();
        
        std::cout << "-spu: " << spu << std::endl;
        std::cout << "-spv: " << spv << std::endl;
        std::cout << "-sp: " << sp << std::endl;
    }

    virtual bool intersect(ray &ray, my_vec<3, float> *int_pos) { return false; }
};

class Sphere: public Shape {
public:
	Sphere(): radius(0) { 
		printf("sgggg\n");
		Shape(); 
	}
	float radius;
	my_vec<3, float> center;
	bool intersect(ray &ray, my_vec<3, float> *int_pos) {
		/* Directional Light */
		return false;
	}
};

class Triangle: public Shape {
	my_vec<3, float> pa;
	my_vec<3, float> pb;
	my_vec<3, float> pc;
	bool intersect(ray &ray, my_vec<3, float> *int_pos) {
		return false;
	}
};

#endif
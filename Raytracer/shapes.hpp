#ifndef _SHAPE_H
#define _SHAPE_H
#include "ray.hpp"

class Shape {
public:
	Shape(): spu(0), spv(0), sp(0) { }

	my_color ka;
	my_color ks;
	my_color kd;
	my_color kr;
    float spu;
    float spv;
    float sp;

    virtual bool intersect(ray &ray, my_vec<3, float> *int_pos) { return false; }
    virtual void report() { }

protected:
    void _report() {
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
	void report() {
		std::cout << "Sphere: r = " << radius << std::endl;
		std::cout << "center: " << std::endl;
		center.report();
		_report();
	}
};

class Triangle: public Shape {
public:
	Triangle() {
		printf("Triangle\n");
		Shape();
	}
	my_vec<3, float> pa;
	my_vec<3, float> pb;
	my_vec<3, float> pc;
	bool intersect(ray &ray, my_vec<3, float> *int_pos) {
		return false;
	}
	void report() {
		std::cout << "Triangle: " << std::endl;
		pa.report();
		pb.report();
		pc.report();
		_report();
	}
};

#endif
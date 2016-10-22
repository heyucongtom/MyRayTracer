#include "ray.hpp"

class Shape {
public:
	Shape(): ka(0), ks(0), kd(0), kr(0), spu(0), spv(0), sp(0) { }
	float ka;
    float ks;
    float kd;
    float kr;
    float spu;
    float spv;
    float sp;

    void report() {
        std::cout << "-ka: " << ka << std::endl;
        std::cout << "-ks: " << ks << std::endl;
        std::cout << "-kd: " << kd << std::endl;
        
        std::cout << "-spu: " << spu << std::endl;
        std::cout << "-spv: " << spv << std::endl;
        std::cout << "-sp: " << sp << std::endl;
    }

    virtual bool intersect(ray &ray, my_vec<3, float> *int_pos) { return false; }
};

class Sphere: public Shape {
public:
	Sphere(): radius(0) { Shape(); }
	float radius;
	my_vec<3, float> center;
	bool intersect(ray &ray, my_vec<3, float> *int_pos) {

	}
};
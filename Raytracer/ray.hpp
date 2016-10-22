#ifndef _RAY_H_
#define _RAY_H_

#include "vector.hpp"
#include "color.hpp"

class ray {

public:
	ray(): type(0) { };
	ray(int t): type(t) { }
	my_vec<3, float> pos;
	my_color rgb;

	float t_min, t_max;
	bool isPoint() { return (type == 0); }
	bool isDirectional() { return type == 1; }

private:
	int type;
};

#endif
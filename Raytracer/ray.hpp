#ifndef _RAY_H_
#define _RAY_H_

#include "vector.hpp"
#include "color.hpp"

const int _PL = 0;
const int _DL = 1;
const int _AL = 2;

class ray {

public:
	ray(): type(0) { };
	ray(const int &t): type(t) { }
	ray(const int &t, const my_vec<3, float> &p, const my_color &c): type(t), pos(p), rgb(c) { }
	my_vec<3, float> pos;
	my_color rgb;

	float t_min, t_max;
	/* Specific for ltp */
	float falloff;

	bool isPoint() { return (type == _PL); }
	bool isDirectional() { return (type == _DL); }
	bool isAmbient() { return (type == _AL); }

	void report() {
		std::cout << "color: ";
		rgb.report();
		std::cout << "pos: ";
		pos.report();
	}

private:
	int type;
};

#endif
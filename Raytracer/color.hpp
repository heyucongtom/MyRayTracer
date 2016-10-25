#ifndef _MY_COLOR_
#define _MY_COLOR_

#include "vector.hpp"


/* rgb should be set 1/255 and as float */
class my_color {
public:
	my_color() {
		for (int i = 0; i < 3; ++i) { d[i] = 0; }
	}

	my_color(const float rhs[3]) {
		for (int i = 0; i < 3; ++i) { d[i] = rhs[i]; }
	}

	my_color(const my_vec<3, float> &rhs) {
		for (int i = 0; i < 3; ++i) { d[i] = rhs[i]; }
	}
	
	my_color(const my_color &rhs) {
		for (int i = 0; i < 3; ++i) { d[i] = rhs.d[i]; }
	}

	float getR() { return d[0]; }
	float getG() { return d[1]; }
	float getB() { return d[2]; }
	void setR(float value) { d[0] = value; }
	void setG(float value) { d[1] = value; }
	void setB(float value) { d[2] = value; }

	/* Only element-wise multiplication make sense for colors */
	friend my_color
	operator*(const my_color &lhs, const my_color &rhs) {
		my_vec<3, float> tmp(my_mult_e(lhs.d, rhs.d));
		return my_color(tmp);
	}

	friend my_color
	operator*(const my_color &lhs, float rhs) {
		my_vec<3, float> tmp(lhs.d * rhs);
		return my_color(tmp);
	}

	void report() { d.report(); }

	float& operator[](int i) { return d[i]; }

private:
	my_vec<3, float> d;
};

#endif
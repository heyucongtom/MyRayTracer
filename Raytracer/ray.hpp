#include "vector.hpp"

class ray {

public:
	ray();
	my_vec<3, float> pos;
	my_color rgb;

	float t_min, t_max;
};
#include "vector.hpp"

class Camera {
public:
	Camera() { };
	my_vec<3, float> eye_pos;
	my_vec<3, float> ll;
	my_vec<3, float> lr;
	my_vec<3, float> ul;
	my_vec<3, float> ur;

	void report() {
		std::cout << "eye: " << std::endl;
		eye_pos.report();
		ll.report();
		lr.report();
		ul.report();
		ur.report();
	}
};
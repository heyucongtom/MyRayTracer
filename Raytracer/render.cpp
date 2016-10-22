#include "vector.hpp"
#include "shapes.hpp"
#include <vector>
#include "task.hpp"

std::vector<float> render_sphere() {
	Task t;
	Sphere s1;
	my_vec<3, float> viewer;
	return std::vector<float>(0);
}

int main(int argc, char *argv[]) {
	Task t;
	int i = 0;
	while (i < argc) {
		printf("%s\n", argv[i]);
    	if (strcmp(argv[i], "sph") == 0) {
    		t.shape = std::make_shared<Sphere>();
    		std::shared_ptr<Sphere> p = std::dynamic_pointer_cast<Sphere>(t.shape);
    		(p->center)[0] = atof(argv[i+1]);
    		(p->center)[1] = atof(argv[i+2]);
    		(p->center)[2] = atof(argv[i+3]);
    		p->radius = atof(argv[i+4]);
    	}
    	++i;
    }
    std::shared_ptr<Sphere> p = std::dynamic_pointer_cast<Sphere>(t.shape);
    std::cout << p->radius << std::endl;
    p->center.report();

}
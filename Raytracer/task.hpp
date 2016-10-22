#include "ray.hpp"
#include <memory>
#include <vector>
#include "shapes.hpp"

class Task {
public:
	std::vector<ray> lightSources;
    my_vec<3, float> viewer;
    std::shared_ptr<Shape> shape;

	Task() { }
	Task(std::shared_ptr<Shape> s) {
		shape = std::move(s);
	}
    Shape* getShape() {
    	return shape.get();
    }
};

void parseFloatCmd(char *argv[], int argc, Task &t) {
    int i = 0;
    /* Initialize shape first */
    while (i < argc) {
    	if (strcmp(argv[i], "sph") == 0) {
    		t.shape = std::make_shared<Sphere>();
    		std::shared_ptr<Sphere> p = std::dynamic_pointer_cast<Sphere>(t.shape);
    		(p->center)[0] = atof(argv[i+1]);
    		(p->center)[1] = atof(argv[i+2]);
    		(p->center)[2] = atof(argv[i+3]);
    		p->radius = atof(argv[i+4]);
    	}
    	// if (strcmp(argv[i], "tri") == 0) {
    	// 	t.shape = std::make_shared<Triangle>();
    	// 	std::shared_ptr<Triangle> p = std::dynamic_pointer_cast<Triangle>(t.shape);
    		
    	// }
    	++i;
    }

    i = 0;
    while (i < argc) {
        if (strcmp(argv[i], "-ka") == 0) {
            my_vec<3, float> &ka = t.shape->ka;
            ka[0] = atof(argv[i+1]);
            ka[1] = atof(argv[i+2]);
            ka[2] = atof(argv[i+3]);
        }
        if (strcmp(argv[i], "-ks") == 0) {
            my_vec<3 ,float> &ks = t.shape->ks;
            ks[0] = atof(argv[i+1]);
            ks[1] = atof(argv[i+2]);
            ks[2] = atof(argv[i+3]);
        }
        if (strcmp(argv[i], "-kd") == 0) {
            my_vec<3 ,float> &kd = t.shape->kd;
            kd[0] = atof(argv[i+1]);
            kd[1] = atof(argv[i+2]);
            kd[2] = atof(argv[i+3]);
        }
        if (strcmp(argv[i], "-kr") == 0) {
            my_vec<3 ,float> &kr = t.shape->kr;
            kr[0] = atof(argv[i+1]);
            kr[1] = atof(argv[i+2]);
            kr[2] = atof(argv[i+3]);
        }
        if (strcmp(argv[i], "-spu") == 0) {
            t.shape->spu = atof(argv[i+1]);
        }
        if (strcmp(argv[i], "-spv") == 0) {
            t.shape->spv = atof(argv[i+1]);
        }
        if (strcmp(argv[i], "-sp") == 0) {
            t.shape->sp = atof(argv[i+1]);
        }
        // if (strcmp(argv[i], "-pl") == 0) {
        //     PointLight pl;
        //     pl.pos.x = atof(argv[i+1]);
        //     pl.pos.y = atof(argv[i+2]);
        //     pl.pos.z = atof(argv[i+3]);
        //     pl.rgb.assign(atof(argv[i+4]), atof(argv[i+5]), atof(argv[i+6]));
        //     t.lightSources.push_back(pl);
        // }
        // if (strcmp(argv[i], "-dl") == 0) {
        //     DirLight dl;
        //     dl.pos.x = atof(argv[i+1]);
        //     dl.pos.y = atof(argv[i+2]);
        //     dl.pos.z = atof(argv[i+3]);
        //     dl.rgb.assign(atof(argv[i+4]), atof(argv[i+5]), atof(argv[i+6]));
        //     t.lightSources.push_back(dl);
        // }
        ++i;
    }
}
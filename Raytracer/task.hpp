#include "ray.hpp"
#include <memory>
#include <vector>
#include "shapes.hpp"
#include "camera.hpp"

class Task {
public:
	std::vector<ray> lightSources;
    my_vec<3, float> viewer;
    std::vector<std::shared_ptr<Shape> > shapes;
    Camera c;

	Task() { }
	// Task(std::shared_ptr<Shape> s) {
	// 	shape = std::move(s);
	// }
 //    Shape* getShape() {
 //    	return shape.get();
 //    }

    void report() {
        std::cout << "Lights: " << std::endl;
        for (int i = 0; i < lightSources.size(); ++i) {
            ray r = lightSources[i];
            r.report();
        }
        std::cout << "Camera: " << std::endl;
        c.report();
        std::cout << "Shape: " << std::endl;
        for (int i = 0; i < shapes.size(); ++i) {
            std::shared_ptr<Shape> shape = shapes[i];
            shape->report();
        }
    }
};

void parseObj(char *file_name) {
    return; // * not implemented *
}

void parseFloatCmd(char *argv[], int argc, Task &t) {
    int i = 0;
    /* Initialize shape first */
    while (i < argc) {
        /* Specify Sphere */
        int pos = t.shapes.size(); 

        // material.
        if (strcmp(argv[i], "mat") == 0) {
            int pos = t.shapes.size();
            std::shared_ptr<Shape> shape = t.shapes[pos - 1];
            my_color &ka = shape->ka;
            ka[0] = atof(argv[i+1]);
            ka[1] = atof(argv[i+2]);
            ka[2] = atof(argv[i+3]);
            my_color &ks = shape->ks;
            ks[0] = atof(argv[i+4]);
            ks[1] = atof(argv[i+5]);
            ks[2] = atof(argv[i+6]);
            my_color &kd = shape->kd;
            kd[0] = atof(argv[i+7]);
            kd[1] = atof(argv[i+8]);
            kd[2] = atof(argv[i+9]);
            my_color &kr = shape->kr;
            kr[0] = atof(argv[i+10]);
            kr[1] = atof(argv[i+11]);
            kr[2] = atof(argv[i+12]);
        }

        if (strcmp(argv[i], "sph") == 0) {
            std::shared_ptr<Shape> shape = std::make_shared<Sphere>();
            std::shared_ptr<Sphere> p = std::dynamic_pointer_cast<Sphere>(shape);
            (p->center)[0] = atof(argv[i+1]);
            (p->center)[1] = atof(argv[i+2]);
            (p->center)[2] = atof(argv[i+3]);
            p->radius = atof(argv[i+4]);
            t.shapes.push_back(shape);
        }
        /* Specify Triangle */
        if (strcmp(argv[i], "tri") == 0) {
            std::shared_ptr<Shape> shape = std::make_shared<Triangle>();
            std::shared_ptr<Triangle> p = std::dynamic_pointer_cast<Triangle>(shape);
            (p->pa)[0] = atof(argv[i+1]);
            (p->pa)[1] = atof(argv[i+2]);
            (p->pa)[2] = atof(argv[i+3]);
            (p->pb)[0] = atof(argv[i+4]);
            (p->pb)[1] = atof(argv[i+5]);
            (p->pb)[2] = atof(argv[i+6]);
            (p->pc)[0] = atof(argv[i+7]);
            (p->pc)[1] = atof(argv[i+8]);
            (p->pc)[2] = atof(argv[i+9]);
            t.shapes.push_back(shape);
        }
        ++i;
    }

    i = 0;
    while (i < argc) {
        /* Camera, only one */
        if (strcmp(argv[i], "cam") == 0) {
            Camera &c = t.c;
            c.eye_pos[0] = atof(argv[i+1]);
            c.eye_pos[1] = atof(argv[i+2]);
            c.eye_pos[2] = atof(argv[i+3]);
            c.ll[0] = atof(argv[i+4]);
            c.ll[1] = atof(argv[i+5]);
            c.ll[2] = atof(argv[i+6]);
            c.lr[0] = atof(argv[i+7]);
            c.lr[1] = atof(argv[i+8]);
            c.lr[2] = atof(argv[i+9]);
            c.ul[0] = atof(argv[i+10]);
            c.ul[1] = atof(argv[i+11]);
            c.ul[2] = atof(argv[i+12]);
            c.ur[0] = atof(argv[i+13]);
            c.ur[1] = atof(argv[i+14]);
            c.ur[2] = atof(argv[i+15]);
        }

        // if (strcmp(argv[i], "-spu") == 0) {
        //     t.shape->spu = atof(argv[i+1]);
        // }
        // if (strcmp(argv[i], "-spv") == 0) {
        //     t.shape->spv = atof(argv[i+1]);
        // }
        // if (strcmp(argv[i], "-sp") == 0) {
        //     t.shape->sp = atof(argv[i+1]);
        // }

        /* Specify rays */
        // Ambient;
        if (strcmp(argv[i], "lta") == 0) {
            ray r(_AL);
            r.rgb[0] = atof(argv[i+1]);
            r.rgb[1] = atof(argv[i+2]);
            r.rgb[2] = atof(argv[i+3]);
            t.lightSources.push_back(r);
        }

        // Directional
        if (strcmp(argv[i], "ltd") == 0) {
            ray r(_DL);
            r.pos[0] = atof(argv[i+1]);
            r.pos[1] = atof(argv[i+2]);
            r.pos[2] = atof(argv[i+3]);
            r.rgb[0] = atof(argv[i+4]);
            r.rgb[1] = atof(argv[i+5]);
            r.rgb[2] = atof(argv[i+6]);
            t.lightSources.push_back(r);
        }

        // Point
        if (strcmp(argv[i], "ltp") == 0) {
            ray r(_PL);
            r.pos[0] = atof(argv[i+1]);
            r.pos[1] = atof(argv[i+2]);
            r.pos[2] = atof(argv[i+3]);
            r.rgb[0] = atof(argv[i+4]);
            r.rgb[1] = atof(argv[i+5]);
            r.rgb[2] = atof(argv[i+6]);
            if (!(isalpha(argv[i+1][0]))) {
                r.falloff = atof(argv[i+7]);
            }
            t.lightSources.push_back(r);
        }
        ++i;
    }
}
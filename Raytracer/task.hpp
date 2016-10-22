#include "ray.hpp"

class Task {
public:
    vector<ray> lightSources;
    my_vec<3, float> viewer;
    Shape shape;
};

class Primitive {
    virtual intersect
}
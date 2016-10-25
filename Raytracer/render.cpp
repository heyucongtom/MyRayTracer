#include "vector.hpp"
#include "shapes.hpp"
#include <vector>
#include "task.hpp"
#include <fstream>

const int ARGS_NUM = 1024;
const int ARGS_SIZE = 64;

Task parse_obj_file(std::string filename) {
    std::ifstream file;
    file.open(filename);

    std::string word;
    int argc = 0;
    /* Using stack would be fine here. */
    char **argv = (char **) malloc (ARGS_NUM * sizeof(char));
    while (file >> word) {
        argv[argc] = (char*) malloc ((word.size() + 1) * sizeof(char));
        strncpy(argv[argc], word.c_str(), word.size());
        ++argc;  
    }
    Task t;
    parseFloatCmd(argv, argc, t);
    t.report();
    return t;
}

std::vector<float> render_sphere() {
	Task t;
	Sphere s1;
	my_vec<3, float> viewer;
	return std::vector<float>(0);
}

int main() {
    std::string obj_file_name = "./tests/obj_test_1";
    Task t(parse_obj_file(obj_file_name));
}
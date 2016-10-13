#include "../png_out.hpp"
#include <cstdlib>


int main() {
	int height = 510;
	int width = 510;
	std::string file_name("test1");
	std::vector<my_color> pixels(height * width);
	for (int i = 0; i < width * height; ++i) {
		my_color tmp;
		for (int j = 0; j < 3; ++j) {
			int v1 = i % 255;
			float r1 = v1 / 255.0;
			tmp[j] = r1;
		}
		pixels[i] = tmp;
	}

	write_img_rgb8_to_file(height, width, file_name, pixels);
}
#define png_infopp_NULL (png_infopp)NULL
#define int_p_NULL (int*)NULL
#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_dynamic_io.hpp>
#include <assert.h>
#include <string>
#include "color.hpp"

using namespace boost::gil;

const int HEIGHT = 500;
const int WIDTH = 500;

/* Pass in a rgb vector and save it as a png */
void write_img_rgb8_to_file(const int height, const int width, 
						const std::string &file_name, const std::vector<my_color> &pixels) {
	assert (height * width == pixels.size());
	rgb8_image_t img (width, height);
	rgb8_image_t::view_t v = view(img);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			my_color tmp = pixels[i * width + j];
			float r = tmp.getR() * 255.0;
			float g = tmp.getG() * 255.0;
			float b = tmp.getB() * 255.0;
			rgb8_pixel_t t(r, g, b);
			v(i, j) = t;
		}
	}
	png_write_view(file_name, const_view(img));
}
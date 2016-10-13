#define png_infopp_NULL (png_infopp)NULL
#define int_p_NULL (int*)NULL
#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_dynamic_io.hpp>
#include <assert.h>
#include <string>
#include "../color.hpp"

using namespace boost::gil;

const int HEIGHT = 500;
const int WIDTH = 500;
int main()
{
    rgb8_image_t img(255, 255);
    
    for (int i = 0; i < 255; ++i) {
    	rgb8_pixel_t t(i, 255-i, 0);
    	rgb8_image_t::view_t v = view(img);
    	v(i, 255-i) = t;
    }
    png_write_view("redsquare.png", const_view(img));
}

/* Pass in a rgb vector and save it as a png */
void write_img_rgb8_to_file(const int height, const int width, 
						const std::string file_name, const std::vector<my_color> &pixels) {
	assert (height * width == pixels.size());
	rgb8_image_t img (width, height);
	rgb8_image_t::view_t v = view(img);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			float r = pixels[i * width + j].getR() * 255.0;
			float g = pixels[i * width + j].getG() * 255.0;
			float b = pixels[i * width + j].getB() * 255.0;
			rgb8_pixel_t t(r, g, b);
			view(i, j) = t;
		}
	}
	png_write_view(file_name, const_view(img));
}
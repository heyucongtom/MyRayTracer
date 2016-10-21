#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>

#include "../vector.hpp"

BOOST_AUTO_TEST_CASE(first_test) {
	int i = 1;
	BOOST_TEST(i);
	BOOST_TEST(i == 1);
}

BOOST_AUTO_TEST_CASE(vector_plus) {
	float test_arr[3] = {1.0, 2.0, 3.0};
	my_vec<3, float> vec1(test_arr);
	my_vec<3, float> vec2(vec1);
	vec1 += vec2;
	BOOST_TEST(vec1[0] == 2.0);
	BOOST_TEST(vec1[1] == 4.0);
	BOOST_TEST(vec1[2] == 6.0);
}

BOOST_AUTO_TEST_CASE(vector_norm) {
	float test_arr[3] = {3.0, 4.0, 0.0};
	my_vec<3, float> vec1(test_arr);
	my_vec<3, float> res = vec1.vec_normal();
	BOOST_TEST(abs(res[0] - 0.6) < 0.00001);
	BOOST_TEST(abs(res[1] - 0.8) < 0.00001);
}
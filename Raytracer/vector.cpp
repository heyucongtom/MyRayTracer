#ifndef _MY_VEC_H_
#define _MY_VEC_H_
/*
 * Name my_vec
 *
 * Credited: implimentation of patrick Moran, pmoran@nas.nasa.gov *
 * This is a student imitated version of C++ vector design
 *
*/

#include <iostream>
#include <math.h>

template <int N, typename T> class my_vec;

template <typename T>
struct vec_traits {
	typedef T element_type;
};

template <int N, typename T>
struct vec_traits<my_vec<N, T>> {
	typedef typename vec_traits<T>::element_type element_type;
};

/* Declaration, signatures */
template <int N, typename T>
T my_dot(const my_vec<N, T>&, const my_vec<N, T>&);

template <typename T>
my_vec<3, T> my_cross(const my_vec<3, T>&, const my_vec<3, T>&);

template <int N, typename T>
class my_vec {
public:
	my_vec() {}
	my_vec(const T dat[]) {
		for (int i = 0; i < N; ++i) {
			d[i] = dat[i];
		}
	}
	template <typename S>
	explicit my_vec(const my_vec<N, S> &dat) {
		for (int i = 0; i < N; ++i) {
			d[i] = (T) dat[i];
		}
	}

	/* Element getter */
	T& operator[](int i) { return d[i]; }

	operator const T*() const {
		return (typename vec_traits<T>::element_type*) d;
	}


	/* Operator overloading for vectors */
	friend bool
	operator==(const my_vec<N, T> &lhs, const my_vec &rhs) {
		bool res = true;
		for (int i = 0; i < N; ++i) {
			if (!lhs[i] == rhs[i]) {
				res = false;
				break;
			}
		}
		return res;
	}

	my_vec<N, T>& operator+=(const my_vec<N, T> &v) {
		for (int i = 0; i < N; ++i) {
				d[i] += v[i];
			}
			return *this;
		}

	my_vec<N, T>& operator -=(const my_vec<N, T> &v) {
		for (int i = 0; i < N; ++i) {
			d[i] -= v[i];
		}
		return *this;
	}

	my_vec<N, T>& operator *=(typename vec_traits<T>::element_type s) {
		for (int i = 0; i < N; ++i) {
			d[i] *= s;
		}
		return *this;
	}

	my_vec<N, T>& operator /=(typename vec_traits<T>::element_type s) {
		for (int i = 0; i < N; ++i) {
			d[i] /= s;
		}
		return *this;
	}

	friend my_vec<N, T> 
	operator+(const my_vec<N, T> &lhs, const my_vec<N, T> &rhs) {
		T tmp[N];
		for (int i = 0; i < N; ++i) {
			tmp[i] = lhs[i] + rhs[i];
		}
		return my_vec(tmp);
	}

	friend my_vec<N, T> 
	operator-(const my_vec<N, T> &lhs, const my_vec<N, T> &rhs) {
		T tmp[N];
		for (int i = 0; i < N; ++i) {
			tmp[i] = lhs[i] - rhs[i];
		}
		return my_vec<N, T>(tmp);
	}

	friend my_vec<N, T>
	operator*(typename vec_traits<T>::element_type lhs, const my_vec<N, T> &rhs) {
		T tmp[N];
		for (int i = 0; i < N; ++i) {
			tmp[i] = lhs * rhs[i];
		}
		return my_vec<N, T>(tmp);
	}

	friend my_vec<N, T>
	operator*(const my_vec<N, T> &lhs, typename vec_traits<T>::element_type &rhs) {
		T tmp[N];
		for (int i = 0; i < N; ++i) {
			tmp[i] = lhs[i] * rhs;
		}
		return my_vec<N, T>(tmp);
	}
private:
	T d[N];
};

#endif


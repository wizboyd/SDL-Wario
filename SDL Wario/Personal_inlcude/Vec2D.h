#pragma once

#include <iostream>

template <typename T>
struct Vec2D
{
	T x, y; // declares variables of type T

	Vec2D() {
		this->x = 0;
		this->y = 0;
	}

	Vec2D(T x, T y) {
		this->x = x;
		this->y = y;
	}

	inline Vec2D<T> operator+(const Vec2D<T>& V2) const {
		return Vec2D<T>(x + V2.x, y + V2.y); // increases the referenced V2 x and y postion;
	}

	inline friend Vec2D<T>& operator+=(Vec2D<T>& v1, const Vec2D<T>& v2) {
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}

	inline Vec2D<T> operator-(const Vec2D<T>& v2) const {
		return Vec2D<T>(x - v2.x, y - v2.y);
	}

	inline friend Vec2D<T>& operator-=(Vec2D<T>& v1, const Vec2D<T>& v2) {
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}

	inline Vec2D<T> operator*(const T scalar) const {
		return Vec2D<T>(x * scalar, y * scalar);
	}

	inline Vec2D<T> operator/(const T divide) const {
		return(divide != 0 ? Vec2D<T>(x / divide, y / divide) : Vec2D<T>());
	}

	inline Vec2D<T>& zero() {
		this->x = 0;
		this->y = 0;
		return *this;
	}

	inline Vec2D<T>& ones() {
		this->x = 1;
		this->y = 1;
		return *this;
	}

	inline friend std::ostream& operator<<(std::ostream& stream, const Vec2D<T>& v) {
		stream << "(" << v.x << "," << v.y << ")";
		return stream;
	}

};

using Vec2DI = Vec2D<int>;
using Vec2DIU = Vec2D<unsigned int>;
using Vec2DF = Vec2D<float>;
using Vec2Dd = Vec2D<double>;

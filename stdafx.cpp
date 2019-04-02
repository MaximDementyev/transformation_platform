#include "stdafx.h"

Vector3 operator + (const  Vector3 &a, const  Vector3 &b) {
	return  Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}
Vector3 operator+(const Vector3 &a, double b) {
	return Vector3(a.x + b, a.y + b, a.z + b);
}
Vector3 operator - (const  Vector3 &a, const  Vector3 &b) {
	return  Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}
Vector3 operator-(const Vector3 &a, double b) {
	return Vector3(a.x - b, a.y - b, a.z - b);
}
Vector3 operator - (const  Vector3 &a) {
	return  Vector3(-a.x, -a.y, -a.z);
}
Vector3 operator * (const  Vector3 &a, const double b) {
	return  Vector3(a.x * b, a.y * b, a.z * b);
}
Vector3 operator * (const double b, const  Vector3 &vec) {
	return  Vector3(vec.x * b, vec.y * b, vec.z * b);
}
Vector3 operator * (const  Vector3 &a, const  Vector3 &b) {
	return  Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}
Vector3 operator / (const  Vector3 &vec, const double b) {
	return Vector3(vec.x / b, vec.y / b, vec.z / b);
}
Vector3 operator += (Vector3 &vec1, const Vector3 &vec2) {
	return Vector3(vec1 = vec1 + vec2);
}
Vector3 operator -= (Vector3 &vec1, const Vector3 &vec2) {
	return Vector3(vec1 = vec1 - vec2);
}
Vector3 operator *= (Vector3 &vec, const double b) {
	return  Vector3(vec = vec * b);
}
Vector3 operator /= (Vector3 &vec, const double b) {
	return  Vector3(vec = vec / b);
}
::Vector3 Vector3::operator-() {
	return Vector3(-this->x, -this->y, -this->z);
}

double & Vector3::operator[](int pos) {
	switch (pos) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		default: return x;
	}
}

platf_angl operator + (const  platf_angl &a, const  platf_angl &b) {
	return  platf_angl(a.kappa + b.kappa, a.chi + b.chi, a.psi + b.psi);
}
platf_angl operator - (const  platf_angl &a, const  platf_angl &b) {
	return  platf_angl(a.kappa - b.kappa, a.chi - b.chi, a.psi - b.psi);
}
platf_angl operator*(double b, const platf_angl &vec) {
	return platf_angl(vec.kappa * b, vec.chi * b, vec.psi * b);
}
platf_angl operator*(const platf_angl &vec, double b) {
	return platf_angl(vec.kappa * b, vec.chi * b, vec.psi * b);
}
platf_angl operator/(const platf_angl &vec, double b) {
	return platf_angl(vec.kappa / b, vec.chi / b, vec.psi / b);
}
platf_angl operator+=(platf_angl &vec1, const platf_angl &vec2) {
	return platf_angl(vec1 = vec1 + vec2);
}
platform operator+(const platform &a, const platform &b) {
	return platform(a.pos + b.pos, a.ang + b.ang);
}
platform operator-(const platform &a, const platform &b) {
	return platform(a.pos - b.pos, a.ang - b.ang);
}
platform operator += (platform &vec1, const platform &vec2) {
	return platform(vec1 = vec1 + vec2);
}
platform operator/(const platform &a, double b) {
	return platform(a.pos / b, a.ang / b);
}

double & platf_angl::operator[](int pos) {
	switch (pos) {
		case 0: return kappa;
		case 1: return chi;
		case 2: return psi;
		default: return kappa;
	}
}


engine_position operator+(const engine_position &a, double b) {
	return engine_position(a.x + b, a.y + b, a.z + b);
}
::engine_position engine_position::operator-() {
	return engine_position(-this->x, -this->y, -this->z);
}
engine_position operator / (const  engine_position &vec, const double b) {
	return engine_position(vec.x / b, vec.y / b, vec.z / b);
}
engine_position operator * (const  engine_position &a, const double b) {
	return  engine_position(a.x * b, a.y * b, a.z * b);
}
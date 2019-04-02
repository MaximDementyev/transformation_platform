#pragma once
#define WIN32_LEAN_AND_MEAN 
#include <cstdio>
#include <windows.h>
#define _USE_MATH_DEFINES

struct Vector3 {
	double x;
	double y;
	double z;
	Vector3() { x = 0; y = 0; z = 0; }
	Vector3(double nx, double ny, double nz) { x = nx; y = ny; z = nz; }
	void set0() { x = 0; y = 0; z = 0; };
	double &operator[] (int);
	friend  Vector3 operator + (const  Vector3 &, const  Vector3 &);
	friend  Vector3 operator + (const  Vector3 &, double);
	friend  Vector3 operator - (const  Vector3 &, const  Vector3 &);
	friend  Vector3 operator - (const  Vector3 &, double);
	friend  Vector3 operator * (const  Vector3 &, double);
	friend  Vector3 operator * (double, const  Vector3 &);
	friend  Vector3 operator * (const  Vector3 &, const  Vector3 &);
	friend  Vector3 operator / (const  Vector3 &, double);
	friend  Vector3 operator += (Vector3 &, const  Vector3 &);
	friend  Vector3 operator -= (Vector3 &, const  Vector3 &);
	friend  Vector3 operator *= (Vector3 &, double);
	friend  Vector3 operator /= (Vector3 &, double);
	::Vector3 operator-();
};

struct platf_angl {
	double kappa;
	double chi;
	double psi;
	platf_angl() { kappa = 0; chi = 0; psi = 0; }
	platf_angl(double nx, double ny, double npsi) { kappa = nx; chi = ny; psi = npsi; }
	void set(double nx, double ny) { kappa = nx; chi = ny; }
	void set0() { kappa = 0; chi = 0; psi = 0; }
	double &operator[] (int);
	friend  platf_angl operator + (const  platf_angl &, const  platf_angl &);
	friend  platf_angl operator - (const  platf_angl &, const  platf_angl &);
	friend  platf_angl operator * (double, const  platf_angl &);
	friend  platf_angl operator * (const  platf_angl &, double);
	friend  platf_angl operator / (const  platf_angl &, double);
	friend  platf_angl operator += (platf_angl &, const  platf_angl &);
};

struct platform {
	Vector3 pos;
	platf_angl ang;
	platform() { pos = Vector3(); ang = platf_angl(); };
	platform(Vector3 npos, platf_angl nang) { pos = npos; ang = nang; }
	void set0() { pos.set0(); ang.set0(); }
	friend platform operator + (const  platform &, const  platform &);
	friend platform operator - (const  platform &, const  platform &);
	friend  platform operator += (platform &, const  platform &);
	friend  platform operator / (const  platform &, double);
};

struct engine_position {
	double x;
	double y;
	double z;
	engine_position() { x = 0; y = 0; z = 0; }
	engine_position(double nx, double ny, double nz) { x = nx; y = ny; z = nz; }
	friend  engine_position operator + (const  engine_position &, double);
	friend  engine_position operator / (const  engine_position &, double);
	friend  engine_position operator * (const  engine_position &, double);
	::engine_position operator-();
};
#pragma once
#include <cmath>
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

using namespace std;
const double L = 380.0;
const double r = 110.0;
const double a = 330.0;
const double c = 410.0;
const double s = 260.0;
const double shift = 380;
const double bad_value = -10;

platform border_set(const double a, const double b, const double c);
engine_position build(const platform *plat, const platform *constraints);
double accessory(double m, double j, double k, int flag);


inline engine_position round(const engine_position &vec);
engine_position dimensional_transform(const engine_position vec, int size_factor);
engine_position rotation_engine_names(engine_position vec);

template <typename T>
int sign(T x) {
	if (x > 0) return 1;
	return -1;
};
#include "stdafx.h"
#include "full_bd.h"
#include "Header.h"
#include <iostream>
using namespace std;
const platform koef_norm = platform(Vector3(0, 0, 110), platf_angl(19.2, 20.1, 0));


extern "C" __declspec(dllexport) void set_construction(full_bd* bd, platform *con){
	bd->constraction = border_set(0, 0, 0);
	*con = bd->constraction;
}

platform border_set(const double a, const double b, const double c) {
	const auto kappa = 0.00008708904855214457 * (4950 + 7655 * a - 5169 * b - 5087 * c);
	const auto chi = 0.000032243502934158766 * (9900 - 7655 * a + 20676 * b - 10174 * c);
	const auto z = 0.000032763252735731606 * (9900 - 7655 * a - 10338 * b + 20348 * c);
	return platform(Vector3(0, 0, z*koef_norm.pos.z), (platf_angl(kappa*koef_norm.ang.kappa, chi*koef_norm.ang.chi, 0) / 180. * M_PI));
}
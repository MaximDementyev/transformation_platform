#include "stdafx.h"
#include "Header.h"
#include "full_bd.h"

extern "C" __declspec(dllexport) void* start() {//создание внутренних структур
	full_bd* bd =new full_bd();;
	bd->constraction = border_set(0, 0, 0);
	return bd;
}

extern "C" __declspec(dllexport) void finish(full_bd *bd) {//освобождение памяти
	if (bd != nullptr) delete bd;
	bd = nullptr;
}


extern "C" __declspec(dllexport) void transform(full_bd* bd, platform *plat, engine_position *ans) {//преобразование положения платформы в положение двигателей
	auto final_engines = build(plat, &bd->constraction); // преобразуем углы наклона в положения двигателей
	auto res = dimensional_transform(final_engines, bd->size_factor); //преобразуем положения двигателя коэффициенты управления
	res = (rotation_engine_names(res)); // замена расположений двигателей 
	*ans = res;
}

engine_position dimensional_transform(engine_position vec, int size_factor) {
	return engine_position(round((-vec + 1.) / 2. * size_factor));
}

engine_position rotation_engine_names(engine_position vec) {
	const auto tmp = vec.x;
	vec.x = vec.z;
	vec.z = tmp;
	return vec;
}

inline engine_position round(const engine_position &vec) {
	return engine_position(round(vec.x), round(vec.y), round(vec.z));
}
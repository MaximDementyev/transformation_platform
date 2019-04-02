#include "stdafx.h"
#include "Header.h"

engine_position build(const platform *plat, const platform *constraints) {
	engine_position position;
	const auto kappa = -plat->ang.kappa;
	const auto chi = -plat->ang.chi;
	auto h = -plat->pos.z + L;
	if (fabs(plat->pos.z) > constraints->pos.z) {
		h = constraints->pos.z * sign(plat->pos.z) + L;
	}

	auto flag_solve = true;
	//A
	auto Ax = -2 * a*cos(chi)*sin(chi)*sin(kappa) + s * cos(kappa);
	auto Ay = -s * sin(kappa)*sin(chi) - a * (cos(chi)*(cos(kappa)*pow(sin(chi), 2) + pow(cos(chi), 2)) - sin(chi)*(-cos(chi)*cos(kappa)*sin(chi) + cos(chi)*sin(chi)));
	auto Az = s * sin(kappa)*cos(chi) - a * (cos(chi)*(-cos(chi)*cos(kappa)*sin(chi) + cos(chi)*sin(chi)) - sin(chi)*(pow(cos(chi), 2) * cos(kappa) + pow(sin(chi), 2)));
	//������ �� �������
	auto m = s - Ax;
	auto j = -a - Ay;
	auto k = h - Az;
	auto solve = accessory(m, j, k, 1);//��������� ������� �������
	if (solve > bad_value + 1) position.x = solve;
	else flag_solve = false;

	if (flag_solve == true) {
		// B
		Ax = 2 * a*cos(chi)*sin(chi)*sin(kappa) + s * cos(kappa);
		Ay = -s * sin(kappa)*sin(chi) + a * (cos(chi)*(cos(kappa)*pow(sin(chi), 2) + pow(cos(chi), 2)) - sin(chi)*(-cos(chi)*cos(kappa)*sin(chi) + cos(chi)*sin(chi)));
		Az = s * sin(kappa)*cos(chi) + a * (cos(chi)*(-cos(chi)*cos(kappa)*sin(chi) + cos(chi)*sin(chi)) - sin(chi)*(pow(cos(chi), 2) * cos(kappa) + pow(sin(chi), 2)));
		//������ �� �������
		m = s - Ax;
		j = a - Ay;
		k = h - Az;
		solve = accessory(m, j, k, -1);//��������� ������� �������
		if (solve > bad_value + 1) position.y = solve;
		else flag_solve = false;

		if (flag_solve == true) {
			// C
			Ax = -c * cos(kappa);
			Ay = c * sin(kappa)*sin(chi);
			Az = -c * sin(kappa)*cos(chi);
			//������ �� �������
			m = -Ay;
			j = -c - Ax;
			k = h - Az;
			solve = accessory(m, j, k, 1);//��������� ������� �������
			if (solve > bad_value + 1) position.z = solve;
			else flag_solve = false;
		}
	}

	if (flag_solve == false) {
		//fprintf(log, "error build\n");
		//print_platform(log, &bd->now->plat);
	}
	return position;
}


double accessory(double m, double j, double k, int flag) {//���������� 1 � ������ ������������� ���� �� ������ �������; 
														  //0 - � ������ ���������� �������
	if (fabs(j) > 10e-9) {
		//������� ����������� ���������
		const auto G = -(m*m + j * j + k * k + r * r - L * L) / (2 * r);
		const auto A = k * k + j * j;
		const auto B = -2 * G*k;
		const auto C = G * G - j * j;
		auto D = B * B - 4 * A*C;

		if (D < 0) {
			if (fabs(D) < 10e-5) D = 0.0;
			else return bad_value;//������� ���
		}

		double x1 = (-B - sqrt(D)) / (2 * A);//������� x1
		if ((x1 >= -1) && (x1 <= 1)) {//�������� �� ���������� ��������
			if (flag*(-G + k * x1) / (j) >= -(1e-6)) //�������� ������� (*) - �� �������
				return x1;
		}
		double x2 = (-B + sqrt(D)) / (2 * A);//������� �2
		if ((x2 >= -1) && (x2 <= 1)) {//�������� �� ���������� ��������
			if (flag*(-G + k * x2) / (j) >= -(1e-6))//�������� ������� (*) - �� �������
				return x2;
		}
	} else {// ������� ��������� ���������
		const auto x0 = (-L * L + r * r + k * k + m * m) / (-2 * k*r);//�������
		if ((x0 >= -1) && (x0 <= 1))//�������� �� ���������� ��������
			return x0;
	}
	return bad_value;
}
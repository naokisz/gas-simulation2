#include <stdio.h>
#include "simulation.h"

struct gas {
	int velocity_x, velocity_y, velocity_z;
	int coordinate_x, coordinate_y, coordinate_z;
} gas_condition[];

double velocity;

int main(void) {

	/*速さの決定*/
	set_velocity(void);

	/*初期座標の決定*/
	set_coordinate(void);

	for(;;;) {

		/*直線接近判定*/
		detect_gas_molecule_collision(void);

		/*

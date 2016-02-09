#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simulation.h"

struct gas {
	int velocity_x, velocity_y, velocity_z;
	int coordinate_x, coordinate_y, coordinate_z;
} *gas_condition;

double velocity;
/*外積*/
double exterior_product_x, exterior_product_y, exterior_product_z, intercept;

int main(void) {

	int molecule1, molecule2;

	/*速さの決定*/
	set_velocity(void);

	/*初期座標の決定*/
	set_coordinate(void);

	for(;;) {

		/*平面方程式作成*/
		make_plane(molecule1, molecule2);

		/*分子接近判定*/
		detect_molecule_collision(void);
	}

	return 0;
}


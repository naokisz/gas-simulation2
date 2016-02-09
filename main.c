#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "simulation.h"


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


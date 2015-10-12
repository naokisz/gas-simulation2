#include <stdio.h>

#define R 8.314459848 // 気体定数
#define AIR_MASS 28.966
#define MAX_COORDINATE 22

int set_velocity(void) {

	int temperature = 300; // ケルビン
	double mass = AIR_MASS;

	/* ｐ＝√３ＲＴ/Ｍ＊10^3をしている。*/
	velocity = 3 * R * temperature;
	velocity /= mass * 0.001;
	velocity = sqrt(velocity);

	gas_condition.velocity_x = rand

	return 0;
}

int set_coordinate(void) {

	gas_condition.coordinate_x = rand() % MAX_COORDINATE;
	gas_condition.coordinate_y = rand() % MAX_COORDINATE;
	gas_condition.coordinate_z = rand() % MAX_COORDINATE;

	return 0;
}

int make_function(void) {
	


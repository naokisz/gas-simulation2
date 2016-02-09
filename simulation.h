#define R 8.314459848 // 気体定数
#define AIR_MASS 28.966
#define MAX_COORDINATE 22 // TODO ここの値正確にしたい randから弄る必要あるけど
/*TODO fmodを使って小数の割り算の余りを求められるからrandに活用*/
#define VAN_DEL_WAALS_RADIUS 1.55e-10

int set_velocity(void) {

	int temperature = 300; // ケルビン
	double mass = AIR_MASS;

	/* ｐ＝√３ＲＴ/Ｍ＊10^3をしている。*/
	/*TODO もっと正確な方法で決めたい。*/
	/*TODO 理想気体なのか普通の気体なのかごっちゃになってる*/
	/*TODO 気体の種類増やしたい*/
	velocity = 3 * R * temperature;
	velocity /= mass * 0.001;
	velocity = sqrt(velocity);

	/*球極座標を分かんないけど代入してる*/
	gas_condition->velocity_x = velocity * sin((rand() % 180) * M_PI / 180) * cos((rand() % 180) * M_PI / 180);
	gas_condition->velocity_y = velocity * sin((rand() % 180) * M_PI / 180) * sin((rand() % 180) * M_PI / 180);
	gas_condition->velocity_z = velocity * cos((rand() % 180) * M_PI / 180);


	return 0;
}

int set_coordinate(void) {

	gas_condition->coordinate_x = rand() % MAX_COORDINATE;
	gas_condition->coordinate_y = rand() % MAX_COORDINATE;
	gas_condition->coordinate_z = rand() % MAX_COORDINATE;

	return 0;
}

int make_plane(int molecule1, int molecule2) {

	/*XXX もう良く分からない*/
	exterior_product_x = gas_condition[molecule1]->velocity_y * gas_condition[molecule2]->velocity_z
		- gas_condition[molecule1]->velocity_z * gas_condition[molecule2]->velocity_y;

	exterior_product_y = gas_condition[molecule1]->velocity_z * gas_condition[molecule2]->velocity_x
		- gas_condition[molecule1]->velotity_x * gas_condition[molecule2]->velocity_z;

	exterior_product_z = gas_condition[molecule1]->velotity_x * gas_condition[molecule2]->velotity_y
		- gas_condition[molecule1]->velocity_y * gas_condition[molecule2]->velocity_x
velocity_x;

	intercept = (gas_condition[molecule1]->coordinate_x * -1 * exterior_product_x)
		+ (gas_condition[molecule1]->coordinate_y * -1 * exterior_product_y)
		+ (gas_condition[molecule1]->coordinate_z * -1 * exterior_product_z);
	
	return 0;
}

/*分子と分子の距離を測る*/
int detect_molecule_collision(void) {

	double distance;

	distance = fabs(exterior_product_x * gas_condition[molecule2]->coordinate_x
		+ exterior_product_y * gas_condition[molecule2]->coordinate_y
		+ exterior_product_z * gas_condition[molecule2]->coordinate_z + intercept) 
		/ sqrt(exterior_product_x * exterior_product_x + exterior_product_y * exterior_product_y
			exterior_product_z * exterior_product_z);

	if(distance < (VAN_DEL_WAALS_RADIUS * 2)) { collision(); } /*TODO 未定義*/
	else if(distance == (VAN_DEL_WAALS_RADIUS * 2)) { graze(); } /*TODO 未定義*/
	else { wall_collision(); }

	return 0;
}


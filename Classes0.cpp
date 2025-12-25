#include <iostream>
#include "Enemy.h"
#include "Demon.h"

int Enemy::health_mult = 2;
int Enemy::total_enem{};

static void bl() { std::cout << "\n"; }

int main() {
	Enemy* doobert = new Enemy(19, 61, "doobert");
	doobert->status();
	doobert->do_action(Enemy::act::attack);
	doobert->level_up(2);
	doobert->status();

	bl();

	Enemy* harold = new Demon(19, 67, "harold", 260);
	harold->status();
	harold->do_action(Enemy::act::demonic_blast);
	harold->level_up(5);
	harold->status();

	bl();

	std::cout << "Total enemies created: " << Enemy::total_enem << std::endl;
	bl();
	Print(doobert);
	Print(harold);

	delete doobert;
	delete harold;
}
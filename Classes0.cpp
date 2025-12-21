#include <iostream>
#include "Enemy.h"

int Enemy::health_mult = 2;
int Enemy::total_enem{};

void bl() { std::cout << "\n"; }

int main() {
	Enemy doobert(19, 61, "doobert");
	doobert.status();
	doobert.do_action(Enemy::act::attack);
	doobert.level_up(2);
	doobert.status();
	bl();
	Demon* harold = new Demon(19, 67, "harold", 260);
	harold->status();
	harold->do_action(Enemy::act::demonic_blast);
	harold->level_up(5);
	harold->status();
	bl();
	std::cout << "Total enemies created: " << Enemy::total_enem << std::endl;
	delete harold;
}
#pragma once
#include "Enemy.h"

class Demon : public Enemy{
private:
    int demonic_power;
public:

    Demon(int x, int y, const std::string& z, int w)
        : Enemy(x, y, z), demonic_power(w) {
    }

    std::string getClassName() const override {
        return "Demon";
    }

    void do_action(act x) override {
        if (x == act::demonic_blast) {
            std::cout << Enemy::get_name() << " used Demonic Blast!" << std::endl;
        }
        else {
            Enemy::do_action(x);
        }
    }

    void status() const override {
        Enemy::status();
        std::cout << "DP: " << demonic_power << std::endl;
    }
};
#pragma once
#include <string>

class Enemy {
private:
    std::string name;
    int health{};
    int strength{};
    int level{};
public:
    enum class act {
        attack, roar, defend, demonic_blast
    };

    static int total_enem;
    static int health_mult;

    Enemy(int x, int y, const std::string& z) 
        : health(x), strength(y), name(z) {
        total_enem++;
    }

    virtual void do_action(act x) {
        if (x == act::attack) {
            std::cout << name << " attacks!" << std::endl;
        }
        else if (x == act::defend) {
            std::cout << name << " defends!" << std::endl;
        }
        else if (x == act::roar) {
            std::cout << name << " roars!" << std::endl;
        }
        else {
            std::cout << name << " stands still!" << std::endl;
        }
    }

    void level_up(int x) {
        level += x;
        std::cout << name << " HAS LEVELED UP TO LEVEL " << level << std:: endl;
    }

    virtual void status() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "HP: " << health << std::endl;
        std::cout << "SP: " << strength << std::endl;
        std::cout << "LVL: " << level << std::endl;
    }

    std::string get_name() const {
        return name;
    }
};

class Demon : public Enemy {
private:
    int demonic_power;
public:

    Demon(int x, int y, const std::string& z, int w)
        : Enemy(x, y, z), demonic_power(w){}

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
        std::cout << "Demonic Power: " << demonic_power << std::endl;
    }
};
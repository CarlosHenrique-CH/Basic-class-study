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
        : health(x), strength(y), name(z) {total_enem++;}

    virtual ~Enemy() = default;

    virtual void do_action(act x) {
        switch (x) {
        case act::attack:
            std::cout << name << " has attacked!" << std::endl;
            break;
        case act::defend:
            std::cout << name << " defends!" << std::endl;
            break;
        case act::roar:
            std::cout << name << " roared!" << std::endl;
            break;
        default:
            std::cout << name << " stands still!" << std::endl;
            break;
        }
    }

    void level_up(int x) {
        level += x;
        std::cout << name << " HAS LEVELED UP TO LEVEL " << level << std:: endl;
    }

    virtual void status() const {
        std::cout << "Name: " << name << "\n"
        << "HP: " << health << "\n"
        << "SP: " << strength << "\n"
        << "LVL: " << level << std::endl;
    }

    std::string get_name() const {
        return name;
    }

};

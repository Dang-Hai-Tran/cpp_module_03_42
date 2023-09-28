#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include "Colors.h"
#include <iostream>
#include <string>

class ClapTrap {
  public:
    static int const defaultHitPoints = 10;
    static int const defaultEnergyPoints = 10;
    static int const defaultAttackDamage = 0;

    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &src);
    ~ClapTrap(void);

    ClapTrap &operator=(ClapTrap const &src);

    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;

    void attack(std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  private:
    ClapTrap(void);
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
};

#endif

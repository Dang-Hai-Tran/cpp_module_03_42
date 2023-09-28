#ifndef DIAMONDTRAP_CLASS_H
#define DIAMONDTRAP_CLASS_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
  public:
    DiamondTrap(DiamondTrap const &src);
    DiamondTrap(std::string name);
    ~DiamondTrap(void);

    DiamondTrap &operator=(DiamondTrap const &src);

    using ScavTrap::attack;

    void whoAmI(void);

  private:
    DiamondTrap(void);
    std::string _name;
};

#endif

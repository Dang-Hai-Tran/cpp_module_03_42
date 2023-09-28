#include "../incs/ClapTrap.hpp"
#include "../incs/DiamondTrap.hpp"
#include "../incs/FragTrap.hpp"
#include "../incs/ScavTrap.hpp"

int main(void) {
    std::string diamondTrapName = "DT-ooo";
    std::string scavTrapName = "SC-xxx";
    std::string clapTrapName = "CT-yyy";

    DiamondTrap diamondTrap(diamondTrapName);
    ScavTrap scavTrap(scavTrapName);
    ClapTrap clapTrap(clapTrapName);

    diamondTrap.whoAmI();
    clapTrap.attack(scavTrapName);
    scavTrap.takeDamage(clapTrap.getAttackDamage());
    scavTrap.attack(clapTrapName);
    clapTrap.takeDamage(scavTrap.getAttackDamage());
    diamondTrap.attack(scavTrapName);
    scavTrap.takeDamage(diamondTrap.getAttackDamage());
    diamondTrap.highFivesGuys();
    diamondTrap.guardGate();
    diamondTrap.takeDamage(5000);
    diamondTrap.beRepaired(5000);
    diamondTrap.whoAmI();
    return (0);
}

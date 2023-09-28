#include "../incs/ClapTrap.hpp"
#include "../incs/ScavTrap.hpp"

int main(void) {
    std::string scavTrapName = "SC-ooo";
    std::string clapTrapName = "CT-xxx";

    ScavTrap scavTrap(scavTrapName);
    ClapTrap clapTrap(clapTrapName);

    clapTrap.attack(scavTrapName);
    scavTrap.takeDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE);
    scavTrap.attack(clapTrapName);
    clapTrap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
    clapTrap.beRepaired(5000);
    scavTrap.guardGate();
    for (int i = 0; i < 50; i++)
        scavTrap.beRepaired(5000);
    scavTrap.attack(scavTrapName);
    scavTrap.takeDamage(5000);
    return (0);
}

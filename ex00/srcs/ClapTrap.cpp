#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _name("Default"), _hitPoints(ClapTrap::defaultHitPoints),
      _energyPoints(ClapTrap::defaultEnergyPoints),
      _attackDamage(ClapTrap::defaultAttackDamage) {
    std::cout << CYAN "ClapTrap default constructor called." RESET << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(ClapTrap::defaultHitPoints),
      _energyPoints(ClapTrap::defaultEnergyPoints),
      _attackDamage(ClapTrap::defaultAttackDamage) {
    std::cout << CYAN "A ClapTrap named \"" << name
              << "\" was constructed." RESET << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << CYAN "ClapTrap copy constructor called." RESET << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void) {
    std::cout << CYAN "The ClapTrap named \"" << this->_name
              << "\" was destroyed." RESET << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
    if (this != &src) {
        this->_name = src.getName();
        this->_hitPoints = src.getHitPoints();
        this->_energyPoints = src.getEnergyPoints();
        this->_attackDamage = src.getAttackDamage();
    }
    return (*this);
}

std::string ClapTrap::getName(void) const { return (this->_name); }

int ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

int ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
}

void ClapTrap::attack(std::string &target) {
    if (this->_hitPoints == 0) {
        std::cout << YELLOW "ClapTrap " << this->_name
                  << " can't attack: it is destroyed." RESET << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << YELLOW "ClapTrap " << this->_name
                  << " can't attack: its battery is depleted." RESET
                  << std::endl;
        return;
    }
    if (target == this->_name)
        target = "itself";
    this->_energyPoints--;
    std::cout << YELLOW "ClapTrap " << this->_name << " attacks " << target
              << " and hits for " << this->_attackDamage << " damage!" RESET
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout
            << RED "ClapTrap " << this->_name
            << " can't take anymore damage: it needs to be repaired!" RESET
            << std::endl;
        return;
    }
    if (this->_hitPoints < 0) {
        std::cout << RED << this->_name
                  << " can't take anymore damage: it was destroyed!" RESET
                  << std::endl;
        return;
    }
    if ((int)(this->_hitPoints - amount) < 0) {
        this->_hitPoints -= amount;
        std::cout << RED "ClapTrap " << this->_name << " takes " << amount
                  << " damage and is destroyed!" RESET << std::endl;
    } else {
        this->_hitPoints -= amount;
        std::cout << RED "ClapTrap " << this->_name << " takes " << amount
                  << " damage!" RESET << std::endl;
    }
    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << GREEN "ClapTrap " << this->_name
                  << " can't repair itself: it is too severely damaged." RESET
                  << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << GREEN "ClapTrap " << this->_name
                  << " can't repair itself: its battery is depleted and needs "
                     "recharging." RESET
                  << std::endl;
        return;
    }
    if ((int)(this->_hitPoints + amount) > ClapTrap::defaultHitPoints)
        amount = ClapTrap::defaultHitPoints - this->_hitPoints;
    if (amount == 0) {
        this->_energyPoints--;
        std::cout << GREEN "ClapTrap " << this->_name
                  << " wastes energy trying to repair itself when it is "
                     "already in tip top shape." RESET
                  << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << GREEN "ClapTrap " << this->_name << " repairs itself for "
              << amount << "." RESET << std::endl;
    return;
}

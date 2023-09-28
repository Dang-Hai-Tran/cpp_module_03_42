/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:42:45 by mcombeau          #+#    #+#             */
/*   Updated: 2023/09/28 15:27:15 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include "Colors.h"
#include <iostream>
#include <string>

#define CLAPTRAP_DEFAULT_HIT_POINTS 10
#define CLAPTRAP_DEFAULT_ENERGY_POINTS 10
#define CLAPTRAP_DEFAULT_ATTACK_DAMAGE 0

class ClapTrap {
  public:
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

  protected:
    ClapTrap(void);

    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
    int _maxHitPoints;
    int _maxEnergyPoints;
    int _maxAttackDamage;
};

#endif

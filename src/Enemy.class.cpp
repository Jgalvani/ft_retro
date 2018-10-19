/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:57:18 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 18:43:24 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"

//ACCESSEURS
int		Enemy::getEnemyBulletNumber(void)
{
	return this-> _enemyBulletNumber;
}

//Fonctions membres
void	Enemy::moveLeft(void)
{
	if (this->_x > START_X)
	{
		attron(COLOR_PAIR(this->_color));
		mvaddch(this->_y, this->_x, ' ');
		this->_x -= 1;
		mvaddch(this->_y, this->_x, this->_sign);
		attroff(COLOR_PAIR(this->_color));
	}
}

//Constructeurs
Enemy::Enemy(void) : Entity()
{
	this->_enemyBullets = new EnemyBullet[MAX_ENEMYBULLETS];
	this->_sign = '<';
	this->_x = 100;
	this->_y = random(0, 60);
	this->_hp = 0;
	this->_color = 4;
	return;
}

Enemy::Enemy(Enemy const & src) : Entity()
{
	*this = src;
}

//Destructeurs
Enemy::~Enemy(void)
{
	delete [] _enemyBullets;
}

//Assignation operator overload
Enemy const & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_sign = rhs._sign;
		this->_hp = rhs._hp;
		this->_color = rhs._color;
	}
	return *this;
}

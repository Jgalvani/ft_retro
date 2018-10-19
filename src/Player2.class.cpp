/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player2.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:01:38 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 19:30:23 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"

//ACCESSEURS
int		Player2::getBulletNumber(void)
{
	return this->_bulletNumber;
}

//Fonctions membres
void	Player2::shoot(void)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (this->_bullets[i].getHp() == 0)
		{
			this->_bullets[i].setHp(1);
			this->_bullets[i].setX(this->getX() + 2);
			this->_bullets[i].setY(this->getY());
			mvaddch(this->_bullets[i].getY(), this->_bullets[i].getX(), this->_bullets[i].getSign());
			break;
		}
	}
}

void	Player2::action(int key)
{
	int		keyTab[4] = {LEFT, RIGHT, UP, DOWN};
	void	(Player2::*functions[4])(void) = {&Player2::moveLeft, &Player2::moveRight, &Player2::moveUp, &Player2::moveDown};

	if (key == SHOOT2 and this->_bulletNumber < MAX_BULLETS)
		this->shoot();

	for (int i = 0; i < 4; i++)
	{
		if (key == keyTab[i])
		{
			(this->*functions[i])();
			break;
		}
	}
}

int		Player2::getNewBulletId(void)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (this->_bullets[i].getHp() > 0)
			return i;
	}
	return -1;
}

void	Player2::setBullet(Bullet bullet)
{
	this->_bullets[bullet.getId()] = bullet;
}

//Constructeurs
Player2::Player2(void) : Entity()
{
	this->_id = 0;
	this->_sign = '>';
	this->_x = 1;
	this->_y = 25;
	this->_hp = 3;
	this->_color = 3;
	this->_bulletNumber = 0;
	this->_bullets = new Bullet[MAX_BULLETS];
}

Player2::Player2(Player2 const & src) : Entity()
{
	*this = src;
}

//Destructeurs
Player2::~Player2(void)
{
	delete [] _bullets;
}

//Assignation operator overload
Player2 const & Player2::operator=(Player2 const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_sign = rhs._sign;
		this->_hp = rhs._hp;
		this->_bulletNumber = rhs._bulletNumber;
	}
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:54:10 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 19:26:09 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"

//ACCESSEURS
int		Player::getBulletNumber(void)
{
	return this->_bulletNumber;
}

//Fonctions membres
void	Player::shoot(void)
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

void	Player::action(int key)
{
	int		keyTab[4] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN};
	void	(Player::*functions[4])(void) = {&Player::moveLeft, &Player::moveRight, &Player::moveUp, &Player::moveDown};

	if (key == SHOOT and this->_bulletNumber < MAX_BULLETS)
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

int		Player::getNewBulletId(void)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (this->_bullets[i].getHp() > 0)
			return i;
	}
	return -1;
}

void	Player::setBullet(Bullet bullet)
{
	this->_bullets[bullet.getId()] = bullet;
}

//Constructeurs
Player::Player(void) : Entity()
{
	this->_id = 0;
	this->_sign = '>';
	this->_x = 1;
	this->_y = 15;
	this->_hp = 3;
	this->_color = 2;
	this->_bulletNumber = 0;
	this->_bullets = new Bullet[MAX_BULLETS];
}

Player::Player(Player const & src) : Entity()
{
	*this = src;
}

//Destructeurs
Player::~Player(void)
{
	delete [] _bullets;
}

//Assignation operator overload
Player const & Player::operator=(Player const & rhs)
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

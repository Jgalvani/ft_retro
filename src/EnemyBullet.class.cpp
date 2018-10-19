/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:45:40 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 18:51:26 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"

//Fonctions membres
void	EnemyBullet::moveLeft(void)
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
EnemyBullet::EnemyBullet(void) : Entity()
{
	this->_sign = '+';
	this->_hp = 0;
	this->_color = 5;
	return;
}

EnemyBullet::EnemyBullet(EnemyBullet const & src) : Entity(src)
{
	*this = src;
}

//Destructeurs
EnemyBullet::~EnemyBullet(void){}

//Assignation operator overload
EnemyBullet const & EnemyBullet::operator=(EnemyBullet const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_id = rhs._id;
		this->_sign = rhs._sign;
		this->_hp = rhs._hp;
		this->_color = rhs._color;
	}
	return *this;
}

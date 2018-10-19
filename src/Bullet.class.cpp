/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:59:16 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 12:50:42 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"

//Constructeurs
Bullet::Bullet(void) : Entity()
{
	this->_sign = '-';
	this->_hp = 0;
	this->_color = 1;
	return;
}

Bullet::Bullet(Bullet const & src) : Entity(src)
{
	*this = src;
}

//Destructeurs
Bullet::~Bullet(void){}

//Assignation operator overload
Bullet const & Bullet::operator=(Bullet const & rhs)
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

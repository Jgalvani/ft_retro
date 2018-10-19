/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:45:59 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 21:24:19 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"





//Setters
void	Entity::setHp(int hp)
{
	this->_hp = hp;
}

void	Entity::setX(int x)
{
	this->_x = x;
}

void	Entity::setY(int y)
{
	this->_y = y;
}

//Accesseurs
int		Entity::getX(void)
{
	return this->_x;
}

int		Entity::getY(void)
{
	return this->_y;
}

int		Entity::getId(void)
{
	return this->_id;
}

char	Entity::getSign(void)
{
	return this->_sign;
}

int		Entity::getColor(void)
{
	return this->_color;
}

int		Entity::getHp(void)
{
	return this->_hp;
}

//Fonctions membres
void	Entity::getDamage(void)
{
	this->_hp -= 1;
	if (this->_hp <= 0)
	{
		if (this->getX() == START_X)
		{
			attron(COLOR_PAIR(6));
			mvaddch(this->getY(), this->getX(), '|');
			attroff(COLOR_PAIR(6));
		}

		else
			mvaddch(this->getY(), this->getX(), ' ');
	}
}

void	Entity::moveUp(void)
{
	if (this->_y > START_Y + 1)
	{
		attron(COLOR_PAIR(this->_color));
		mvaddch(this->_y, this->_x, ' ');
		this->_y -= 1;
		mvaddch(this->_y, this->_x, this->_sign);
		attroff(COLOR_PAIR(this->_color));
	}
}

void	Entity::moveDown(void)
{
	if (this->_y < START_Y + HEIGHT - 1)
	{
		attron(COLOR_PAIR(this->_color));
		mvaddch(this->_y, this->_x, ' ');
		this->_y += 1;
		mvaddch(this->_y, this->_x, this->_sign);
		attroff(COLOR_PAIR(this->_color));
	}
}

void	Entity::moveLeft(void)
{
	if (this->_x > START_X + 1)
	{
		attron(COLOR_PAIR(this->_color));
		mvaddch(this->_y, this->_x, ' ');
		this->_x -= 1;
		mvaddch(this->_y, this->_x, this->_sign);
		attroff(COLOR_PAIR(this->_color));
	}
}

void	Entity::moveRight(void)
{
	if (this->_x < START_X + WIDTH - 1)
	{
		attron(COLOR_PAIR(this->_color));
		mvaddch(this->_y, this->_x, ' ');
		this->_x += 1;
		mvaddch(this->_y, this->_x, this->_sign);
		attroff(COLOR_PAIR(this->_color));
	}
}

//Constructeurs
Entity::Entity(void){}

Entity::Entity(Entity const & src)
{
	*this = src;
}

//Destructeurs
Entity::~Entity(void){}

//Assignation operator overload
Entity const & Entity::operator=(Entity const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_sign = rhs._sign;
		this->_hp = rhs._hp;
	}
	return *this;
}

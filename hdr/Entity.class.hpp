/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:16:49 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 12:38:19 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CLASS_HPP
# define ENTITY_CLASS_HPP

# include "ft_retro.hpp"

class Entity 
{
	protected:
	char 	_sign;
	int		_x;
	int		_y;
	int		_hp;
	int		_color;
	int		_id;

	public:
	int		getX(void);
	int		getY(void);
	int		getId(void);
	int		getColor(void);
	int		getHp(void);
	char	getSign(void);

	void	setHp(int hp);
	void	setX(int x);
	void	setY(int y);

	void	moveUp(void);
	void	moveDown(void);
	void	moveLeft(void);
	void	moveRight(void);

	void	getDamage();

	Entity(void);
	Entity(Entity const & src);
	~Entity(void);

	Entity const &	operator=(Entity const & rhs);
};

#endif

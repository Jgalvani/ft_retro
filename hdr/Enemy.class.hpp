/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:23:51 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 18:39:44 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include "ft_retro.hpp"

class Enemy : public Entity
{
	public:
	int		_enemyBulletNumber;

	public:
	int		getEnemyBulletNumber();
	EnemyBullet	*_enemyBullets;
	void	moveLeft();

	Enemy(void);
	Enemy(Enemy const & src);
	~Enemy(void);

	Enemy const &	operator=(Enemy const & rhs);
};

#endif

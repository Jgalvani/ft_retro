/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:23:16 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 12:32:40 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "ft_retro.hpp"

class Player : public Entity
{
	private:
	int		_bulletNumber;

	public:
	Bullet	*_bullets;
	void	shoot(void);

	int		getBulletNumber(void);
	int		getNewBulletId(void);
	void	setBullet(Bullet bullet);

	void	action(int key);

	Player(void);
	Player(Player const & src);
	~Player(void);

	Player const &	operator=(Player const & rhs);
};

#endif

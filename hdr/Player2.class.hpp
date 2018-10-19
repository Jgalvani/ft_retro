/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player2.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:03:15 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 19:15:27 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER2_CLASS_HPP
# define PLAYER2_CLASS_HPP

# include "ft_retro.hpp"

class Player2 : public Entity
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

	Player2(void);
	Player2(Player2 const & src);
	~Player2(void);

	Player2 const &	operator=(Player2 const & rhs);
};

#endif

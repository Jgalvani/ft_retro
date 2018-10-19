/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:50:18 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 18:46:12 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYBULLET_CLASS_HPP
# define ENEMYBULLET_CLASS_HPP

# include "ft_retro.hpp"

class EnemyBullet : public Entity
{
	public:
	void	moveLeft();
	EnemyBullet(void);
	EnemyBullet(EnemyBullet const & src);
	~EnemyBullet(void);

	EnemyBullet const &	operator=(EnemyBullet const & rhs);
};

#endif

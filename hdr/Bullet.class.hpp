/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:37:53 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 12:41:56 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

# include "ft_retro.hpp"

class Bullet : public Entity
{
	public:
	Bullet(void);
	Bullet(Bullet const & src);
	~Bullet(void);

	Bullet const &	operator=(Bullet const & rhs);
};

#endif

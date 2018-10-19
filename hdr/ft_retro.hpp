/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:15:12 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 20:57:08 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# include	<ncurses.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>

# include	<iostream>
# include	<string>
# include	<cstring>

# define	DEBUG				0

# define	TIMEOUT				8

# define	MAX_ENEMIES 		10
# define	MAX_BULLETS 		20
# define	MAX_ENEMYBULLETS	4

# define	RETURN		 		10	//	key return

# define	SHOOT		 		46	//	key .

# define	UP					119	// key W
# define	DOWN				115	//key S			
# define	LEFT				97	//key A			
# define	RIGHT				100	//key D			
# define	SHOOT2				32	//key Space

# define	WIDTH				101
# define	HEIGHT				30

# define	START_X				0
# define	START_Y				0

int			random(int min, int max);

# include	"Entity.class.hpp"
# include	"EnemyBullet.class.hpp"
# include	"Bullet.class.hpp"
# include	"Enemy.class.hpp"
# include	"Player.class.hpp"
# include	"Player2.class.hpp"
# include	"Game.class.hpp"

#endif

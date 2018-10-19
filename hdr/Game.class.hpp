/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:20:11 by jaustry           #+#    #+#             */
/*   Updated: 2018/10/07 21:22:10 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "ft_retro.hpp"

class Game
{
	private:
	Enemy	*_enemies;
	int		_enemyNumber;
	int		_enemyCounter;

	WINDOW	*_win;

	int		_width;
	int		_height;
	int		_startX;
	int		_startY;

	char	_borderLeft;
	char	_borderRight;
	char	_borderTop;
	char	_borderDown;
	char	_borderTopLeft;
	char	_borderTopRight;
	char	_borderDownLeft;
	char	_borderDownRight;

	int		_score;

	int		_speed;

	bool	_over;
	
	void		highlightMenu(int highlight);

	public:
	Player	*_player;
	Player2	*_player2;

	void	printScore(void);
	int		playerMenu(void);

	int		getScore(void);
	int		getSpeed(void);
	int		getEnemyNumber(void);
	int		getEnemyBulletNumber(void);
	bool	getOver(void);

	int		getNewEnemyId(void);
	void	createEnemy(void);
	void	enemyShoot(void);

	void	moveBullets(void);
	void	moveEnemyBullets(void);
	void	moveEnemies(void);

	void	checkCollisions(void);

	void	createBox(void);
	void	destroyBox(void);
	void	destroyWin(void);

	void	createNewWin(void);

	void	display_init_color();
	Game(void);
	Game(Game const & src);
	~Game(void);

	Game const &	operator=(Game const & rhs);
};

#endif


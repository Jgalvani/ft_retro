/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:37:38 by jaustry           #+#    #+#             */
/*   Updated: 2018/10/07 21:39:48 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"

int random(int min, int max)
{
	return (min +(rand() % (max-min)));
}

int		main(void)
{
	int		row, col;
	int		key;
	int		count = 0;
	Game *	game = new Game();

	srand ( time(NULL) ); //initialize the random seed

	if (game->playerMenu() == 1)
		game->_player2->setHp(0);

	game->createBox();
	initscr();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	cbreak();
	timeout(TIMEOUT);	
	getmaxyx(stdscr, row, col);
	game->display_init_color();
	while (game->getOver() == false)
	{
		key = getch();
		if (key == KEY_F(1))
			break;
		if (game->_player->getHp() > 0)
			game->_player->action(key);
		if (game->_player2->getHp() > 0)
			game->_player2->action(key);
		if (count % game->getSpeed() == 0 and game->getEnemyNumber() < MAX_ENEMIES)
		{
			game->createEnemy();
			if (count % (game->getSpeed() * 2) == 0)
			{
				game->enemyShoot();
				count = 0;
			}
		}
		game->moveBullets();
		game->moveEnemyBullets();
		game->moveEnemies();
		game->checkCollisions();
		refresh();
		count++;
		if (game->_player->getHp() <= 0 and game->_player2->getHp() <= 0)
			break;
	}
	game->printScore();
	sleep(5);
	endwin();
	delete game;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:03:56 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/07 21:52:16 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ft_retro.hpp"

//ACCESSEURS
int	Game::getScore(void)
{
	return this->_score;
}

int		Game::getSpeed(void)
{
	return this->_speed;
}

bool		Game::getOver(void)
{
	return this->_over;
}

int		Game::getEnemyNumber(void)
{
	return this-> _enemyNumber;
}

//Fonctions membres
void Game::highlightMenu(int highlight)
{
	char players[2][10] = {"1 Player ", "2 Players"};
	int x, y, i;	

	x = 2;
	y = 2;
	box(this->_win, 0, 0);
	for(i = 0; i < 2; ++i)
	{	if(highlight == i + 1) 
		{	wattron(this->_win, A_REVERSE); 
			mvwprintw(this->_win, y, x, "%s", players[i]);
			wattroff(this->_win, A_REVERSE);
		}
		else
			mvwprintw(this->_win, y, x, "%s", players[i]);
		++y;
	}
	wrefresh(this->_win);
}

void	Game::display_init_color()
{
	start_color();

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_GREEN);

	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(20, COLOR_BLACK, COLOR_BLUE);

	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(30, COLOR_BLUE, COLOR_YELLOW);

	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(40, COLOR_BLACK, COLOR_RED);

	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
}


int	Game::playerMenu(void)
{	
	int highlight = 1;
	int choice = 0;
	int key = 0;
	int players = 2;

	initscr();
	clear();
	noecho();
	cbreak();	

	this->_win = newwin(HEIGHT, WIDTH, START_Y, START_X);
	keypad(_win, TRUE);
	curs_set(0);
	refresh();
	while(1)
	{	key = wgetch(_win);
		if (key == KEY_UP)
		{
			if(highlight == 1)
				highlight = players;
			else
				--highlight;
		}
		else if (key == KEY_DOWN)
		{
			if(highlight == players)
				highlight = 1;
			else 
				++highlight;
		}
		else if (key == RETURN)
			choice = highlight;
		refresh();
		highlightMenu(highlight);
		if(choice != 0)	
			break;
	}	
	clrtoeol();
	refresh();
	clear();
	endwin();
	return choice;
}

void	Game::printScore(void)
{
	mvaddstr(START_X + 10, START_Y + 10, "Congratulations ! Your score is: ");
	refresh();
	std::cout << this->_score << std::endl;
}

void	Game::enemyShoot(void)
{
	for (int j = 0; j < MAX_ENEMIES; j++)
	{
		for (int i = 0; i < MAX_ENEMYBULLETS; i++)
		{
			if (this->_enemies[j].getHp() > 0 and this->_enemies[j]._enemyBullets[i].getHp() == 0)
			{
				this->_enemies[j]._enemyBullets[i].setHp(1);
				this->_enemies[j]._enemyBullets[i].setX(this->_enemies[j].getX() - 2);
				this->_enemies[j]._enemyBullets[i].setY(this->_enemies[j].getY());
				mvaddch(this->_enemies[j]._enemyBullets[i].getY(), this->_enemies[j]._enemyBullets[i].getX(), this->_enemies[j]._enemyBullets[i].getSign());
				break;
			}
		}
	}
}

void	Game::checkCollisions(void)
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (this->_enemies[i].getX() == this->_player->getX() and this->_enemies[i].getY() == this->_player->getY() and this->_enemies[i].getHp() > 0)
			this->_player->getDamage();

		if (this->_enemies[i].getX() == this->_player2->getX() and this->_enemies[i].getY() == this->_player2->getY() and this->_enemies[i].getHp() > 0)
			this->_player2->getDamage();
		for (int k = 0; k < MAX_ENEMYBULLETS; k++)
		{
		if (this->_enemies[i]._enemyBullets[k].getX() == this->_player2->getX() and this->_enemies[i]._enemyBullets[k].getY() == this->_player2->getY() and this->_enemies[i]._enemyBullets[k].getHp() > 0)
			this->_player2->getDamage();
		if (this->_enemies[i]._enemyBullets[k].getX() == this->_player->getX() and this->_enemies[i]._enemyBullets[k].getY() == this->_player->getY() and this->_enemies[i]._enemyBullets[k].getHp() > 0)
			this->_player->getDamage();
		}

		for (int j = 0; j < MAX_BULLETS; j++)
		{
			if (this->_enemies[i].getX() == this->_player->_bullets[i].getX() and this->_enemies[i].getY() == this->_player->_bullets[i].getY() and this->_player->_bullets[i].getHp() > 0)
			{
				this->_player->_bullets[i].getDamage();
				this->_enemies[i].getDamage();
				this->_score += 1;
				if (this->_speed > 10)
					this->_speed -= 10;
				break;
			}
			if (this->_enemies[i].getX() == this->_player2->_bullets[i].getX() and this->_enemies[i].getY() == this->_player2->_bullets[i].getY() and this->_player2->_bullets[i].getHp() > 0)
			{
				this->_player2->_bullets[i].getDamage();
				this->_enemies[i].getDamage();
				this->_score += 1;
				if (this->_speed > 10)
					this->_speed -= 10;
				break;
			}
		}
	}
}

//ENEMIES
void	Game::moveEnemies(void)
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (this->_enemies[i].getHp() > 0)
		{
			int rand = random(0,30);
			if (rand == 0)
				this->_enemies[i].moveLeft();
			if (rand == 1)
				this->_enemies[i].moveUp();
			if (rand == 2)
				this->_enemies[i].moveDown();
			if (this->_enemies[i].getX() < START_X + 1)
				this->_enemies[i].getDamage();
		}
	}
}

void	Game::moveBullets(void)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (this->_player->_bullets[i].getHp() > 0)
		{
			this->_player->_bullets[i].moveRight();
			if (this->_player->_bullets[i].getX() > START_X + WIDTH - 2)
				this->_player->_bullets[i].getDamage();
		}
		if (this->_player2->_bullets[i].getHp() > 0)
		{
			this->_player2->_bullets[i].moveRight();
			if (this->_player2->_bullets[i].getX() > START_X + WIDTH - 2)
				this->_player2->_bullets[i].getDamage();
		}
	}
}

void	Game::moveEnemyBullets(void)
{
	for (int j = 0; j < MAX_ENEMIES; j++)
	{
		for (int i = 0; i < MAX_ENEMYBULLETS; i++)
		{
			if (this->_enemies[j]._enemyBullets[i].getHp() > 0)
			{
				this->_enemies[j]._enemyBullets[i].moveLeft();
				if (this->_enemies[j]._enemyBullets[i].getX() < START_X + 1)
					this->_enemies[j]._enemyBullets[i].getDamage();
			}
		}
	}
}

int		Game::getNewEnemyId(void)
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (this->_enemies[i].getHp() > 0)
		{
			return i;
		}
	}
	return -1;
}

void	Game::createEnemy(void)
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (this->_enemies[i].getHp() == 0)
		{
			this->_enemies[i].setHp(1);
			this->_enemies[i].setX(START_X + WIDTH - 1), 
			this->_enemies[i].setY(random(START_Y + 1, START_Y + HEIGHT - 1));
			break;
		}
	}
}

//WINDOW
void	Game::createNewWin(void)
{	
	this->_win = newwin(HEIGHT, WIDTH, START_Y, START_X);
	box(this->_win, 0 , 0);		 
								 
	wrefresh(this->_win);	
}

void	Game::destroyWin(void)
{	
	wborder(this->_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(this->_win);
	delwin(this->_win);
}

void	Game::createBox(void)
{
	mvaddch(START_Y, START_X, this->_borderTopLeft);
	mvaddch(START_Y, START_X + WIDTH, this->_borderTopRight);
	mvaddch(START_Y + HEIGHT, START_X, this->_borderDownLeft);
	mvaddch(START_Y + HEIGHT, START_X + WIDTH, this->_borderDownRight);
	mvhline(START_Y, START_X + 1, this->_borderTop, WIDTH - 1);
	mvhline(START_Y + HEIGHT, START_X + 1, this->_borderDown, WIDTH - 1);
	mvvline(START_Y + 1, START_X, this->_borderLeft, HEIGHT - 1);
	mvvline(START_Y + 1, START_X + WIDTH, this->_borderRight, HEIGHT - 1);
}

void	Game::destroyBox(void)
{
	int	i;
	int	j;

	for(j = START_Y; j <= START_Y + HEIGHT; ++j){
		for(i = START_X; i <= START_X + WIDTH; ++i){
			mvaddch(j, i, ' ');
		}
	}
	refresh();
}

//Constructeurs
Game::Game(void)
{
	this->_player = new Player();
	this->_player2 = new Player2();

	this->_enemies = new Enemy[MAX_ENEMIES];

	this->_enemyNumber = 0;
	this->_enemyCounter = 0;

	this->_borderLeft = '|';
	this->_borderRight = '|';
	this->_borderTop = '-';
	this->_borderDown = '-';
	this->_borderTopLeft = '+';
	this->_borderTopRight = '+';
	this->_borderDownLeft = '+';
	this->_borderDownRight = '+';

	this->_speed = 200;

	this->_score = 0;

	this->_over = false;
}

Game::Game(Game const & src)
{
	*this = src;
}

//Destructeurs
Game::~Game(void)
{
	delete [] _enemies;
	delete _player;
	delete _player2;
}

//Assignation operator overload
Game const & Game::operator=(Game const & rhs)
{
	if (this != &rhs)
	{
		this->_enemyNumber = rhs._enemyNumber;
		this->_enemyCounter = rhs._enemyCounter;

		this->_player = rhs._player;

		this->_over = rhs._over;

		this->_win = rhs._win;

		this->_width = rhs._width;
		this->_height = rhs._height;
		this->_startX = rhs._startX;
		this->_startY = rhs._startY;

		this->_borderLeft = rhs._borderLeft;
		this->_borderRight = rhs._borderRight;
		this->_borderTop = rhs._borderTop;
		this->_borderDown = rhs._borderDown;
		this->_borderTopLeft = rhs._borderTopLeft;
		this->_borderTopRight = rhs._borderTopRight;
		this->_borderDownLeft = rhs._borderDownLeft;
		this->_borderDownRight = rhs._borderDownRight;

		this->_score = rhs._score;

		this->_speed = rhs._speed;
	}
	return *this;
}

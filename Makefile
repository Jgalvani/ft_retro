# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 17:10:37 by jgalvani          #+#    #+#              #
#    Updated: 2018/10/07 19:26:49 by jgalvani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC_DIR = src

HDR_DIR = hdr

CLASS_DIR = class

OBJ_DIR = objects

SRCS = main.cpp Bullet.class.cpp Entity.class.cpp Enemy.class.cpp Player.class.cpp Game.class.cpp EnemyBullet.class.cpp Player2.class.cpp

HDRS = ft_retro.hpp Bullet.class.hpp Entity.class.hpp Enemy.class.hpp Player.class.hpp Game.class.hpp EnemyBullet.class.hpp Player.class.hpp


OBJS = $(SRCS:.cpp=.o)

SRC_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
HDR_PATH = $(addprefix $(HDR_DIR)/,$(HDRS))
OBJ_PATH = $(addprefix $(OBJ_DIR)/,$(OBJS))

FLGS = -Wall -Wextra -Werror

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(SRC_PATH) $(HDR_PATH)
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@echo "\033[0;40;32mCreating objects." 2> /dev/null
	@clang++ -c  $(FLGS) $(SRC_PATH)
	@mv $(OBJS) $(OBJ_DIR) 2> /dev/null
	@echo "Compiling" $(NAME) 2> /dev/null
	@clang++ $(FLGS) -lcurses -o $(NAME) $(OBJ_PATH)
	@echo "\033[0m" 2> /dev/null

clean:
	@echo "\033[0;40;31mErasing objects."
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@rmdir $(OBJ_DIR) 2> /dev/null || true
	@echo "\033[0m" 2> /dev/null

fclean:	clean
	@echo "\033[0;40;35mErasing" $(NAME)
	@rm -rf $(NAME) 2> /dev/null
	@echo "\033[0m" 2> /dev/null

re: fclean all

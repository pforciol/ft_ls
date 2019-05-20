# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 11:47:04 by pforciol          #+#    #+#              #
#    Updated: 2019/05/20 14:13:12 by pforciol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
DARK_GREY = \033[0;90m
NORMAL = \033[0m

NAME = ft_ls
CC = @gcc

OBJ_DIR = objs/

CFLAGS = -Wall -Wextra -Werror

SRC =		ft_ls_utils.c \
			ft_list_dir.c
			
SRC_DIR = srcs/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
SRC := $(addprefix $(SRC_DIR), $(SRC))

INCLUDES = includes/ft_ls.h

.SILENT:

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) -o $(NAME) $(SRC) -L libft/ -lft
	@echo "$(DARK_GREY)COMPILATION	 $(GREEN)>>$(NORMAL) ft_ls has been compiled"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES) libft/libft.a
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

debug: lib $(OBJ)
	$(CC) -g -o $(NAME) $(SRC) -L libft/ -lft
	@echo "$(DARK_GREY)COMPILATION	 $(GREEN)>>$(NORMAL) ft_ls has been compiled $(DARK_GREY)(ready for debug)$(NORMAL)"

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(DARK_GREY)SUPPRESSION	 $(RED)>>$(NORMAL) ft_ls has been removed $(DARK_GREY)(object files)$(NORMAL)"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(DARK_GREY)SUPPRESSION	 $(RED)>>$(NORMAL) ft_ls has been removed $(DARK_GREY)(executables)$(NORMAL)"

lib:
	@make -C libft

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 11:47:04 by pforciol          #+#    #+#              #
#    Updated: 2019/09/12 16:08:45 by pforciol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[91m
GREEN = \033[32m
DARK_GREY = \033[90m
NORMAL = \033[0m

NAME = ft_ls
CC = gcc

OBJ_DIR = objs/

CFLAGS = -Wall -Wextra -Werror

SRC =		ft_ls.c \
			ls_directory.c \
			ls_display_l.c \
			ls_display_utils.c \
			ls_display.c \
			ls_lst_utils.c \
			ls_names.c \
			ls_options.c \
			ls_process.c \
			ls_sort.c \
			ls_utils.c
			
SRC_DIR = srcs/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
SRC := $(addprefix $(SRC_DIR), $(SRC))

INCLUDES = includes/ft_ls.h

.SILENT:

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L libft/ -lft
	@echo "$(DARK_GREY)COMPILATION	 $(GREEN)>>$(NORMAL) ft_ls has been compiled"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES) libft/libft.a
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

debug: lib $(OBJ)
	$(CC) -g3 $(CFLAGS) -o $(NAME) $(SRC) -L libft/ -lft
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

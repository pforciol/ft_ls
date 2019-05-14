# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 11:47:04 by pforciol          #+#    #+#              #
#    Updated: 2019/05/14 14:07:44 by pforciol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
DARK_GREY = \033[0;90m
NORMAL = \033[0m

NAME = ft_ls
CC = @gcc
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

SRCS =		srcs/ft_ls_utils.c \
			srcs/ft_inspect_file.c

all: $(NAME)

libftmake:
	@make -C libft

libftfclean:
	@make -C libft fclean

$(NAME): libftmake $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L libft/ -lft &> /dev/null
	@echo "$(DARK_GREY)COMPILATION	 $(GREEN)>>$(NORMAL) ft_ls has been compiled"

debug: libftmake $(OBJS)
	$(CC) -g -o $(NAME) $(SRCS) -L libft/ -lft
	@echo "$(DARK_GREY)DEBUGGING	 $(GREEN)>>$(NORMAL) ft_ls has been compiled $(DARK_GREY)(ready for debug)$(NORMAL)"

clean:
	@rm -f $(OBJS)
	@echo "$(DARK_GREY)SUPPRESSION	 $(RED)>>$(NORMAL) ft_ls has been removed $(DARK_GREY)(object files)$(NORMAL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(DARK_GREY)SUPPRESSION	 $(RED)>>$(NORMAL) ft_ls has been removed $(DARK_GREY)(executables)$(NORMAL)"

re: fclean all

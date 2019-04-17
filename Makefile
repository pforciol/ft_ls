# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 11:47:04 by pforciol          #+#    #+#              #
#    Updated: 2019/04/17 12:58:26 by pforciol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = @gcc
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

SRCS =		srcs/ft_list_dir.c

all: $(NAME)

# Rule to make our libft without going into libft directory
libftmake:
	@make -C libft

# Rule to fclean our libft without going into libft directory
libftfclean:
	@make -C libft fclean

# Rule to make our "ft_ls" executable
$(NAME): libftmake $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L libft/ -lft &> /dev/null
	@echo "\033[90mCOMPILATION	 \033[92m>>\033[39m ft_ls has been compiled"

# Rule when we want to debug with option -g (to use with gdb / lldb)
debug: libftmake $(OBJS)
	$(CC) -g -o $(NAME) $(SRCS) -L libft/ -lft
	@echo "\033[90mDEBUGGING	 \033[92m>>\033[39m ft_ls has been compiled \033[90m(ready for debug)\033[39m"

# Rule to clean our directories without removing the "ft_ls" executable
clean:
	@rm -f $(OBJS)
	@echo "\033[90mSUPPRESSION	 \033[91m>>\033[39m ft_ls has been removed \033[90m(object files)\033[39m"

# Rule to totally clean our directory
fclean: clean
	@rm -f $(NAME)
	@echo "\033[90mSUPPRESSION	 \033[91m>>\033[39m ft_ls has been removed \033[90m(executables)\033[39m"

# Rule to fclean our directory and re-compile right after
re: fclean all

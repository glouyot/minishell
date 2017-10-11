# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 17:19:59 by glouyot           #+#    #+#              #
#    Updated: 2017/10/11 14:21:22 by glouyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

INCLUDES	:= -I../include
INC_PATH	:= ./include
INC			:= minishell.h

FLAGS		:= -Wall -Werror -Wextra
FLAGS_DEBUG	:= -Wall -Werror -Wextra -g

ARGS		:= ./libft
LIBNAME		:= libft.a

OBJECTS		:= 	builtins/ft_echo.o\
				builtins/ft_cd.o\
				builtins/ft_setenv.o\
				builtins/ft_unsetenv.o\
				builtins/ft_env.o\
				builtins/ft_exit.o\
				builtins/ft_help.o\
				builtins/ft_getenv.o\
			   	srcs/minishell.o\
				srcs/ft_signals.o\
				srcs/ft_error.o\
				srcs/loop.o\
				srcs/exec.o\
				srcs/ft_mkenv.o\
				srcs/ft_delenv.o\


ifneq ($(shell make -q -C libft; echo $$?), 0)
.PHONY: $(ARGS)
endif

.PHONY: all, fclean, clean, re, debug

all: $(NAME)

$(ARGS):
	make -C $(ARGS)

%.o: %.c $(INC_PATH)/$(INC)
	gcc $(FLAGS_DEBUG) $(INCLUDES) -c $< -o $@

$(NAME): $(ARGS) $(OBJECTS) $(INC_PATH)/$(INC)
	gcc $(FLAGS_DEBUG) $(INCLUDES) $(OBJECTS) $(ARGS)/$(LIBNAME) -o $(NAME)
	@echo "Done !"

debug: $(ARGS) $(OBJECTS) $(INC_PATH)/$(INC)
	gcc $(FLAGS_DEBUG) $(INCLUDES) $(OBJECTS) $(ARGS)/$(LIBNAME) -o $(NAME)
	@echo "Done !"

clean:
	make clean -C $(ARGS)
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(ARGS)
	/bin/rm -f $(NAME)

re: fclean
	$(MAKE) all

#				builtins/ft_cd.o\
				builtins/ft_setenv.o\
				builtins/ft_unsetenv.o\
				builtins/ft_env.o\
				builtins/ft_exit.o\
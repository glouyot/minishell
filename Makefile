# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 17:19:59 by glouyot           #+#    #+#              #
#    Updated: 2017/08/02 15:03:42 by glouyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

INCLUDES := -I../includes
INC_PATH := ./includes
INC := ../includes/minishell.h

FLAGS := -Wall -Werror -Wextra -O2

ARGS := ./libft
LIBNAME := libft.a

OBJECTS := 	srcs/minishell.o\


ifneq ($(shell make -q -C libft; echo $$?), 0)
.PHONY: $(ARGS)
endif

.PHONY: all, fclean, clean, re

all: $(NAME)

$(ARGS):
	make -C $(ARGS)

%.o: %.c $(INC_PATH)/$(INC)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(ARGS) $(OBJECTS) $(INC_PATH)/$(INC)
	gcc $(FLAGS) $(INCLUDES) $(OBJECTS) $(ARGS)/$(LIBNAME) -o $(NAME)
	@echo "Done !"

clean:
	make clean -C $(ARGS)
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(ARGS)
	/bin/rm -f $(NAME)

re: fclean
	$(MAKE) all

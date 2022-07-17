# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 15:56:29 by jgoldste          #+#    #+#              #
#    Updated: 2022/07/17 20:32:29 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRCS		=	minishell.c		init.c		env.c	free_utils.c	error.c

HEADER		=	minishell.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS))

INCLUDES	=	-I.

CFLAGS		=	-Wall -Wextra -Werror -g

CC			=	gcc

RM			=	rm -rf

LIB			=	./libft/libft.a

YELLOW		=	"\033[1;33m"
GREEN		=	"\033[1;32m"
END			=	"\033[0m"

.PHONY		:	all libft clean fclean re

all			:	libft $(NAME)

libft		:	
				$(MAKE) -C $(dir $(LIB))

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MD

$(NAME)		:	$(OBJS) $(LIB)
				$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(OBJS)
				@echo ${GREEN} "\n\tMinishell is compiled\n" ${END}
clean		:	
				@$(RM) $(OBJS) $(D_FILES)
				@$(MAKE) -C $(dir $(LIB)) clean
				@echo ${YELLOW} "\n\tMinishell 'clean' status: DONE\n" ${END}
				
fclean		:	clean
				@$(RM) $(NAME)
				@$(MAKE) -C $(dir $(LIB)) fclean
				@echo ${YELLOW} "\n\tMinishell 'fclean' status: DONE\n" ${END}

re			:	fclean all

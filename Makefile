# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 15:56:29 by jgoldste          #+#    #+#              #
#    Updated: 2022/07/19 05:06:33 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

HEADER		:=	minishell.h
BUILDDIR	:=	object
INC			:=	-I./includes/ -I./gnl/ -I./libft/

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g -fPIE

LIB			:=	libft/libft.a# -ltermcap -lreadline
LFLAGS		:=	-ltermcap -lreadline

EXECUTE_SRC	=	cd.c	init.c		env.c	free_utils.c	error.c

# PARSER_SRC	=	

GNL_SRC		=	get_next_line.c			get_next_line_utils.c

SOURCES := $(PARSER_SRC:%=parser/%) $(EXECUTE_SRC:%=sources/%) $(GNL_SRC:%=gnl/%) main.c
OBJECTS := $(patsubst %,$(BUILDDIR)/%,$(SOURCES:.c=.o))
D_FILES := $(patsubst %,$(BUILDDIR)/%,$(SOURCES:.c=.d))

# RM			=	rm -rf

YELLOW		=	"\033[1;33m"
GREEN		=	"\033[1;32m"
END			=	"\033[0m"

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(dir $(LIB))
	$(CC) $^ -o $(NAME) $(LIB) $(LFLAGS)
	@echo ${GREEN} "\n\tMinishell is compiled\n" ${END}

$(BUILDDIR)/%.o: ./%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -g -c -o $@ $< -MD

clean:
	@make -C ./libft/ clean
	$(RM) -r $(BUILDDIR)

fclean:	clean
	@make -C ./libft/ fclean
	$(RM) -r $(NAME)

re: fclean all

norm:
	@norminette *.c *.h

.PHONY: clean fclean re


# NAME		=	minishell

# HEADER		=	minishell.h

# SRCS		=	cd.c	init.c		env.c	free_utils.c	error.c

# OBJS		=	$(patsubst %.c,%.o,$(SRCS))

# D_FILES		=	$(patsubst %.c,%.d,$(SRCS))

# INCLUDES	=	-I.

# CFLAGS		=	-Wall -Wextra -Werror -g -fPIE

# CC			=	gcc

# RM			=	rm -rf

# LIB			=	libft/libft.a# -lreadline -ltermcap

# YELLOW		=	"\033[1;33m"
# GREEN		=	"\033[1;32m"
# END			=	"\033[0m"

# .PHONY		:	all libft clean fclean re

# all			:	libft $(NAME)

# libft		:	
# 				$(MAKE) -C $(dir $(LIB))

# %.o			:	%.c $(HEADER)
# 				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MD

# $(NAME)		:	$(OBJS) $(LIB)
# 				$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(OBJS)
# 				@echo ${GREEN} "\n\tMinishell is compiled\n" ${END}
# clean		:	
# 				@$(RM) $(OBJS) $(D_FILES)
# 				@$(MAKE) -C $(dir $(LIB)) clean
# 				@echo ${YELLOW} "\n\tMinishell 'clean' status: DONE\n" ${END}
				
# fclean		:	clean
# 				@$(RM) $(NAME)
# 				@$(MAKE) -C $(dir $(LIB)) fclean
# 				@echo ${YELLOW} "\n\tMinishell 'fclean' status: DONE\n" ${END}

# re			:	fclean all

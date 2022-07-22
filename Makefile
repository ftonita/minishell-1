# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 15:56:29 by jgoldste          #+#    #+#              #
#    Updated: 2022/07/22 04:31:18 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

HEADER		:=	./includes/minishell.h ./gnl/get_next_line.h ./libft/libft.h
BUILDDIR	:=	object
INC			:=	-I./includes/ -I./gnl/ -I./libft/

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g -fPIE

LIB			:=	libft/libft.a
LFLAGS		:=	-ltermcap -lreadline

EXECUTE_SRC	=	cd.c	init.c		env.c	history.c	free_utils.c	error.c

PARSER_SRC	=	parser.c

GNL_SRC		=	get_next_line.c			get_next_line_utils.c

SOURCES := $(PARSER_SRC:%=parser/%) $(EXECUTE_SRC:%=sources/%) $(GNL_SRC:%=gnl/%) main.c
OBJECTS := $(patsubst %,$(BUILDDIR)/%,$(SOURCES:.c=.o))
D_FILES := $(patsubst %,$(BUILDDIR)/%,$(SOURCES:.c=.d))

RM			=	rm -rf

YELLOW		=	"\033[1;33m"
GREEN		=	"\033[1;32m"
END			=	"\033[0m"

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(dir $(LIB))
	$(CC) $^ -o $(NAME) $(LIB) $(LFLAGS)
	@echo ${GREEN} "\n\tMinishell is compiled\n" ${END}

$(BUILDDIR)/%.o: ./%.c $(HEADER)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -g -c -o $@ $< -MD

clean:
	@$(MAKE) -C ./libft/ clean
	@$(RM) $(BUILDDIR)
	@echo ${YELLOW} "\n\tMinishell 'clean' status: DONE\n" ${END}

fclean:	clean
	@$(MAKE) -C ./libft/ fclean
	@$(RM) $(NAME)
	@echo ${YELLOW} "\n\tMinishell 'fclean' status: DONE\n" ${END}

re: fclean all

norm:
	@norminette *.c *.h

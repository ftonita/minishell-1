/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:12:25 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/25 23:26:30 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* *************************************************************************** */

#include "minishell.h"

void	mini_parser(t_shell *minishell, char *line)
{
	char	**buff;
	t_mini	*buff_t;

	buff_t = (t_mini *)malloc(sizeof(t_mini));
	if (!buff_t)
		return ;
	buff = ft_split(line, SPACE);
	if (!buff)
	{
		free(buff_t);
		return ;
	}
	buff_t->key = buff[0];
	buff_t->value = buff[1];
	buff_t->next = NULL;
	free(buff);
	minishell->tocken = buff_t;	
}

void	read_loop(t_shell *minishell)
{
	char	*line;
	
	while (1)
	{
		line = readline("minishell % ");
		if (!line)
			exit (EXIT_FAILURE);
		mini_parser(minishell, line);
		free(line);
		free_mini_list(minishell->tocken);
		minishell->tocken = NULL;
		printf("tocken address = [%p]\n", minishell->tocken);
		if (!minishell->tocken)
			exit (EXIT_FAILURE);
		printf("[%s] [%s]\n", minishell->tocken->key, minishell->tocken->value);
		free_mini_list(minishell->tocken);
	}
}

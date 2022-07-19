/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:12:25 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/20 02:51:18 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int mini_parser(t_shell *minishell, char *line)
{
	char	**tocken_arr;
	t_mini	*node;

	tocken_arr = ft_split(line, ' ');
	if (!tocken_arr)
		return (1);
	node = (t_mini *)malloc(sizeof(t_mini));
	if (!node)
	{
		free_array ((void **)tocken_arr);
		return (1);
	}
	node->key = tocken_arr[0];
	node->value = tocken_arr[1];
	node->next = NULL;
	printf("\t%s\n\t%s\n\t%p\n", node->key, node->value, node->next);
	minishell->tocken = node;
	printf("TOCKEN ADDRESS: %p\n", minishell->tocken);
	printf("\t%s\n\t%s\n\t%p\n", minishell->tocken->key, minishell->tocken->value, minishell->tocken->next);
	return (0);
}

void	read_loop(t_shell *minishell)
{
	char	*line;
	
	while (1)
	{
		line = readline("minishell->$ ");
		if (mini_parser(minishell, line))
		{
			printf("!!!miniparser return value [1]\n");
			free(line);
			return ;
		}
		printf("!!!miniparser return value [0]\n");
		free(line);
		printf("[%s] [%s] [%p]\n", minishell->tocken->key, minishell->tocken->value, minishell->tocken->next);
		if (!minishell->tocken->key)
			return ;
	}
}

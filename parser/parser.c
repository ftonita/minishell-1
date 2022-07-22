/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:12:25 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/22 04:15:16 by jgoldste         ###   ########.fr       */
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
	free((void **)tocken_arr);
	minishell->tocken = node;
	return (0);
}

void	read_loop(t_shell *minishell)
{
	char	*line;
	
	while (1)
	{
		line = readline("minishell %% ");
		if (!line)
			return ;
		if (mini_parser(minishell, line))
		{
			write(STDERR_FILENO, "Parser: malloc allocation error\n", 33);
			free(line);
			return ;
		}
		free(line);
		if (!minishell->tocken->key)
			return ;
	}
}

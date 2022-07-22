/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:38:24 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/22 00:58:23 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
	return (0);
}

int	free_mini_list(t_mini *node)
{
	t_mini	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

int	free_minishell(t_shell *minishell)
{
	if (minishell)
	{
		if (minishell->tocken)
			free_mini_list(minishell->tocken);
		if (minishell->mini_env)
			free_mini_list(minishell->mini_env);
		if (minishell->path_array)
			free_array((void **)minishell->path_array);
		free(minishell);
		minishell = NULL;
	}
	return (0);
}

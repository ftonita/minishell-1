/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:38:24 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/17 20:11:50 by jgoldste         ###   ########.fr       */
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
	}
	node = NULL;
	return (0);
}

int	free_minishell(t_shell *minishell)
{
	if (minishell)
	{
		if (minishell->mini_env)
			free_mini_list(minishell->mini_env);
		if (minishell->path_array)
			free_array((void **)minishell->path_array);
		// if (minishell->mini_pwd)
		// 	free(minishell->mini_pwd);
		// if (minishell->mini_oldpwd)
		// 	free(minishell->mini_oldpwd);
		// if (minishell->mini_home)
		// 	free(minishell->mini_home);
		// if (minishell->mini_shlvl)
		// 	free(minishell->mini_shlvl);
		free(minishell);
		minishell = NULL;
	}
	return (0);
}

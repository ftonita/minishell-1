/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:05:05 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/15 19:05:55 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	*init_node_mini_env(char **env, int i)
{
	t_mini	*node_env;
	char	**str_env;

	node_env = (t_mini *)malloc(sizeof(t_mini));
	if (!node_env)
		return (NULL);
	str_env = ft_split(env[i], '=');
	if (!str_env)
	{
		free(node_env);
		return (NULL);
	}
	node_env->key = str_env[0];
	node_env->value = str_env[1];
	node_env->next = NULL;
	free(str_env);
	return (node_env);
}

t_mini	*save_env(char **env, int i)
{
	t_mini	*mini_env;
	t_mini	*node_env;
	t_mini	*node_last;

	mini_env = NULL;
	node_last = NULL;
	while (env[++i])
	{
		node_env = init_node_mini_env(env, i);
		if (!node_env)
			if (!free_mini_list(mini_env))
				return (NULL);
		if (!mini_env)
			mini_env = node_env;
		else
		{
			if (!mini_env->next)
				mini_env->next = node_env;
			else
				node_last->next = node_env;
			node_last = node_env;
		}
	}
	return (mini_env);
}

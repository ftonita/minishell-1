/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:05:05 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/16 01:49:51 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_mini *mini_env)
{
	t_mini	*fix;

	fix = mini_env;
	while (mini_env)
	{
		printf("%s=%s\n", mini_env->key, mini_env->value);
		mini_env = mini_env->next;
	}
	mini_env = fix;
}

t_mini	*init_node_mini_env(char *env)
{
	t_mini	*node_env;
	int		delim;

	delim = 0;
	node_env = (t_mini *)malloc(sizeof(t_mini));
	if (!node_env)
		return (NULL);
	while (env[delim] != '=' && env[delim])
		delim++;
	node_env->key = ft_substr(env, 0, delim);
	node_env->value = ft_substr(env, delim + 1, ft_strlen(env) - delim + 1);
	node_env->next = NULL;
	if (!node_env->key && !node_env->value)
		return (NULL);
	return (node_env);
}

t_mini	*save_env(char **env, int i)
{
	t_mini	*mini_env;
	t_mini	*node_env;
	t_mini	*node_last;

	mini_env = NULL;
	node_last = NULL;
	while (env[i])
	{
		node_env = init_node_mini_env(env[i++]);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:05:05 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/22 00:19:01 by jgoldste         ###   ########.fr       */
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

static void	add_env_end(t_mini **mini_env, t_mini **nd_env, t_mini **nd_last)
{
	if (!*mini_env)
		*mini_env = *nd_env;
	else
	{
		if (!(*mini_env)->next)
			(*mini_env)->next = *nd_env;
		else
			(*nd_last)->next = *nd_env;
		(*nd_last) = *nd_env;
	}
}

static t_mini	*init_node_mini_env(char *env)
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
	return (node_env);
}

t_mini	*save_env(char **env)
{
	t_mini	*mini_env;
	t_mini	*node_env;
	t_mini	*node_last;
	int		i;

	mini_env = NULL;
	node_last = NULL;
	i = 0;
	while (env[i])
	{
		if (env[i][0] == '\0')
			continue ;
		node_env = init_node_mini_env(env[i]);
		if (!node_env)
			if (!free_mini_list(mini_env))
				return (NULL);
		add_env_end(&mini_env, &node_env, &node_last);
		i++;
	}
	return (mini_env);
}

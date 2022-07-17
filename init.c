/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:32:49 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/17 20:41:31 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**save_path()
{
	char	*path_str;
	char	**path_array;

	path_str = getenv("PATH");
	if (!path_str)
	{
		write(STDERR_FILENO, "PATH not specified\n", 20);
		return (NULL);
	}
	path_array = ft_split(path_str, ':');
	if (!path_array)
		return (NULL);
	return (path_array);
}

char	*find_list(t_mini *mini_env, char *key, size_t len)
{
	t_mini	*fix;
	char    *ptr;

	fix = mini_env;
	while (mini_env)
	{
		if (mini_env->key)
		{
			if (!ft_strncmp(mini_env->key, key, len))
			{
				ptr = mini_env->value;
				mini_env = fix;
				return (ptr);
			}
		}
		mini_env = mini_env->next;
	}
	mini_env = fix;
	return (NULL);
}

t_shell	*init_minishell(t_mini *mini_env, char **path_array)
{
	t_shell	*minishell;

	minishell = (t_shell *)malloc(sizeof(t_shell));
	if (!minishell)
		return (NULL);
	minishell->mini_env = mini_env;
	minishell->path_array = path_array;
	minishell->mini_pwd = find_list(mini_env, "PWD", 3);
	minishell->mini_oldpwd = find_list(mini_env, "OLDPWD", 6);
	minishell->mini_home = find_list(mini_env, "HOME", 4);
	minishell->mini_shlvl = find_list(mini_env, "SHLVL", 5);
	return (minishell);
}

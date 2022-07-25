/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:32:49 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/25 22:14:08 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	*increase_shlvl(t_mini *shlvl)
{
	int	level;

	if (shlvl)
	{
		if (!shlvl->key || !shlvl->value)
			return (NULL);
		level = ft_atoi(shlvl->value);
		free(shlvl->value);
		shlvl->value = ft_itoa(level + 1);
		if (!shlvl->value)
			return (NULL);
		return(shlvl);
	}
	return (NULL);
}

char	**save_path(int argc, char **argv)
{
	char	*path_str;
	char	**path_array;

	(void)argc;
	(void)argv;
		path_str = getenv(PATH);
	if (!path_str)
		return (NULL);
	path_array = ft_split(path_str, ':');
	if (!path_array)
		return (NULL);
	return (path_array);
}

t_mini	*find_list(t_mini *mini_env, char *key, size_t len)
{
	t_mini	*fix;
	t_mini	*ptr;

	fix = mini_env;
	while (mini_env)
	{
		if (mini_env->key)
		{
			if (!ft_strncmp(mini_env->key, key, len))
			{
				ptr = mini_env;
				mini_env = fix;
				return (ptr);
			}
		}
		mini_env = mini_env->next;
	}
	mini_env = fix;
	return (NULL);
}

t_shell	*init_minishell(int argc, char **argv, char **env)
{
	t_shell	*minishell;

	minishell = (t_shell *)malloc(sizeof(t_shell));
	if (!minishell)
		return (NULL);
	minishell->tocken = NULL;
	minishell->mini_env = save_env(env);
	minishell->path_array = save_path(argc, argv);
	minishell->mini_pwd = find_list(minishell->mini_env, PWD, 3);
	minishell->mini_oldpwd = find_list(minishell->mini_env, OLD_PWD, 6);
	minishell->mini_home = find_list(minishell->mini_env, HOME, 4);
	minishell->mini_shlvl
		= increase_shlvl(find_list(minishell->mini_env, SH_LVL, 5));
	minishell->hist_file = get_hist_file_name(minishell);
	return (minishell);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:28 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/17 20:09:56 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	minishell()
// {
	
// }

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

int	main(int argc, char **argv, char **env)
{
	t_shell *minishell;
	t_mini	*mini_env;
	char	**path_array;

	(void)argc;
	(void)argv;
	path_array = save_path();
	if (!path_array)
		return (printf("PATH: malloc allocation error\n"));
	//*
	printf("\n\t[PATH]\n");
	for (int i = 0; path_array[i]; i++)
		printf("%s\n", path_array[i]);
	//*
	mini_env = save_env(env, 0);
	if (!mini_env)
		return (printf("ENV parse error, return value [%d]\n", free_array((void **)path_array) + 1));
	//*
	printf("\n\t[ENV]\n");
	print_env(mini_env);
	//*
	minishell = init_minishell(mini_env, path_array);
	if (!minishell)
		return (printf("Malloc allocation error, return value [%d]\n",
			free_array ((void **)path_array) + free_mini_list(mini_env)) + 1);
	//*
	printf("\n\t!!!MINISHELL!!!\n");
	printf("\n\t[PATH]\n");
	for (int i = 0; minishell->path_array[i]; i++)
		printf("%s\n", minishell->path_array[i]);
	printf("\n\t[ENV]\n");
	print_env(minishell->mini_env);
	printf("\n\t[DIRECTORIES\n");
	printf("PWD=%s\n", minishell->mini_pwd);
	printf("OLDPWD=%s\n", minishell->mini_oldpwd);
	printf("HOME=%s\n", minishell->mini_home);
	printf("SHLVL=%s\n", minishell->mini_shlvl);
	printf("\n");
	//*
	return (free_minishell(minishell));
}

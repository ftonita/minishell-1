/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:28 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/17 20:44:49 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	minishell()
// {
	
// }

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
	mini_env = save_env(env, 0);
	if (!mini_env)
		return (printf("ENV parse error, return value [%d]\n", free_array((void **)path_array) + 1));
	minishell = init_minishell(mini_env, path_array);
	if (!minishell)
		return (printf("Malloc allocation error, return value [%d]\n",
			free_array ((void **)path_array) + free_mini_list(mini_env)) + 1);
	if (!minishell->mini_pwd || !minishell->mini_oldpwd || !minishell->mini_home || !minishell->mini_shlvl)
		return (printf("Directories not found, return value [%d]\n",
			free_minishell(minishell) + 1));
	//*
	printf("\n\t!!!MINISHELL!!!\n");
	printf("\n\t[PATH]\n");
	for (int i = 0; minishell->path_array[i]; i++)
		printf("%s\n", minishell->path_array[i]);
	printf("\n\t[ENV]\n");
	print_env(minishell->mini_env);
	printf("\n\t[DIRECTORIES]\n");
	printf("PWD=%s\n", minishell->mini_pwd);
	printf("OLDPWD=%s\n", minishell->mini_oldpwd);
	printf("HOME=%s\n", minishell->mini_home);
	printf("SHLVL=%s\n", minishell->mini_shlvl);
	printf("\n");
	//*
	return (free_minishell(minishell));
}

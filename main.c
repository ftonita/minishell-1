/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:28 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/22 06:02:43 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*minishell;
	t_mini	*mini_env;
	char	**path_array;

	(void)argc;
	(void)argv;
	path_array = save_path();
	if (!path_array)
		return (EXIT_FAILURE);
	mini_env = save_env(env);
	if (!mini_env)
		return (init_error(NULL, mini_env, (void **)path_array, 1)
			+ EXIT_FAILURE);
	minishell = init_minishell(mini_env, path_array);
	if (!minishell)
		return (init_error(NULL, mini_env, (void **)path_array, 2)
			+ EXIT_FAILURE);
	if (!minishell->mini_pwd || !minishell->mini_oldpwd
		|| !minishell->mini_home || !minishell->mini_shlvl
		|| !minishell->hist_file)
		return (init_error(minishell, NULL, NULL, 3));
	print_env(minishell->mini_env);
	printf("\nHISTORY_FILE_NAME = [%s]\n", minishell->hist_file);
	// read_loop(minishell);
	return (free_minishell(minishell));
}

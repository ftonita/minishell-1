/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:28 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/25 22:11:02 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*minishell;

	minishell = init_minishell(argc, argv, env);
	if (!minishell)
		return (init_error(minishell, 1) + EXIT_FAILURE);
	if (!minishell->mini_env)
		return (init_error(minishell, 2) + EXIT_FAILURE);
	if (!minishell->path_array)
		return (init_error(minishell, 3) + EXIT_FAILURE);
	if (!minishell->mini_pwd || !minishell->mini_oldpwd
		|| !minishell->mini_home)
		return (init_error(minishell, 4) + EXIT_FAILURE);
	if (!minishell->mini_shlvl)
		return (init_error(minishell, 5) + EXIT_FAILURE);
	if (!minishell->mini_shlvl->value)
		return (init_error(minishell, 5) + EXIT_FAILURE);
	if (!minishell->hist_file)
		return (init_error(minishell, 6) + EXIT_FAILURE);
	print_env(minishell->mini_env);
	printf("\nHISTORY_FILE_NAME=[%s]\n", minishell->hist_file);
	// read_loop(minishell);
	return (free_minishell(minishell));
}

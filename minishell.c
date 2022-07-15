/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:28 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/16 01:49:46 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	minishell()
// {
	
// }

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini_env;

	(void)argc;
	(void)argv;
	mini_env = save_env(env, 0);
	if (!mini_env)
		return (printf("ENV parse error\n"));
	print_env(mini_env);
	return (free_mini_list(mini_env));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:28 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/15 19:05:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini_env;

	(void)argc;
	(void)argv;
	mini_env = save_env(env, -1);
	if (!mini_env)
		return (printf("ENV parse error\n"));
	return (free_mini_list(mini_env));
}


	// t_mini	*fix;
	// fix = mini_env;
	// while (mini_env)
	// {
	// 	printf("%s=%s\n", mini_env->key, mini_env->value);
	// 	mini_env = mini_env->next;
	// }
	// mini_env = fix;
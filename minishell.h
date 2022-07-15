/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:56:11 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/16 01:48:11 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_mini
{
	char			*key;
	char			*value;
	struct s_mini	*next;
}	t_mini;

//env.c
t_mini	*save_env(char **env, int i);
t_mini	*init_node_mini_env(char *env);
void	print_env(t_mini *mini_env);

//free_utils.c
void	free_array(void **array);
int		free_mini_list(t_mini *node);

#endif
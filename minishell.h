/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:56:11 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/15 19:07:04 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mini
{
	char			*key;
	char			*value;
	struct s_mini	*next;
	// struct s_mini	*last;
}	t_mini;

//env.c
t_mini	*save_env(char **env, int i);
t_mini	*init_node_mini_env(char **env, int i);

//free_utils.c
int	free_mini_list(t_mini *node);

#endif
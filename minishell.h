/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:56:11 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/17 20:34:15 by jgoldste         ###   ########.fr       */
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

typedef struct s_shell
{
	t_mini          *mini_env;
	char			**path_array;
	char			*mini_pwd;
	char            *mini_oldpwd;
	char            *mini_home;
	char            *mini_shlvl;
}	t_shell;

//init.c
char	**save_path();
t_shell	*init_minishell(t_mini *mini_env, char **path_array);
char	*find_list(t_mini *mini_env, char *key, size_t len);

//env.c
t_mini	*save_env(char **env, int i);
t_mini	*init_node_mini_env(char *env);
void	print_env(t_mini *mini_env);

//free_utils.c
int		free_array(void **array);
int		free_mini_list(t_mini *node);
int		free_minishell(t_shell *minishell);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:56:11 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/25 22:27:05 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "constants.h"
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
	t_mini	*tocken;
	t_mini	*mini_env;
	t_mini	*mini_pwd;
	t_mini	*mini_oldpwd;
	t_mini	*mini_home;
	t_mini	*mini_shlvl;
	char	**path_array;
	char	*hist_file;
}	t_shell;

//init.c
char	**save_path(int argc, char **argv);
t_shell	*init_minishell(int argc, char **argv, char **env);
t_mini	*find_list(t_mini *mini_env, char *key, size_t len);
t_mini	*increase_shlvl(t_mini *shlvl);

//history.c
char	*get_hist_file_name(t_shell *minishell);

//env.c
t_mini	*save_env(char **env);
void	print_env(t_mini *mini_env);

//cd.c
int		cd(char *cd_path);

//free_utils.c
int		free_array(void **array);
int		free_mini_list(t_mini *node);
int		free_minishell(t_shell *minishell);

//error.c
int		init_error(t_shell *shell, int err);

//parser.c
void	read_loop(t_shell *minishell);
void	mini_parser(t_shell *minishell, char *line);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:22:11 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/22 05:35:26 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_hist_file_name(t_shell *minishell)
{
	char	*path;
	char	*filename;
	
	if (!minishell->mini_shlvl || !minishell->mini_home)
		return (NULL);
	path = ft_strjoin(minishell->mini_home->value, HIST_FILE);
	if (!path)
		return (NULL);
	filename = ft_strjoin(path, minishell->mini_shlvl->value);
	free(path);
	if (!filename)
		return (NULL);
	return (filename);
}

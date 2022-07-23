/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:03:32 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/22 00:52:59 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_error(t_shell *shell, t_mini *list, void **array, int err)
{
	if (err == 1)
		write(STDERR_FILENO, "Environment init: parsing error\n", 33);
	else if (err == 2)
		write(STDERR_FILENO, "Environment init: malloc allocation error\n", 43);
	else if (err == 3)
		write(STDERR_FILENO, "Environment init: directories not found\n", 41);
	else if (err == 4)
		write(STDERR_FILENO, "Environment init: shell level error\n", 37);
	else if (err == 5)
		write(STDERR_FILENO, "Environment init: history file error\n", 38);
	if (shell)
		return (free_minishell(shell));
	if (array)
		free_array(array);
	if (list)
		free_mini_list(list);
	return (0);
}
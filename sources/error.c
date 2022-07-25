/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:03:32 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/25 22:22:25 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_error(t_shell *shell, int err)
{
	if (err == 1)
		write(STDERR_FILENO, "Environment init: malloc allocation error\n", 43);
	else if (err == 2)
		write(STDERR_FILENO, "Environment init: environment saving error\n", 44);
	else if (err == 3)
		write(STDERR_FILENO, "Environment init: path init error\n", 35);
	else if (err == 4)
		write(STDERR_FILENO, "Environment init: directories not found\n", 41);
	else if (err == 5)
		write(STDERR_FILENO, "Environment init: shell level error\n", 37);
	else if (err == 6)
		write(STDERR_FILENO, "Environment init: history file error\n", 38);
	else if (err == 7)
		write(STDERR_FILENO, "Parser: readline / tocken creation error\n", 42);
	if (shell)
		return (free_minishell(shell));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:47:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/07/18 23:19:15 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char *cd_path)
{
	if (chdir(cd_path) == -1)
	{
		printf("No file or directory: %s\n", cd_path);
		return (1);
	}
	printf("Directory change: %s\n", cd_path);
	return (0);
}

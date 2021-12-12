/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:39:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 00:42:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "hotrace.h"
#include "t_keyval.h"

static void	__print_keyval(char const *key, char const *val)
{
	if (val)
		write(STDOUT_FILENO, val, hr_strlen(val));
	else
	{
		write(STDOUT_FILENO, key, hr_strlen(key));
		write(STDOUT_FILENO, ": Not found.", 12);
	}
	write(STDOUT_FILENO, "\n", 1);
}

static int	__process(char const **const line, char const **const val,
	t_keyval **const map)
{
	if (hr_keyval_search(*line, val, map))
	{
		free((void *)*line);
		return (EXIT_FAILURE);
	}
	__print_keyval(*line, *val);
	return (EXIT_SUCCESS);
}

int	hr_search(t_keyval **const map)
{
	char const	*line;
	char const	*val;
	int			ret;

	ret = hr_gnl(&line);
	while (ret == 1)
	{
		if (__process(&line, &val, map))
			return (EXIT_FAILURE);
		free((void *)line);
		ret = hr_gnl(&line);
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	if (*line && __process(&line, &val, map))
		return (EXIT_FAILURE);
	free((void *)line);
	return (EXIT_SUCCESS);
}

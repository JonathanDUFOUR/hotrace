/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:36:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 04:05:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"
#include "t_store.h"

static int	__process(char const **const key, char const **const val,
	t_store *const db)
{
	if (*val)
	{
		if (hr_store_keyval(*key, *val, db))
		{
			free((void *)*key);
			free((void *)*val);
			return (EXIT_FAILURE);
		}
		hr_memdel(key);
		*val = NULL;
	}
	return (EXIT_SUCCESS);
}

int	hr_store(t_store *const db)
{
	char const	*line = NULL;
	char const	*key = NULL;
	char const	*val = NULL;
	static int	tog = 1;
	int			ret;

	ret = hr_gnl(&line);
	while (ret == 1)
	{
		if (!*line)
			break ;
		if (tog)
			key = line;
		else
			val = line;
		if (__process(&key, &val, db))
			return (EXIT_FAILURE);
		tog ^= 1;
		ret = hr_gnl(&line);
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	free((void *)line);
	free((void *)key);
	return (EXIT_SUCCESS);
}

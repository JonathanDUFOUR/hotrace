/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:14:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 00:41:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "hotrace.h"
#include "t_keyval.h"

static int	__error_quit(t_keyval **const map)
{
	char const	*str = strerror(errno);

	hr_map_clear(map);
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, str, hr_strlen(str));
	return (EXIT_FAILURE);
}

int	main(void)
{
	t_keyval	*map[MAP_SIZE];

	hr_bzero(map, sizeof(map));
	if (hr_store(map) || hr_search(map))
		return (__error_quit(map));
	hr_map_clear(map);
	return (EXIT_SUCCESS);
}

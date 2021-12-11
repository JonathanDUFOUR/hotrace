/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:14:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 22:47:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "hotrace.h"
#include "t_store.h"

static int	__error_quit(t_store *const db)
{
	char const	*str = strerror(errno);

	if (db)
		hr_clear_data(db);
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, str, hr_strlen(str));
	return (EXIT_FAILURE);
}

int	main(void)
{
	t_store *const	db = (t_store *)hr_calloc(1, sizeof(t_store));

	if (!db)
		return (__error_quit(NULL));
	if (hr_store(db) || hr_search(db))
		return (__error_quit(db));
	hr_clear_data(db);
	return (EXIT_SUCCESS);
}

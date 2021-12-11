/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 00:43:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "hotrace.h"

static int	__update_buff(char *buff)
{
	char	*ptr;

	ptr = hr_strchr(buff, '\n') + 1;
	while (*ptr)
		*buff++ = *ptr++;
	*buff = 0;
	return (1);
}

int	hr_gnl(char const **const line)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	char const	*tmp;
	ssize_t		rd;

	if (read(STDIN_FILENO, buff, 0) == -1)
		return (-1);
	*line = hr_strcdup(buff, '\n');
	if (hr_strchr(buff, '\n'))
		return (__update_buff(buff));
	rd = read(STDIN_FILENO, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[rd] = 0;
		tmp = *line;
		*line = hr_strcjoin(*line, buff, '\n');
		hr_memdel(&tmp);
		if (!*line)
			return (-1);
		if (hr_strchr(buff, '\n'))
			return (__update_buff(buff));
		rd = read(STDIN_FILENO, buff, BUFFER_SIZE);
	}
	return (0);
}

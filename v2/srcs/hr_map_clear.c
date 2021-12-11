/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:09:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 00:42:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"
#include "t_keyval.h"

void	hr_map_clear(t_keyval **const map)
{
	unsigned int		i;
	register t_keyval	*node;
	t_keyval			*next;

	i = 0;
	while (i < MAP_SIZE)
	{
		node = map[i];
		while (node)
		{
			next = node->next;
			free((void *)node->key);
			free((void *)node->val);
			free(node);
			node = next;
		}
		++i;
	}
}

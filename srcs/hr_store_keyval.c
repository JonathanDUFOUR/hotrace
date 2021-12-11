/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_store_keyval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:01:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 19:53:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"
#include "t_store.h"

int	hr_store_keyval(char const *key, char const *val, t_store *const db)
{
	unsigned int	idx;

	if (*key)
	{
		idx = (unsigned char)*key;
		if (!db->next[idx])
		{
			db->next[idx] = hr_calloc(1, sizeof(t_store));
			if (!db->next[idx])
				return (EXIT_FAILURE);
		}
		if (hr_store_keyval(key + 1, val, db->next[idx]))
			return (EXIT_FAILURE);
	}
	else
	{
		free((void *)db->value);
		db->value = val;
	}
	return (EXIT_SUCCESS);
}

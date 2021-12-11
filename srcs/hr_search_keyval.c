/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_search_keyval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:17:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 03:22:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_store.h"

int	hr_search_keyval(char const *key, char const **const val, t_store *const db)
{
	unsigned int	idx;

	if (*key)
	{
		idx = (unsigned char)*key % (CHAR_MAX + 1);
		if (!db->next[idx])
		{
			*val = NULL;
			return (EXIT_SUCCESS);
		}
		if (hr_search_keyval(key + 1, val, db->next[idx]))
			return (EXIT_FAILURE);
	}
	else
		*val = db->value;
	return (EXIT_SUCCESS);
}

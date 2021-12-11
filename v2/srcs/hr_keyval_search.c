/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_keyval_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:17:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 00:43:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"
#include "t_keyval.h"

static void	__browse_lst(char const *key, char const **const val,
	t_keyval const *lst)
{
	while (lst)
	{
		if (!hr_strcmp(key, lst->key))
		{
			*val = lst->val;
			return ;
		}
		lst = lst->next;
	}
	*val = NULL;
}

int	hr_keyval_search(char const *key, char const **const val,
	t_keyval **const map)
{
	register unsigned int	hash;
	register char const		*str = key;

	hash = 0;
	while (*str)
	{
		hash *= 31;
		hash += *str;
		++str;
	}
	hash %= MAP_SIZE;
	__browse_lst(key, val, map[hash]);
	return (EXIT_SUCCESS);
}

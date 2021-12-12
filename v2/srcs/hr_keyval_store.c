/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_keyval_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:01:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 02:02:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"
#include "t_keyval.h"

static int	__update_lst(char const *key, char const *val, t_keyval *lst)
{
	t_keyval	*node;
	t_keyval	*tail;

	tail = NULL;
	while (lst)
	{
		if (!hr_strcmp(key, lst->key))
		{
			free((void *)key);
			free((void *)lst->val);
			lst->val = val;
			return (EXIT_SUCCESS);
		}
		tail = lst;
		lst = lst->next;
	}
	node = malloc(sizeof(t_keyval));
	if (!node)
		return (EXIT_FAILURE);
	node->key = key;
	node->val = val;
	node->next = NULL;
	tail->next = node;
	return (EXIT_SUCCESS);
}

int	hr_keyval_store(char const *key, char const *val, t_keyval **const map)
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
	if (!map[hash])
	{
		map[hash] = hr_keyval_new(key, val);
		if (!map[hash])
			return (EXIT_FAILURE);
	}
	else
	{
		if (__update_lst(key, val, map[hash]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

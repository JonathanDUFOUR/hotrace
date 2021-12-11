/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/12/11 12:11:29 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

unsigned int	hash(char const *key, size_t const size_database,
ssize_t const len)
{
	unsigned int	h;
	ssize_t			i;

	i = 0;
	h = PRIME_1;
	while (i < len)
	{
		h = (h * PRIME_2 + key[i]) % size_database;
		i++;
	}
	return (h);
}

char	type_entry(char *line, size_t *length_key)
{
	if (line[0] == '!')
		return (DELETE);
	else if (contains_equal('=', line, length_key))
		return (ENTRY);
	else
		return (SEARCH);
}

t_data const	*get_data(t_list const *table)
{
	return ((t_data *)(table->content));
}

bool	is_in_table(t_list **table, char const *key, ssize_t const len)
{
	t_list	*tmp;
	t_list	*start;

	start = table[hash(key, SIZE_DATABASE, len)];
	if (start)
	{
		tmp = start;
		while (tmp)
		{
			if (!strcmp(key, get_data(tmp)->key))
				return (true);
			tmp = tmp->next;
		}
	}
	return (false);
}

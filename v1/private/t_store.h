/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_store.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:46:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 19:55:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STORE_H
# define T_STORE_H

# include <limits.h>

typedef struct s_store	t_store;

struct s_store
{
	char const	*value;
	t_store		*next[UCHAR_MAX + 1];
};

int		hr_search(t_store *const db)
		__attribute__((nonnull));
int		hr_search_keyval(char const *key, char const **const val,
			t_store *const db)
		__attribute__((nonnull));
int		hr_store(t_store *const db)
		__attribute__((nonnull));
int		hr_store_keyval(char const *key, char const *val, t_store *const db)
		__attribute__((nonnull));

void	hr_clear_data(t_store *const db)
		__attribute__((nonnull));

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keyval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:46:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 00:44:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_KEYVAL_H
# define T_KEYVAL_H

# include <limits.h>

typedef struct s_keyval	t_keyval;

struct s_keyval
{
	char const	*key;
	char const	*val;
	t_keyval	*next;
};

int			hr_keyval_search(char const *key, char const **const val,
				t_keyval **const map)
			__attribute__((nonnull));
int			hr_keyval_store(char const *key, char const *val,
				t_keyval **const map)
			__attribute__((nonnull));
int			hr_search(t_keyval **const map)
			__attribute__((nonnull));
int			hr_store(t_keyval **const map)
			__attribute__((nonnull));

void		hr_map_clear(t_keyval **const map)
			__attribute__((nonnull));

t_keyval	*hr_keyval_new(char const *const key, char const *const val)
			__attribute__((nonnull));

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/12/11 13:36:59 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# include "linked_list.h"

# define SIZE_DATABASE	1242419
# define PRIME_1		13
# define PRIME_2		31

# define MAX_CHAR	126
# define MIN_CHAR	32

# define ENTRY		'E'
# define SEARCH		'S'
# define DELETE		'D'

typedef struct s_data
{
	char	*key;
	char	*value;
}			t_data;

int				contains_equal(char const c, char const *charset, size_t *pos);
void			free_data(void *content);
void			set_data(t_data **data, char *line, size_t length_key);
t_list			**init_table(void);
void			free_table(t_list **table);

unsigned int	hash(char const *key, size_t const size_database,
					ssize_t const len);
char			type_entry(char *line, size_t *length_key);
t_data const	*get_data(t_list const *table);
bool			is_in_table(t_list **table, char const *key, ssize_t const len);

#endif

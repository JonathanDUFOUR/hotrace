/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:38:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 00:49:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

# ifndef MAP_SIZE
#  define MAP_SIZE		65536U
# endif

int		hr_gnl(char const **const line)
		__attribute__((nonnull));
int		hr_strcmp(char const *s0, char const *s1)
		__attribute__((nonnull));

void	hr_bzero(void *addr, size_t size)
		__attribute__((nonnull (1)));

char	*hr_strcdup(char const *str, char const c)
		__attribute__((nonnull (1)));
char	*hr_strchr(char const *str, char const c)
		__attribute__((nonnull (1)));
char	*hr_strcjoin(char const *s0, char const *s1, char const c)
		__attribute__((nonnull (1, 2)));

size_t	hr_strlen(char const *str)
		__attribute__((nonnull));

#endif

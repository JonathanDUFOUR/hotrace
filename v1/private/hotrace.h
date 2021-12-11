/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:38:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 03:44:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

int		hr_gnl(char const **const line)
		__attribute__((nonnull));

void	hr_bzero(void *addr, size_t size)
		__attribute__((nonnull (1)));
void	hr_memdel(void *addr)
		__attribute__((nonnull));

void	*hr_calloc(size_t n, size_t size);

char	*hr_strcdup(char const *str, char const c)
		__attribute__((nonnull (1)));
char	*hr_strchr(char const *str, char const c)
		__attribute__((nonnull (1)));
char	*hr_strcjoin(char const *s0, char const *s1, char const c)
		__attribute__((nonnull (1, 2)));

size_t	hr_strlen(char const *str)
		__attribute__((nonnull));

#endif

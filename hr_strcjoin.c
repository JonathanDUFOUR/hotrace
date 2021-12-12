/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:19:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 01:02:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

char	*hr_strcjoin(char const *s0, char const *s1, char const c)
{
	char	*output;
	char	*ptr;
	size_t	len;

	ptr = hr_strchr(s0, c);
	if (!ptr)
		ptr = hr_strchr(s0, 0);
	len = ptr - s0;
	ptr = hr_strchr(s1, c);
	if (!ptr)
		ptr = hr_strchr(s1, 0);
	len += ptr - s1;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (*s0 && *s0 != c)
		*ptr++ = *s0++;
	while (*s1 && *s1 != c)
		*ptr++ = *s1++;
	*ptr = 0;
	return (output);
}

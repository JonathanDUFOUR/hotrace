/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:05:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 00:13:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

char	*hr_strcdup(char const *str, char const c)
{
	char	*output;
	char	*ptr;

	ptr = hr_strchr(str, c);
	if (!ptr)
		ptr = hr_strchr(str, 0);
	output = malloc((ptr - str + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (*str && *str != c)
		*ptr++ = *str++;
	*ptr = 0;
	return (output);
}

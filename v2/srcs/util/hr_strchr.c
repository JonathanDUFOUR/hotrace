/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:09:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 00:10:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*hr_strchr(char const *str, char const c)
{
	while (*str && *str != c)
		++str;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:15:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/12 00:22:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hr_strcmp(char const *s0, char const *s1)
{
	register unsigned char const	*p0 = (unsigned char *)s0;
	register unsigned char const	*p1 = (unsigned char *)s1;

	while (*p0 && *p0 == *p1)
	{
		++p0;
		++p1;
	}
	return (*p0 - *p1);
}

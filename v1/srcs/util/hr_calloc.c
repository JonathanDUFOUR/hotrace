/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:48:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 02:50:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

void	*hr_calloc(size_t n, size_t size)
{
	void	*output;

	output = malloc(n * size);
	if (!output)
		return (NULL);
	hr_bzero(output, n * size);
	return (output);
}

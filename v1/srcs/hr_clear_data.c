/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:09:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/11 19:54:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_store.h"

void	hr_clear_data(t_store *const root)
{
	int	i;

	i = 0;
	while (i < UCHAR_MAX + 1)
	{
		if (root->next[i])
			hr_clear_data(root->next[i]);
		++i;
	}
	free((void *)root->value);
	free(root);
}

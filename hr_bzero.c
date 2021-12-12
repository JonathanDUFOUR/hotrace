/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:19:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/10 23:28:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void	hr_bzero(void *addr, size_t size)
{
	while (size >= sizeof(uint64_t))
	{
		*(uint64_t *)addr = (uint64_t)0;
		addr += sizeof(uint64_t);
		size -= sizeof(uint64_t);
	}
	if (size >= sizeof(uint32_t))
	{
		*(uint32_t *)addr = (uint32_t)0;
		addr += sizeof(uint32_t);
		size -= sizeof(uint32_t);
	}
	if (size >= sizeof(uint16_t))
	{
		*(uint16_t *)addr = (uint16_t)0;
		addr += sizeof(uint16_t);
		size -= sizeof(uint16_t);
	}
	if (size)
		*(uint8_t *)addr = (uint8_t)0;
}

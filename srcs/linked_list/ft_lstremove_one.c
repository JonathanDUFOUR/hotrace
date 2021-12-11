/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:56:00 by hthomas           #+#    #+#             */
/*   Updated: 2021/12/11 13:35:35 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/linked_list.h"

/*
** Remove the node 'lst' of the list and return it.
** @param lst	The address of the node to remove from the list.
** @return		The address of the node removed from the list.
*/

t_list	*ft_lstremove_one(t_list **alst, t_list *lst)
{
	t_list	*tmp;

	if (!*alst || !lst)
		return (NULL);
	if (*alst == lst)
	{
		if (*alst == (*alst)->next)
		{
			*alst = NULL;
			return (lst);
		}
		*alst = lst->next;
	}
	else
	{
		tmp = *alst;
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
	}
	lst->next = NULL;
	return (lst);
}

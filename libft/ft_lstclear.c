/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:40:16 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 15:27:45 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (lst == NULL || del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		curr = *lst;
		(*lst) = (*lst)->next;
		del (curr -> content);
		free ((curr));
	}
	return ;
}

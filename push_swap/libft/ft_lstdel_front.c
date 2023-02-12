/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:34:28 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/01/30 02:19:05 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstdel_front(t_list *lst)
// {
// 	t_list	*ptr;

// 	ptr = lst;
// 	lst->next = ptr->next->next;
// 	free(ptr->next);
// }

void	ft_lstdel_front(t_list **lst)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = (*lst);
	tmp = ptr->next;
	free(ptr);
	*lst = tmp;
}

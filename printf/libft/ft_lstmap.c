/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:15:11 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 19:45:11 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	t_list	*ptr;

	ptr = lst;
	result = NULL;
	while (ptr)
	{
		tmp = ft_lstnew((*f)(ptr->content));
		if (!tmp)
		{
			ft_lstclear(&result, del);
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp);
		ptr = ptr -> next;
	}
	return (result);
}

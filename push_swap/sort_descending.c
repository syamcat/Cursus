/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_descending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:40:15 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/22 14:42:41 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_sort_descending_2(t_list *stack)
{
	t_list	*ptr;
	int		tmp[2];

	ptr = stack;
	tmp[0] = ptr->content;
	ptr = ptr->next;
	tmp[1] = ptr->content;
	if (tmp[0] < tmp[1]) // top->12
		return (1);
	return (0);
}

void	sort_descending_2(t_list **stack)
{
	int	Sequence;

	Sequence = how_sort_descending_2(*stack);
	if (Sequence == 0) // top->21 (complete)
		return ;
	else if (Sequence == 1) // top->12
		sb(stack);
}

int	how_sort_descending_3(t_list *stack)
{
	t_list	*ptr;
	int		tmp[3];

	ptr = stack;
	tmp[0] = ptr->content;
	ptr = ptr->next;
	tmp[1] = ptr->content;
	ptr = ptr->next;
	tmp[2] = ptr->content;
	// printf("tmp[0]: %d, tmp[1]: %d, tmp[2]: %d\n", tmp[0], tmp[1], tmp[2]);
	if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
		return (0);
	else if (tmp[0] < tmp[1] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
		return (1);
	else if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] < tmp[2])
		return (2);
	else if (tmp[0] < tmp[1] && tmp[0] < tmp[2] && tmp[1] > tmp[2])
		return (3);
	else if (tmp[0] > tmp[1] && tmp[0] < tmp[2] && tmp[1] < tmp[2])
		return (4);
	else if (tmp[0] < tmp[1] && tmp[0] < tmp[2] && tmp[1] < tmp[2])
		return (5);
	return (0);
}

void	sort_descending_3(t_list **stack)
{
	int	Sequence;

	Sequence = how_sort_descending_3(*stack);
	if (Sequence == 0) // top->123 (complete)
		return ;
	else if (Sequence == 1) // top->213
		swap(stack);
	else if (Sequence == 2) // top->132
	{
		rev_rotate(stack);
		swap(stack);
	}
	else if (Sequence == 3) // top->312
		rotate(stack);
	else if (Sequence == 4) // top->231
		rev_rotate(stack);
	else if (Sequence == 5) // top->321
	{
		swap(stack);
		rev_rotate(stack);
	}
	return ;
}

void	sort_descending(t_list **stack)
{
	int	count;

	count = ft_lstsize(*stack);
	if (count == 1)
		return ;
	if (count == 2)
		sort_descending_2(stack);
	// else if (count == 3)
	if (count == 3)
		sort_descending_3(stack);
}

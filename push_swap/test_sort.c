/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:33:51 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/19 20:40:36 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_sort_b(t_list **stack_a, t_list **stack_b, int com)
{
	int	smallest;
	int	count_pa;
	int	tmp;
	t_list	*ptr;

	if (com == 0)
		test_sort_a(stack_a, stack_b, com);
	smallest = select_smallest(*stack_b, com);
	count_pa = 0;
	while (com--)
	{
		tmp = (*stack_b)->content;
		if (tmp > smallest)
			count_pa += pa(stack_b, stack_a);
		else
			rb(stack_b);
	}
	if (ft_lstsize(*stack_b) > 1)
		rrb(stack_b);
	test_sort_a(stack_a, stack_b, count_pa);
}

void	test_sort_a(t_list **stack_a, t_list **stack_b, int com)
{
	int	biggest;
	int count_pb;
	int	tmp;
	t_list	*ptr;

	if (com == 0)
	{
		ptr = (*stack_b);
		while (ptr)
		{
			pa(stack_b, stack_a);
			ptr = (*stack_b)->next;
		}
		pa(stack_b, stack_a);
		return ;
	}
	biggest = select_biggest(*stack_a, com);
	count_pb = 0;
	while (com--)
	{
		tmp = (*stack_a)->content;
		if (tmp < biggest)
			count_pb += pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (ft_lstsize(*stack_a) > 1)
		rra(stack_a);
	test_sort_b(stack_a, stack_b, count_pb);
}

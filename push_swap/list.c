/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:18:38 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/12 19:53:59 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(void)
{
	t_list	*tmp;

	tmp  = (t_list *)malloc(sizeof(t_list));	
	if (tmp)
	{
		tmp->content = 0;
		tmp->next = NULL;
	}
	return (tmp);
}

// void	free_stack(t_list *stack)
// {
//		t_list	*ptr;
// 		if (stack)
// 		{
// 			while (stack->next->next)
// 				stack = stack->next;
// 			while (stack->prev)
// 			{
// 				free(stack->next);
// 				stack = stack->prev;
// 			}
// 			free(ptr);
// 		}
// }

void	set_stack_a(t_list *stack_a, int argc, char *argv[])
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (idx == 1)
		{
			stack_a->content = ft_atoi(argv[idx]);
			idx++;
			continue;
		}
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[idx])));
		// printf("add_here: %d\n", stack_a->content);
		idx++;
	}
}

// test function
void print_list(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = stack_a;
	ptr_b = stack_b;
	printf("stack_a: ");
	for (;ptr_a;ptr_a = ptr_a->next)
		printf("%d -> ", ptr_a->content);
	printf("\nstack_b: ");
	for (;ptr_b;ptr_b = ptr_b->next)
		printf("%d -> ", ptr_b->content);
	printf("\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:18:38 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/24 19:42:52 by dohyeoki         ###   ########.fr       */
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

void	set_stack_a(t_list *stack_a, int argc, char *argv[])
{
	int	i;
	int	j;
	int	size;
	char **cont;

	i = 1;
	while (i < argc)
	{
		cont = ft_split(argv[i] , ' ');
		j = 0;
		if (i == 1)
		{
			if (cont) // 수정의 여지 있음 (cont[j]로 할지)
				stack_a->content = ft_atoi(cont[j]);
			i++;
			continue;
		}
		while (cont[j])
		{
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(cont[j])));
			j++;
		}
		free(cont);
		// printf("add_here: %d\n", stack_a->content);
		i++;
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
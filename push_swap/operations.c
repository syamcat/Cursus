/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:01:01 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/12 14:03:27 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if ((*stack)->next == NULL) // 예외처리
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

int	sa(t_list **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	swap(stack_a);
	// ft_putstr_fd("sa\n", 1);
	return (1);
}

int	sb(t_list **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL)
		return (0);
	swap(stack_b);
	// ft_putstr_fd("sb\n", 1);
	return (1);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	swap(stack_a);
	if (stack_b == NULL || *stack_b == NULL)
		return (0);
	swap(stack_b);
	// ft_putstr_fd("ss\n", 1);
	return (1);
}

void	push(t_list **stack_frm, t_list **stack_dst)
{
	t_list	*ptr_frm;
	// t_list	*ptr_dst;

	ptr_frm = *stack_frm;
	// ptr_dst = *stack_dst;
	ft_lstadd_front(stack_dst, ft_lstnew(ptr_frm->content));
	ft_lstdel_front(stack_frm);
}

int	pa(t_list **stack_b, t_list **stack_a)
{
	if (stack_b == NULL || *stack_b == NULL)
		return (0);
	push(stack_b, stack_a);
	// ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	push(stack_a, stack_b);
	// ft_putstr_fd("pb\n", 1);
	return (1);
}

void	rotate(t_list **stack)
{
	// int		tmp;
	t_list		*ptr;

	ptr = (*stack);
	ft_lstadd_back(stack, ft_lstnew(ptr->content));
	ft_lstdel_front(stack);
	// tmp = (*stack)->content;
	// ft_lstdel_front(stack);
	// ft_lstadd_back(stack, ft_lstnew(tmp));
}

int	ra(t_list **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	rotate(stack_a);
	// ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rb(t_list **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL)
		return (0);
	rotate(stack_b);
	// ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	rotate(stack_a);
	if (stack_b == NULL || *stack_b == NULL)
		return (0);
	rotate(stack_b);
	// ft_putstr_fd("rr\n", 1);
	return (1);
}

void	rev_rotate(t_list **stack)
{
	t_list	*ptr;
	t_list	*tmp;

	if ((*stack)->next == NULL) // 예외처리
		return ;
	ptr = ft_lstlast(*stack);
	tmp = (*stack);
	ft_lstadd_front(stack, ft_lstnew(ptr->content));
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	free(ptr);
}

int	rra(t_list **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	rev_rotate(stack_a);
	// ft_putstr_fd("rra\n", 1);
	return (1);
}

int	rrb(t_list **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL)
		return (0);
	rev_rotate(stack_b);
	// ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	rev_rotate(stack_a);
	if (stack_b == NULL || *stack_b == NULL)
		return (0);
	rev_rotate(stack_b);
	// ft_putstr_fd("rrr\n", 1);
	return (1);
}

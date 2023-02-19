/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:34:37 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/19 21:01:42 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"
// number of error
# define ARGU_ERR 1
# define ALLO_ERR 2
# define DUP_ERR  3

typedef struct  s_list  t_list;

// test
# include <stdio.h>
void	print_list(t_list *stack_a, t_list *stack_b);
//test_sort.c
void	test_sort_b(t_list **stack_a, t_list **stack_b, int com);
void	test_sort_a(t_list **stack_a, t_list **stack_b, int com);

// push_swap.c
// void	sort_stack_b(t_list **stack_a, t_list **stack_b, int com, int i, int j);
void	sort_stack_a(t_list **stack_a, t_list **stack_b, int com, int i, int j);
void 	qs_swap(int *a, int *b);
void 	quickSort(int *result,int start, int end);
int		*presort(t_list *stack, int count);
int		*select_pivot(t_list *stack, int count);
int		select_smallest(t_list *stack, int count);
int		select_biggest(t_list *stack, int count);
void	push_swap(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack);
int		intncmp(int *i1, int *i2, int num);


// list.c
t_list	*init_stack(void);
// t_list	*init_stack(t_list *tmp);
void	set_stack_a(t_list *stack_a, int argc, char *argv[]);
// operation.c
void	swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_frm, t_list **stack_dst);
int		pa(t_list **stack_b, t_list **stack_a);
int		pb(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
void	rev_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
// error.c
void	chk_arg(int argc, char *argv[]);
int		isvaild(int rec, int *arr);
void	error(int err);
// sort_ascending.c
void	sort_ascending(t_list **stack);
void	sort_ascending_3(t_list **stack);
int		how_sort_ascending_3(t_list *stack);
void	sort_ascending_2(t_list **stack);
int		how_sort_ascending_2(t_list *stack);
// sort_descending.c
int		how_sort_descending_2(t_list *stack);
void	sort_descending_2(t_list **stack);
int		how_sort_descending_3(t_list *stack);
void	sort_descending_3(t_list **stack);
void	sort_descending(t_list **stack);

#endif
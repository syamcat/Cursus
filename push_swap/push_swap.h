/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:34:37 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/22 15:29:52 by dohyeoki         ###   ########.fr       */
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
int		select_smallest(t_list *stack, int count);			// 스택에서 제일 작을 값을 반환하는 함수
int		select_biggest(t_list *stack, int count);			// 스택에서 제일 큰 값을 선택하는 함수

// push_swap.c
// void	sort_stack_b(t_list **stack_a, t_list **stack_b, int com, int i, int j);
int		push_to_stack_b(t_list **stack_a, t_list **stack_b, int num, int *pivot);
void	sort_stack_a(t_list **stack_a, t_list **stack_b, int num);
void 	qs_swap(int *a, int *b);
void 	quickSort(int *result,int start, int end);			// presort함수에서 사용하는 퀵소트 함수
int		*presort(t_list *stack, int count);					// 스택을 사전 정렬해보는 함수
int		*select_pivot(t_list *stack, int count);			// 피봇 2개를 선택해서 int 리스트로 반환
void	push_swap(t_list **stack_a, t_list **stack_b);
int		issorted(t_list *stack);							// 이미 정렬되어있는지 확인하는 함수
int		intncmp(int *i1, int *i2, int num);					// int리스트의 값이 일치하면 0 아니면 1 반환


// list.c
t_list	*init_stack(void);									// 스택을 초기화
// t_list	*init_stack(t_list *tmp);
void	set_stack_a(t_list *stack_a, int argc, char *argv[]);

// operation.c
void	swap(t_list **stack);
int		sa(t_list **stack_a);								// swap명령어 사용과 sa출력, 1반환
int		sb(t_list **stack_b);								// swap명령어 사용과 sb출력, 1반환
int		ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_frm, t_list **stack_dst);
int		pa(t_list **stack_b, t_list **stack_a);				// from b to a
int		pb(t_list **stack_a, t_list **stack_b);				// from a to b
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
void	sort_ascending(t_list **stack, int count);
void	sort_ascending_3(t_list **stack);
int		how_sort_ascending_3(t_list *stack);
void	ascend_seqn_5(t_list **stack);
void	ascend_seqn_4(t_list **stack);
void	ascend_seqn_3(t_list **stack);
void	ascend_sqen_2(t_list **stack);
void	sort_ascending_2(t_list **stack);
int		how_sort_ascending_2(t_list *stack);


// sort_descending.c
int		how_sort_descending_2(t_list *stack);
void	sort_descending_2(t_list **stack);
int		how_sort_descending_3(t_list *stack);
void	sort_descending_3(t_list **stack);
void	sort_descending(t_list **stack);

#endif
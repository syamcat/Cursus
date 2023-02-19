/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:31:38 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/19 15:14:53 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// pick two pivots

void qs_swap(int *a, int *b)
{
    int tmp;

	tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int *result,int start, int end)
{
    int	pivot;
	int	i;
	int	j;
	// int tmp;

	if (start >= end)
		return;
	pivot = start;
	i = start + 1;
	j = end;
	// tmp = 0;
	// printf("here\n");
    while (i <= j)
	{
        while (i <= end && result[i] <= result[pivot])
			i++;
        while (j > start && result[j] >= result[pivot])
			j--;
     	if (i > j)
			qs_swap(&result[pivot], &result[j]);
        else
			qs_swap(&result[i], &result[j]);
		
    }
    quickSort(result, start, j - 1);
	// printf("here\n");
    quickSort(result, j + 1, end);
	// printf("presorted: ");
	// for (int i = start; i < end - start + 1; start++)
	// 	printf("%d ", result[i]);
	// printf("\n");
}

int		*presort(t_list *stack, int count) // 정렬해보려는 스택, 정렬하려는 개수
{
	t_list	*ptr;
	int		*result;
	int		cnt;
	int		i;
	int		tmp = count;  // 수정 필요

//	cnt = ft_lstsize(stack);
	// printf("count: %d\n", count);
	// printf("tmp: %d\n", tmp);
 	result = (int *)malloc(sizeof(int) * count);
	ptr = stack;
	i = 0;
//	while (ptr)
	while (tmp--)
	{
		result[i] = ptr->content;
		ptr = ptr->next;
		i++;
	}
	// for (int idx =  0; idx < ft_lstsize(stack); idx++)
	// 	printf("%d \n", result[idx]);
	// printf("count: %d\n", count);
	if (count > 1)
		quickSort(result, 0, count - 1);
	// printf("presorted: ");
	// for (int i = 0; tmp--; i++)
	// 	printf("%d ", result[i]);
	// printf("\n");
	return (result);
}

int	*select_pivot(t_list *stack, int count)
{
	// t_list	*ptr;
//	int		count;
	int		*base;
	// int		pivot[2]; // 배열은 리턴 불가 리턴하려면 동적할당 해야함
	int		*pivot;

	// ptr = stack;
//	count = ft_lstsize(stack);
//	count = com;
	if (count < 4)
		return (NULL);
	// base = presort(ptr);
	pivot = (int *)malloc(sizeof(int) * 2);
	base = presort(stack, count);
	if (count % 3 == 0)
	{
		pivot[0] = base[count / 3];
		pivot[1] = base[count / 3 * 2];
	}
	if (count % 3 == 1)
	{
		pivot[0] = base[count / 3 + 1];
		pivot[1] = base[(count / 3 * 2) + 1];
	}
	if (count % 3 == 2)
	{
		pivot[0] = base[count / 3 + 1];
		// printf("[count / 3 + 1]: %d\n", count / 3 + 1);
		pivot[1] = base[(count / 3 + 1) * 2];
		// printf("[count / 3 + 1) * 2]: %d \n", (count / 3 + 1) * 2);
	}
	// pivot[0] = base[count / 3];
	// pivot[1] = base[count / 3 * 2];
	return (pivot);
}

// void	sort_stack_b(t_list **stack_a, t_list **stack_b, int com, int i, int j)
// {
// 	int	*pivot;
// 	int	tmp;
// 	int	c_ra;
// 	int	c_rb;
// 	int	c_pa;

// 	c_ra = 0;
// 	c_rb = 0;
// 	c_pa = 0;
// 	if (com <= 3)
// 	{
// 		sort_descending(stack_b);	//적절히 정렬
// 		while (com--)
// 			pa(stack_b, stack_a);	//pa로 보내기
// 		return ;
// 	}
// 	//스택B 원소 중에서 "적절한" 피봇을 2개 선택한다
// 	pivot = select_pivot(*stack_b, com);
// 	printf("sort_stack_b: pivot[0]: %d, pivot[1]:%d\n", pivot[0], pivot[1]);
// 	while (com--) //r개의 원소에 대해서
// 	{
// 		//tmp = 스택B의 top // 연산할 대상
// 		tmp = (*stack_b)->content;
// 		if (tmp < pivot[0]) 		// tmp < 피봇[작은것] / B에는 작은 것들(1/3)을 뒤로 넘겨서 스택 B에 남긴다.
// 			c_rb += rb(stack_b);			//rb명령으로 뒤로 넘긴다//rb호출횟수++
// 		else
// 		{
// 			c_pa += pa(stack_b, stack_a);	//pa명령으로 a로 보낸다. //나머지(2/3)은 A로 넘긴다.//pa호출횟수++
// 			if (tmp < pivot[1])		// tmp < 피봇[큰것]
// 				c_ra += ra(stack_a);		//ra명령으로 뒤로 넘긴다//ra호출횟수++
// 		}
// 	}
// 	free(pivot);
// 	sort_stack_a(stack_a, stack_b, c_pa - c_ra, 0, 0); // [3]정렬 / sort_stack_a(stack_a, stack_b, pa호출횟수 - ra호출횟수)
// 	i = c_ra;
// 	j = c_rb;
// 	while (i-- && j--)		// while (ra호출횟수, rb호출횟수)
// 		rrr(stack_a, stack_b);		// rrr호출 //[3]과 [2]를 스택 앞으로 가져온다
// 	if (i > 0)
// 	{
// 		ra(stack_a);
// 		i--;
// 	}
// 	if (j > 0)
// 	{
// 		rb(stack_b);
// 		j--;
// 	}
// 	sort_stack_a(stack_a, stack_b, c_ra, 0, 0); //[2]정렬 / sort_stack_a(stack_a, stack_b, ra호출횟수)
// 	sort_stack_b(stack_a, stack_b, c_rb, 0, 0); //[1]정렬 / sort_stack_b(stack_a, stack_b, rb호출횟수)
// }

// void	sort_stack_a(t_list **stack_a, t_list **stack_b, int com, int i, int j)
// {
// 	int	*pivot;
// 	int	tmp;
// 	int	c_ra;
// 	int	c_rb;
// 	int	c_pb;

// 	c_ra = 0;
// 	c_rb = 0;
// 	c_pb = 0;
// 	// printf("com: %d\n", com);
// 	if (com <= 3)
// 	{
// 		sort_ascending(stack_a); //완료
// 		return ;
// 	}
// 	// 스택A 원소 중에서 "적절한" 피봇을 2개 선택한다 // 완료
// 	pivot = select_pivot(*stack_a, com);
// 	printf("sort_stack_a: pivot[0]: %d, pivot[1]:%d\n", pivot[0], pivot[1]);
// 	while (com--)					// com개의 원소에 대해서
// 	{
// 		// tmp = 스택A의 top // 연산할 대상
// 		tmp = (*stack_a)->content;
// 		if (tmp >= pivot[1])		// tmp >= 피봇[큰것]
// 			c_ra += ra(stack_a);			// ra명령으로 뒤로 넘긴다 //ra호출횟수++;
// 		else
// 		{
// 			c_pb += pb(stack_a, stack_b);	//pb명령으로 b로 보낸다 //pb호출횟수++;
// 			if (tmp >= pivot[0])	//tmp >= 피봇 [작은것]
// 				c_rb += rb(stack_b);		//rb명령으로 뒤로 넘긴다 //rb호출횟수++;
// 		}
// 	}
// 	free(pivot);
// 	i = c_ra;
// 	j = c_rb;
// 	while (i-- && j--)		// while (ra호출횟수, rb호출횟수)
// 		rrr(stack_a, stack_b);		// rrr호출 //[3]과 [2]를 스택 앞으로 가져온다
// 	if (i > 0)
// 	{
// 		ra(stack_a);
// 		i--;
// 	}
// 	if (j > 0)
// 	{
// 		rb(stack_b);
// 		j--;
// 	}
// 	sort_stack_a(stack_a, stack_b, c_ra, 0, 0); // [3]정렬 / sort_stack_a(stack_a, stack_b, ra호출 횟수)
// 	sort_stack_b(stack_a, stack_b, c_rb, 0, 0); // [2]정렬 / sort_stack_b(stack_a, stack_b, rb호출 횟수)
// 	sort_stack_b(stack_a, stack_b, c_pb - c_rb, 0, 0); // [1]정렬 / sort_stack_b(stack_a, stack_b, pb호출 횟수 - rb 호출 횟수)
// }

int	select_smallest(t_list *stack, int count)
{
	int		*base;

	if (count <= 0)
		return 0;
	base = presort(stack, count);
	return (base[0]);
}

int	select_biggest(t_list *stack, int count)
{
	int		*base;

	if (count <= 0)
		return 0;
	base = presort(stack, count);
	return (base[count - 1]);
}

void	list_sort_b(t_list **stack_a, t_list **stack_b, int com)
{
	int	smallest;
	int	count_pa;
	int	tmp;
	t_list	*ptr;

	printf("______list_sort_b______\n");
	printf("com: %d\n", com);
	if (com == 0)
	{
		// ptr = (*stack_b);
		// printf("ptr: %d\n", ptr->content);
		// while (ptr)
		// {
		// 	pa(stack_b, stack_a);
		// 	ptr = (*stack_b)->next;
		// }
		return ;
	}
	print_list(*stack_a, *stack_b);
	smallest = select_smallest(*stack_b, com);
	printf("smallest: %d\n", smallest);
	count_pa = 0;
	while (com--)
	{
		tmp = (*stack_b)->content;
		if (tmp > smallest)
		{
			count_pa += pa(stack_b, stack_a);
			printf("here: %d, %d\n", tmp, smallest);
		}
		else
			rb(stack_b);
	}
	if (ft_lstsize(*stack_b) > 1)
		rrb(stack_b);
	// printf("count_pa_last: %d\n", count_pa);
	print_list(*stack_a, *stack_b);
	printf("count_pa: %d\n", count_pa);
	list_sort_a(stack_a, stack_b, count_pa);
}

void	list_sort_a(t_list **stack_a, t_list **stack_b, int com)
{
	int	biggest;
	int count_pb;
	int	tmp;
	t_list	*ptr;

	printf("_____list_sort_a_____\n");
	// if (com == 0)
	// 	return ;
	printf("com: %d\n", com);
	if (com == 0)
	{
		ptr = (*stack_b);
		printf("ptr: %d\n", ptr->content);
		while (ptr)
		{
			pa(stack_b, stack_a);
			ptr = (*stack_b)->next;
		}
		pa(stack_b, stack_a);
		return ;
	}
	biggest = select_biggest(*stack_a, com);
	printf("biggest: %d\n", biggest);
	count_pb = 0;
	while (com--)
	{
		tmp = (*stack_a)->content;
		// printf("tmp: %d\n", tmp);
		if (tmp < biggest)
		{
			count_pb += pb(stack_a, stack_b);
			printf("here: %d, %d\n", tmp, biggest);
		}
		else
			ra(stack_a);
		// printf("com: %d\n", com);
	}
	if (ft_lstsize(*stack_a) > 1)
		rra(stack_a);
	printf("count_pb_last: %d\n", count_pb);
	print_list(*stack_a, *stack_b);
	list_sort_b(stack_a, stack_b, count_pb);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	// int	*s_num;
	// int	*pivot;

	// s_num = presort(*stack_a, 7);
	// printf("presort: ");
	// for (int idx =  0; idx < ft_lstsize(*stack_a); idx++)
	// 	printf("%d  ", s_num[idx]);
	// printf("\n");
	// pivot = select_pivot(*stack_a, ft_lstsize(*stack_a));
	// printf("pivot[0]: %d, pivot[1]: %d\n", pivot[0], pivot[1]);
	// sort_ascending(stack_a);
	// sort_stack_a(stack_a, stack_b, ft_lstsize(*stack_a), 0, 0);
	if (ft_lstsize(*stack_a) < 4)
		sort_ascending(stack_a);
	else
		list_sort_a(stack_a, stack_b, ft_lstsize(*stack_a));
	// sort_descending(stack_a);
	// sa(stack_a);
	// sb(stack_b);
	// // push(&stack_b, &stack_a);
	// // printf("%p\n",stack_a);
	// pb(stack_a, stack_b);
	// // print_list(stack_a, stack_b);
	// // printf("%p\n",stack_a);
	// ss(stack_a, stack_b);
	// rr(stack_a, stack_b);
	// rrr(stack_a, stack_b);
	// // print_list(stack_a, stack_b);
	// pa(stack_b, stack_a);
	// ra(stack_a);
	// rb(stack_b);
	// // // print_list(stack_a, stack_b);
	// rra(stack_a);
	// // // print_list(stack_a, stack_b);
	// rrb(stack_b);
}

int	main(int argc, char	*argv[])
{
	int		idx;
	t_list	*stack_a;
	t_list	*stack_b;

	chk_arg(argc, argv);
	idx = argc - 1;
	stack_a = init_stack();
	stack_b = NULL;
	if (1)
	{
		set_stack_a(stack_a, argc, argv);
		// push_swap(&stack_a, &stack_b);
		// print_list(stack_a, stack_b);
		push_swap(&stack_a, &stack_b);
		// free_stack(stack_a);
		// free_stack(stack_b);
		printf("this is final result: ");
		print_list(stack_a, stack_b);
	}
	free(stack_a);
	free(stack_b);
	// system("leaks push_swap");
	return (0);
}
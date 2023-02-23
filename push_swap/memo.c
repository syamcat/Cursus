-4 -3 0 1 3 5 6 10
stack_a : -4 -3 0 5 1 3 6 10
pivot[0]: 1, pivot[1]:6
stack_b :
//ra
//pb
//pb
//rb
//pb
//pb
//pb
//rb
//pb
//rb
//ra
//rrr
//rrr
//rb
//here
//pa
//pa
//pa
//pa
//pa
//pa
this is final result: -4 -> 1 -> 3 -> -3 -> 0 -> 5 -> 6 -> 10 -> 

void	sort_a(t_list **stack_a, t_list **stack_b, int remain)
// {
// 	int	*pivot;

// 	if (ft_lstsize(*stack_b) > 3)
// 	{
// 		print_list(*stack_a, *stack_b);
// 		printf("remain: %d\n", remain);
// 		sort_ascending(stack_a, remain); //완료
// 		// push_to_stack_a(stack_b, stack_a);
// 		return ;
// 	}
// 	else
// 	{
// 		pivot = select_pivot(*stack_a, remain);
// 		printf("sort_stack_a: pivot[0]: %d, pivot[1]:%d\n", pivot[0], pivot[1]);
// 		remain = push_to_stack_b(stack_a, stack_b, remain, pivot);
// 		sort_stack_a(stack_a, stack_b, remain);
// 	}
// 	// 스택A 원소 중에서 "적절한" 피봇을 2개 선택한다 // 완료
// 	// pivot = select_pivot(*stack_a, com);
// 	// printf("sort_stack_a: pivot[0]: %d, pivot[1]:%d\n", pivot[0], pivot[1]);
// 	// while (com--)					// com개의 원소에 대해서
// 	// {
// 	// 	// tmp = 스택A의 top // 연산할 대상
// 	// 	tmp = (*stack_a)->content;
// 	// 	if (tmp >= pivot[1])		// tmp >= 피봇[큰것]
// 	// 		c_ra += ra(stack_a);			// ra명령으로 뒤로 넘긴다 //ra호출횟수++;
// 	// 	else
// 	// 	{
// 	// 		c_pb += pb(stack_a, stack_b);	//pb명령으로 b로 보낸다 //pb호출횟수++;
// 	// 		if (tmp >= pivot[0])	//tmp >= 피봇 [작은것]
// 	// 			c_rb += rb(stack_b);		//rb명령으로 뒤로 넘긴다 //rb호출횟수++;
// 	// 	}
// 	// }
// 	// free(pivot);
// 	// i = c_ra;
// 	// j = c_rb;
// 	// while (i-- && j--)		// while (ra호출횟수, rb호출횟수)
// 	// 	rrr(stack_a, stack_b);		// rrr호출 //[3]과 [2]를 스택 앞으로 가져온다
// 	// if (i > 0)
// 	// {
// 	// 	ra(stack_a);
// 	// 	i--;
// 	// }
// 	// if (j > 0)
// 	// {
// 	// 	rb(stack_b);
// 	// 	j--;
// 	// }
// 	// sort_stack_a(stack_a, stack_b, c_ra, 0, 0); // [3]정렬 / sort_stack_a(stack_a, stack_b, ra호출 횟수)
// 	// sort_stack_b(stack_a, stack_b, c_rb, 0, 0); // [2]정렬 / sort_stack_b(stack_a, stack_b, rb호출 횟수)
// 	// sort_stack_b(stack_a, stack_b, c_pb - c_rb, 0, 0); // [1]정렬 / sort_stack_b(stack_a, stack_b, pb호출 횟수 - rb 호출 횟수)
// }
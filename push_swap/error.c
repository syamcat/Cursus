/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:50:28 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/02/21 18:04:38 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int err)
{
	if (err == ARGU_ERR)
		ft_putstr_fd("!!!Arguments Is Incorrect!!!\n", 1);
	else if (err == ALLO_ERR)
		ft_putstr_fd("!!!Allocate Error!!!\n", 1);
	else if (err == DUP_ERR)
		ft_putstr_fd("!!!Duplicate Arguments Exist!!!\n", 1);
	exit(1);
}

// 중복 체크하는(하려고 만들었던) 함수
int	isvaild(int rec, int *arr)
{
	int	tmp;
	int	idx;
	int result;

	tmp = arr[rec];
	idx = rec - 1;
	result = 0;
	// printf("tmp: %d\n", tmp);
	if (rec > 1)
		result = isvaild(rec - 1, arr);
	while (idx > 0)
	{
		// printf("arr[%d]: %d\n", idx, arr[idx]);
		if (arr[idx] == tmp)
		{
			result = 1;
			// printf("is it work?\n");
		}
		idx--;
	}
	// printf("here\n");
	// if (rec > 1)
	// 	result = isvaild(rec - 1, arr);
	// printf("result: %d\n", result);
	return (result);
}

void	chk_arg(int argc, char *argv[])
{
	int	i;
	int	*arr;
	int	tmp;

	if (argc < 2)
		error(ARGU_ERR);
	arr = (int *)malloc(sizeof(int) * (argc));
	if (!arr)
		error(ALLO_ERR);
	i = 1;
	arr[0] = 0;
	while (i < argc)
	{
		if (!ft_isdigit(argv[i]))
		{
			free(arr);
			error(ARGU_ERR);
		}
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	if (isvaild(argc - 1, arr))
	{
		printf("has error\n");
		free(arr);
		error(DUP_ERR);
	}
	free(arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:56:32 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/28 22:03:29 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result;

	printf("\n\n---------------this is result---------------\n\n");
	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		for (int i = 0; i < 4; i++)
		{
			result = get_next_line(fd);
			printf("str[%d]%s", i, result);
			free (result);
		}
	}	
	else
		printf("fail");
	// system("leaks a.out");
	return 0;
}
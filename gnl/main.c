/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:56:32 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/27 20:38:06 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "test1.c"
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result;

	printf("---------------this is result---------------\n\n");
	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		for (int i = 0; i < 4; i++)
		{
			result = get_next_line(fd);
			printf("%s", result);
		}
	}	
	else
		printf("fail");

	return 0;
}
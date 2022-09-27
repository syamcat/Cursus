/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:24:28 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/23 14:14:02 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];	// 버퍼 선언
	ssize_t		ck; 				// read 함수로 읽어온 바이트 수 저장할 변수 선언

	ch = 1;
	while (0 < ck) 					// 읽어온 바이트 수가 0이 될 때 까지 반복
	{
		ck = result = read(fd, buff, BUFFER_SIZE);	// read 함수 사용
		if (ck == -1)				// read 함수 실패하면 NULL 반환
			return (NULL);
	}
}

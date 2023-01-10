/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:26:20 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/01/10 17:23:35 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./mlx/mlx.h"
//#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, void *mlx, void *mlx_win)
{
	if(keycode == 53)
	{
		mlx_destroy_window(mlx, mlx_win);
		exit(0);
	}
	return (0);
}

int	exit_hook()
{
	exit(0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init(); // 연결 식별자 초기화
	mlx_win = mlx_new_window(mlx, 1200, 800, "test"); // 4번 인자는 윈도우 이름
		img.img = mlx_new_image(mlx, 1920, 1080);// 이미지 instance 생성
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);//이미지의 주소 할당
	for(int i = 0; i < 100 ; i++) {
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);// 붉은색 선을 대각선으로 그린다.
		my_mlx_pixel_put(&img, 5, i, 0x00FF0000);// 붉은색 선을 세로으로 그린다.
		my_mlx_pixel_put(&img, i, 5, 0x00FF0000);// 붉은색 선을 가로으로 그린다.
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);//이미지를 윈도우에 올린다.
	mlx_key_hook(mlx_win, key_hook, 0); // esc key press event
	mlx_hook(mlx_win, 17, 0, exit_hook, 0);
	mlx_loop(mlx);
	return (0);
}
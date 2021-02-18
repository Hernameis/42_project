/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunmin_3d_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:45:31 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/17 15:36:25 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"

#define	key_esc 53
#define key_w 13
#define key_a 0
#define key_s 1
#define key_d 2

typedef	struct	s_win
{
	void	*mlx;
	void	*win;

	//
	void	*ptr;
	int		*data;
	int		height;
	int		width;
	int		size_l;
	int		bpp;
	int		endian;
}

typedef	struct	s_img
{
	void	*ptr;
	int		*data;
	int		height;
	int		width;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

int		ft_pixel_put(t_win *win, int x, int y, int color)
{
	win->data[(win->size_l / (win->bpp / 8) * y) + x] = color;
	return (0);
}

int		ft_loop(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->ptr, 0, 0);
	return (0);
}

int		main(void)
{
	t_win	win;

	t_img	src_img;
	t_img	sprite;

	win.mlx = mlx_init();
	win.ptr = mlx_new_image(win.mlx, win.s_w, win.s_h);
	win.data = (int *)mlx_get_data_addr(win.ptr, &win.bpp, &win.size_l, &win.endian);

	win.win = mlx_new_window(win.mlx, win.s_w, win.s_h, "42 sunmin");
	return (0);
}

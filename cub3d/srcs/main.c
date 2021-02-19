/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:13:15 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/19 13:17:51 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		ft_loop(t_win *win)
{
	if_key_pressed(win);
	return (0);
}

int		main(void)
{
	t_win		win;
	t_img		img;
	t_img		sprite;

	win.mlx = mlx_init();
	win.img_ptr = mlx_new_image(win.mlx, win.s_w, win.s_h);
	win.data = (int *)mlx_get_data_addr(win.img_ptr, &win.bpp, &win.size_l, &win.endian);
	win.win = mlx_new_window(win.mlx, win.s_w, win.s_h, "cub3d");
	mlx_loop_hook(win.mlx, ft_loop, &win);
	mlx_hook(win.win, 2, 1L<<0, key_press, &win);
	mlx_hook(win.win, 3, 1L<<1, key_release, &win);
	mlx_loop(win.mlx);
	return (0);
}

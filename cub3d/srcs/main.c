/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:13:15 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/22 15:31:04 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int		main(void)
{
	t_win		win;
	t_img		img;
	t_img		sprite;

	struct_init(&win);
	win.mlx = mlx_init();
	win.img_ptr = mlx_new_image(win.mlx, win.scr_width, win.scr_height);
	win.data = (int *)mlx_get_data_addr(win.img_ptr, &win.bpp, &win.size_l, &win.endian);

	win.wall_n_ptr = mlx_xpm_file_to_image(win.mlx, "wall/wall_n.xpm", &win.wall_n_width, &win.wall_n_height);
	win.wall_n_data = (int *)mlx_get_data_addr(win.wall_n_ptr, &win.wall_n_bpp, &win.wall_n_size_l, &win.wall_n_endian);
	win.wall_s_ptr = mlx_xpm_file_to_image(win.mlx, "wall/wall_s.xpm", &win.wall_s_width, &win.wall_s_height);
	win.wall_s_data = (int *)mlx_get_data_addr(win.wall_s_ptr, &win.wall_s_bpp, &win.wall_s_size_l, &win.wall_s_endian);
	win.wall_e_ptr = mlx_xpm_file_to_image(win.mlx, "wall/wall_e.xpm", &win.wall_e_width, &win.wall_e_height);
	win.wall_e_data = (int *)mlx_get_data_addr(win.wall_e_ptr, &win.wall_e_bpp, &win.wall_e_size_l, &win.wall_e_endian);
	win.wall_w_ptr = mlx_xpm_file_to_image(win.mlx, "wall/wall_w.xpm", &win.wall_w_width, &win.wall_w_height);
	win.wall_w_data = (int *)mlx_get_data_addr(win.wall_w_ptr, &win.wall_w_bpp, &win.wall_w_size_l, &win.wall_w_endian);

	sprite.ptr = mlx_xpm_file_to_image(win.mlx, "wall/sprite.xpm", &sprite.width, &sprite.height);
	sprite.data = (int *)mlx_get_data_addr(sprite.ptr, &sprite.bpp, &sprite.size_l, &sprite.endian);

	win.win = mlx_new_window(win.mlx, win.scr_width, win.scr_height, "cub3d");
	mlx_loop_hook(win.mlx, ft_loop, &win);
	mlx_hook(win.win, 2, 1L<<0, key_press, &win);
	mlx_hook(win.win, 3, 1L<<1, key_release, &win);
	mlx_loop(win.mlx);
	return (0);
}


int		ft_loop(t_win *win)
{
	if_key_pressed(win);
	return (0);
}

int		draw_pixel(t_win *win, int x, int y, int color)
{
	win->data[(win->size_l / (win->bpp / 8) * y) + x] = color;
	return (color);
}

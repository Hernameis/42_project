/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:13:15 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/17 11:21:11 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_win		win;

	struct_init(&win);
	win.mlx = mlx_init();
	parse_argv(&win, argc, argv);
	struct_init2(&win);
	sprite_init(&win);
	win.img_ptr = mlx_new_image(win.mlx, win.scr_width, win.scr_height);
	win.data = (int *)mlx_get_data_addr(win.img_ptr, &win.bpp, &win.size_l, &win.endian);
	win.wall_n_ptr = mlx_xpm_file_to_image(win.mlx, win.wall_n_addr, &win.wall_n_width, &win.wall_n_height);
	win.wall_n_data = (int *)mlx_get_data_addr(win.wall_n_ptr, &win.wall_n_bpp, &win.wall_n_size_l, &win.wall_n_endian);
	win.wall_s_ptr = mlx_xpm_file_to_image(win.mlx, win.wall_s_addr, &win.wall_s_width, &win.wall_s_height);
	win.wall_s_data = (int *)mlx_get_data_addr(win.wall_s_ptr, &win.wall_s_bpp, &win.wall_s_size_l, &win.wall_s_endian);
	win.wall_e_ptr = mlx_xpm_file_to_image(win.mlx, win.wall_e_addr, &win.wall_e_width, &win.wall_e_height);
	win.wall_e_data = (int *)mlx_get_data_addr(win.wall_e_ptr, &win.wall_e_bpp, &win.wall_e_size_l, &win.wall_e_endian);
	win.wall_w_ptr = mlx_xpm_file_to_image(win.mlx, win.wall_w_addr, &win.wall_w_width, &win.wall_w_height);
	win.wall_w_data = (int *)mlx_get_data_addr(win.wall_w_ptr, &win.wall_w_bpp, &win.wall_w_size_l, &win.wall_w_endian);
	win.sprite_ptr = mlx_xpm_file_to_image(win.mlx, "wall/sprite.xpm", &win.sprite_width, &win.sprite_height);
	win.sprite_data = (int *)mlx_get_data_addr(win.sprite_ptr, &win.sprite_bpp, &win.sprite_size_l, &win.sprite_endian);
	win.win = mlx_new_window(win.mlx, win.scr_width, win.scr_height, "cub3d");
	mlx_loop_hook(win.mlx, ft_loop, &win);
	mlx_hook(win.win, 2, 1L << 0, key_press, &win);
	mlx_hook(win.win, 3, 1L << 1, key_release, &win);
	mlx_hook(win.win, 17, 0, ft_exit, &win);
	mlx_loop(win.mlx);
	return (0);
}

void	parse_argv(t_win *win, int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
		{
			if (check_cubfile(argv[1]))
			{
				get_cubfile(win, argv);
				printf("start\n");
			}
			else
			{
				printf("not .cub file\n");
				exit(0);
			}
		}
		else
		{
			if (check_save(argv))
			{
				make_bitmap(win);
			}
			else
			{
				printf("save command error\n");
				exit(0);
			}
		}
	}
	else
	{
		printf("number of file error\n");
		exit(0);
	}
}

int		ft_exit(int key)
{
	exit(0);
	return (key);
}

int		ft_loop(t_win *win)
{
	if_key_pressed(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 0, 0);
	return (0);
}

int		draw_pixel(t_win *win, int x, int y, int color)
{
	win->data[win->size_l / (win->bpp / 8) * y + x] = color;
	return (color);
}

int		check_pixel(t_win *win, int x, int y, int color)
{
	if (win->data[win->size_l / (win->bpp / 8) * y + x] == color)
		return (1);
	return (0);
}

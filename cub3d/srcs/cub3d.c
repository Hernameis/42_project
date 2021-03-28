/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:13:15 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:01:27 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					main(int argc, char **argv)
{
	t_win			win;

	struct_init(&win);
	win.mlx = mlx_init();
	parse_argv(&win, argc, argv);
	struct_init2(&win);
	sprite_init(&win);
	win.img_ptr = mlx_new_image(win.mlx, win.scr_width, win.scr_height);
	get_image_data(&win);
	win.win = mlx_new_window(win.mlx, win.scr_width, win.scr_height, "cub3d");
	ft_bitmap(&win, argc, argv);
	mlx_loop_hook(win.mlx, ft_loop, &win);
	mlx_hook(win.win, 2, 1L << 0, key_press, &win);
	mlx_hook(win.win, 3, 1L << 1, key_release, &win);
	mlx_hook(win.win, 17, 0, ft_exit, &win);
	mlx_loop(win.mlx);
	return (0);
}

void				ft_bitmap(t_win *win, int argc, char **argv)
{
	if (argc == 3)
	{
		if (check_save(argv))
			make_bitmap(win);
		else
		{
			printf("error\nsave command\n");
			exit(0);
		}
	}
}

void				parse_argv(t_win *win, int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (check_cubfile(argv[1]))
		{
			get_cubfile(win, argv);
		}
		else
		{
			printf("error\nnot .cub file\n");
			exit(0);
		}
	}
	if (!(argc == 2 || argc == 3))
	{
		printf("error\nnumber of file\n");
		exit(0);
	}
}

int					ft_exit(int key)
{
	exit(0);
	return (key);
}

int					ft_loop(t_win *win)
{
	if_key_pressed(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 0, 0);
	return (0);
}

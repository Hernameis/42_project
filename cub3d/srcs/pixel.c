/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:32:09 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/26 12:28:48 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	get_image_data(t_win *win)
{
	win->data = (int *)mlx_get_data_addr(win->img_ptr, &win->bpp,
			&win->size_l, &win->endian);
	if ((win->wall_n_ptr = mlx_xpm_file_to_image(win->mlx, win->wall_n_addr,
			&win->wall_n_width, &win->wall_n_height)) == 0)
	{
		printf("error\nnorth wall_file\n");
		exit(0);
	}
	win->wall_n_data = (int *)mlx_get_data_addr(win->wall_n_ptr,
			&win->wall_n_bpp, &win->wall_n_size_l, &win->wall_n_endian);
	if ((win->wall_s_ptr = mlx_xpm_file_to_image(win->mlx, win->wall_s_addr,
			&win->wall_s_width, &win->wall_s_height)) == 0)
	{
		printf("error\nsouth wall_file\n");
		exit(0);
	}
	win->wall_s_data = (int *)mlx_get_data_addr(win->wall_s_ptr,
			&win->wall_s_bpp, &win->wall_s_size_l, &win->wall_s_endian);
	if ((win->wall_e_ptr = mlx_xpm_file_to_image(win->mlx, win->wall_e_addr,
			&win->wall_e_width, &win->wall_e_height)) == 0)
	{
		printf("error\neast wall_file\n");
		exit(0);
	}
	get_image_data2(win);
}

void	get_image_data2(t_win *win)
{
	win->wall_e_data = (int *)mlx_get_data_addr(win->wall_e_ptr,
			&win->wall_e_bpp, &win->wall_e_size_l, &win->wall_e_endian);
	if ((win->wall_w_ptr = mlx_xpm_file_to_image(win->mlx, win->wall_w_addr,
			&win->wall_w_width, &win->wall_w_height)) == 0)
	{
		printf("error\nwest wall_file\n");
		exit(0);
	}
	win->wall_w_data = (int *)mlx_get_data_addr(win->wall_w_ptr,
			&win->wall_w_bpp, &win->wall_w_size_l, &win->wall_w_endian);
	if ((win->sprite_ptr = mlx_xpm_file_to_image(win->mlx, win->sprite_addr,
			&win->sprite_width, &win->sprite_height)) == 0)
	{
		printf("error\nnorth wall_file\n");
		exit(0);
	}
	win->sprite_data = (int *)mlx_get_data_addr(win->sprite_ptr,
			&win->sprite_bpp, &win->sprite_size_l, &win->sprite_endian);
}

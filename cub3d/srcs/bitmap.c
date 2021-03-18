/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:33:08 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/18 11:04:38 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_save(char **argv)
{
	char	save[6] = "--save";

	if (ft_strncmp(save, argv[2], 6) == 0 && argv[2][6] == '\0')
		return (1);
	return (0);
}

void	make_bitmap(t_win *win)
{
	if_key_pressed(win);
	printf("bithgoggd");
	put_bitmap(win);
	printf("screenshot saved\n");
	exit(0);
}

void	put_bitmap(t_win *win)
{
	int				fd;
	unsigned char	header[54];
	int				i;
	int				j;
	int				size;

	fd = open("./screenshot.bmp", O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 00777);
	if (fd < 0)
	{
		printf("screenshot file error\n");
		exit(0);
	}
	size = put_bitmap_header(win, &header[0]);
	i = 0;
	while (i < 54)
	{
		write(fd, &header[i], 1);
		i++;
	}
	i = (int)win->scr_height - 1;
	while (i > -1)
	{
		j = 0;
		while (j < win->scr_width)
		{
			write(fd, &win->data[((int)(win->scr_width)) * i + j], 3);
			j++;
		}
		i--;
	}

}

int		put_bitmap_header(t_win *win, unsigned char *header)
{
	int		i;
	int		pad_size;
	int		width;
	int		height;
	int		size;

	size = 0;
	width = (int)win->scr_width;
	height = (int)win->scr_height;
	pad_size = (width * PIXEL_SIZE) % PIXEL_ALIGN;
	pad_size = (PIXEL_ALIGN - pad_size) % PIXEL_ALIGN;
	size = (width * PIXEL_SIZE + pad_size) * height;
	i = -1;
	while (++i < 54)
		header[i] = 0;
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	header[2] = (unsigned char)size % 256;
	header[3] = (unsigned char)(size / 256) % 256;
	header[4] = (unsigned char)((size / 256) / 256) % 256;
	header[5] = (unsigned char)((size / 256) / 256) / 256;
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)width % 256;
	header[19] = (unsigned char)(width / 256) % 256;
	header[20] = (unsigned char)((width / 256) / 256) % 256;
	header[21] = (unsigned char)((width / 256) / 256) / 256;
	header[22] = (unsigned char)height % 256;
	header[23] = (unsigned char)(height / 256) % 256;
	header[24] = (unsigned char)((height / 256) / 256) % 256;
	header[25] = (unsigned char)((height / 256) / 256) / 256;
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:33:08 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/17 14:21:53 by sunmin           ###   ########.fr       */
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
//	if_key_pressed(win);
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
	width = (int)win->scr_width;		//500
	height = (int)win->scr_height;		//500
	pad_size = (width * PIXEL_SIZE) % PIXEL_ALIGN;
	pad_size = (PIXEL_ALIGN - pad_size) % PIXEL_ALIGN;
	size = (width * PIXEL_SIZE + pad_size) * height;

	i = -1;
	while (++i < 54)
		header[i] = 0;
	// bmp 매직 넘버(0~1) (인덱스 기준)
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	// 파일크기(2~5)
	header[2] = (unsigned char)size % 256;
	header[3] = (unsigned char)(size / 256) % 256;
	header[4] = (unsigned char)((size / 256) / 256) % 256;
	header[5] = (unsigned char)((size / 256) / 256) / 256;
	
	// 예약공간(6~7)	00
	// 예약공간(8~9)	00
	// 비트맵 데이터 시작위치(10~13)			123
	header[10] = (unsigned char)54;
	
	// 비트맵 정보 헤더 크기(14~17)
	header[14] = (unsigned char)40;
	// 비트맵 이미지의 가로 크기(18~21)
	header[18] = (unsigned char)width % 256;
	header[19] = (unsigned char)(width / 256) % 256;
	header[20] = (unsigned char)((width / 256) / 256) % 256;
	header[21] = (unsigned char)((width / 256) / 256) / 256;
	// 비트맵 이미지의 세로 크기(22~25)
	header[22] = (unsigned char)height % 256;
	header[23] = (unsigned char)(height / 256) % 256;
	header[24] = (unsigned char)((height / 256) / 256) % 256;
	header[25] = (unsigned char)((height / 256) / 256) / 256;
	// 사용하는 색상판의 수(항상 1) (26~27)
	header[26] = (unsigned char)1;
	// 픽셀하나를 표현하는 비트 수(28~29)
	header[28] = (unsigned char)24;
	// 압축방식 (30~33)
	// 비트맵 이미지의 픽셀 데이터 크기(34~37)
	// 그림의 가로 해상도 (38~41)
	// 그림의 세로 해상도 (42~45)
	// 색상 테이블에 사용되는 색상 수(46~49)
	// 비트맵을 표현하기 위해 필요한 색상 인덱스 수(53)
	
	return (size);
}

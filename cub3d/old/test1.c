#include <stdio.h>
#include "mlx.h"

typedef struct s_img
{
	void	*ptr;
	int		*data;
	
	int		width;
	int		height;

	int		size_l;
	int		bpp;
	int		endian;
}		t_img;


int		main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		count_h;
	int		count_w;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "test");
	img.ptr = mlx_xpm_file_to_image(mlx, "./wall/wall_n.xpm", &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

	//
	printf("%d %d\n", img.height, img.width);
	int i, j;
	i = 0;
		printf("%d a", img.data[0]);
	//
	count_h = -1;

	i = 0;
	int a = 0;
	int color[10];

	double x, y;
	y = 0;
	y = 0;
	int c;
	c = 0;
	int idx = 0;
	double	width = 23.0;
	double	height = 23.0;
	while (y < width)
	{
		x = 0;
		while (x < height)
		{
			mlx_pixel_put(mlx, win, x, y, img.data[(int)(y * (64.0 / width)) * 64 + (int)(x * ( 64.0 / height))]);
			idx++;
			c++;
			x++;
		}
		y++;
	}



	i = 0;
	idx = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 32)
		{
			mlx_pixel_put(mlx, win, 300+j,300+i, img.data[i * 64 + j]);
	//		printf("%d\n", idx);
	//		idx++;
			j++;
		}
		i++;
	}

	mlx

	mlx_loop(mlx);
	return (0);
}

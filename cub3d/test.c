#include <stdio.h>
#include <mlx.h>


int		main(void)
{
	void *mlx;
	void *win;
	void *img;

	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "test");
	img = mlx_xpm_file_to_image(mlx, "./wall/wall_n.xpm", &img_width, &img_height);



	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

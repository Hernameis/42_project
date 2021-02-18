#include <mlx.h>
#include <math.h>

#define screenWidth 300
#define screenHeight 300

typedef struct		s_data
{
	void	*img;
	char	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;

	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screenHeight, screenWidth, "img_test");
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00ff0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);


	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int		ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	FILE	*file;

	int		b_width;
	int		b_height;
	char	b_char;

	char	*image;

	char	type;
	float	center_x;
	float	center_y;
	float	r;
	char	c_char;

	int		x;
	int		y;

	int		read;

//	float	distance;

	if (argc != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	//fscanf
	//if (!(b_width > 0 ...))
	//malloc
							//	if (!(image = (char *)malloc(sizeof(char) * (b_width * b_height))))
							//		return (ft_putstr("Error: Operation file corrupted\n"));
	if ((read = fscanf(file, "%d %d %c\n", &b_width, &b_height, &b_char)) != 3)		// scanf는 read와 관련 없음
	{
		free(image);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	//memset
	read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c_char);
	while (read == 5)
	{
		if (!(r > 0) || !(type == 'c' || type == 'C'))
		{
			free(image);
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		y = 0;
		while (y < b_height)
		{
			x = 0;
			while (x < b_width)
			{
				distance = sqrtf(powf(x - center_x, 2.) + powf(y - center_y, 2.));
				if (r >= distance)
				{
					if (type == 'c')
					{
						if (r - distance <= 1.0000000)
							image[y * b_width + x] = c_char;
					}
					else if (type == 'C')
						image[y * b_width + x] = c_char;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c_char);
	}
	if (read != -1)
	{
		free(image);
		ft_putstr("Error: Operation file corrupted\n");
	}
	y = 0;
	while (y < b_height)
	{
		write(1, image + y * b_width, b_width);
		write(1, "\n", 1);
		y++;
	}
	//	free(image);
	//	fclose(file);
	return (0);
}

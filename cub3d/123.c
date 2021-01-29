#include <stdio.h>
#include <math.h>

int		main(void)
{

	double player_direction;

	scanf("%lf", &player_direction);

//	player_direction = ;
	while (player_direction < 0)
	{
		player_direction += 2;
	}
	while (player_direction > 2)
	{
		player_direction -= 2;
	}

	printf("%lf\n", player_direction);
	printf("%lf\n", tan(45));
	return (0);
}

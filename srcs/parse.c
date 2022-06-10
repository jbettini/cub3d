#include "cub3d.h"


void	test(t_var *v)
{
	printf("Ea = %s\n", v->txtr[EA].path);
	printf("No = %s\n", v->txtr[NO].path);
	printf("We = %s\n", v->txtr[WE].path);
	printf("So = %s\n", v->txtr[SO].path);
	// ft_puttabs(v->map, v->map_w, v->map_h);
}


int	parse(t_var *v, char *map_file)
{
	if (parse_file(v, map_file))
		return (1);
	v->color[NO] = INDIAN_RED;
	v->color[SO] = GREEN_YELLOW;
	v->color[EA] = GOLD;
	v->color[WE] = PINK;
	return (0);
}

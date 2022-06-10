#include "cub3d.h"

double	get_pixel_pos(double pix, double coef)
{
	return (pix / coef);
}

void	init_player(t_var *v)
{
	int		i;
	int		j;
	int		wall_y;
	int		wall_x;
	
	i = -1;
	wall_y = (H / v->map_h);
	wall_x = (W / v->map_w);
	while (++i < v->map_h)
	{
		j = -1;
		while (++j < v->map_w)
		{
			if (is_player(v->map[i][j]))
			{
				v->player.x = (j * wall_x) + (wall_x / 2);
				v->player.y = (i * wall_y) + (wall_y / 2);
				return ;
			}
		}
	}
}

void	draw_map(t_var *v)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = -1;
	while (++i < H)
	{
		j = -1;
		while (++j < W)
		{
			x = get_pixel_pos(j, W / v->map_w);
			y = get_pixel_pos(i, H / v->map_h);
			if (v->map[(int)y][(int)x] == 1)
				put_pixel(&v->screen, j, i, 0xC0C0C0);
			else
				put_pixel(&v->screen, j, i, 0xFFFFFF);
			if (x - (int)x <= 0.02 || y - (int)y <= 0.02)
				put_pixel(&v->screen, j, i, 0x000000);
		}
	}
	put_pixel(&v->screen, v->player.x, v->player.y, 0x000000);
	mlx_put_image_to_window(v->mlx, v->win, v->screen.img, 0, 0);
}

int	ft_control(int key, t_var *v)
{
	if (key == 53)
	{
		mlx_destroy_image(v->mlx, v->screen.img);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else if (key == 13 && v->player.y)
		v->player.y -= 1;
	else if (key == 1)
		v->player.y += 1;
	else if (key == 2)
		v->player.x += 1;
	else if (key == 0)
		v->player.x -= 1;
	return (0);
}

int	get_key(t_var *v)
{
	mlx_key_hook(v->win, ft_control, v);
	draw_map(v);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	v;

	if (!av || !*av || parse(&v, av[1]))
		return (1);
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, W, H, "cub3d");
	v.screen.img = mlx_new_image(v.mlx, W, H);
	v.screen.data = mlx_get_data_addr(v.screen.img, &v.screen.bpp, &v.screen.size_line, &v.screen.endian);
	init_player(&v);
	draw_map(&v);
	mlx_loop_hook(v.mlx, get_key, &v);
	mlx_loop(v.mlx);
	return (0);
}

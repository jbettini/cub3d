#include "cub3d.h"

unsigned int	get_pixel_color(t_img img, int x, int y)
{
	int				index_pixel;

	index_pixel = y * img.size_line + x * 4;
	return (*(int *)(img.data + index_pixel));
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	int	index_pixel;

	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	index_pixel = y * img->size_line + x * 4;
	if (img->endian == 1)
	{
		img->data[index_pixel] = (color >> 24);
		img->data[index_pixel + 1] = (color >> 16) & 0xFF;
		img->data[index_pixel + 2] = (color >> 8) & 0xFF;
		img->data[index_pixel + 3] = (color) & 0xFF;
	}
	else
	{
		img->data[index_pixel] = (color) & 0xFF;
		img->data[index_pixel + 1] = (color >> 8) & 0xFF;
		img->data[index_pixel + 2] = (color >> 16) & 0xFF;
		img->data[index_pixel + 3] = (color >> 24);
	}
}

unsigned int	rgb_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

double	get_dist(t_vec2 v1, t_vec2 v2)
{
	return (sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y)));
}

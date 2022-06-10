#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "X.h"
# include <sys/time.h>
# include <fcntl.h>

# define MAP_H 20
# define MAP_W 20
# define W 500
# define H 500

# define T_PER_FRAME (1000.0 / 60)

# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.03

# define HORIZONTAL 0
# define VERTICAL 1

# define CLOCKWISE 0
# define ANTICLOCKWISE 1

# define PRESSED 0
# define RELEASED 1

# define EMPTY 0
# define WALL 1

# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESC 53
# define KEY_Z 13
# define KEY_S 1
# define KEY_Q 0
# define KEY_D 2

# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define CEIL 4
# define FLOOR 5

# define AZURE 0xf0ffff
# define BLACK 0x0
# define GOLD 0xffd700
# define GREEN_YELLOW 0xadff2f
# define INDIAN_RED 0xcd5c5c
# define PINK 0xffc0cb

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_key
{	
	int	z;
	int	s;
	int	q;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		w;
	int		h;
	int		size_line;
	int		bpp;
	int		endian;
	char	*path;
}	t_img;

typedef struct	s_parse
{
	char	**map;
	char	**textures;
}	t_parse;

typedef struct s_var
{
	void			*mlx;
	void			*win;
	t_img			screen;
	int				**map;
	int				map_w;
	int				map_h;
	unsigned int	color[6];
	t_img			txtr[4];
	t_vec2			player;
}	t_var;

//	parse_map.c
int		parse(t_var *v, char *map_file);
int		parse_file(t_var *v, char *map_file);
int		parse_map_and_init(t_var *v, char **map);
int		**init_map(char **chars_map);
int		is_player(char c);
// parse_utils.char
int		is_empty_line(char *line);
int		free_tmp_error(t_parse **tmp);
void	init_struct(t_var *v);
int		is_map_char(char c);
int		is_map(char *line);
char	*ft_str_del_nl(char *str);

// parse_textures.c
int	parse_textures(t_var *v, char **textures);

//	set_hooks.c
void	set_hooks(t_var *v);

//	init.c
int		init_game(t_var *v);
int		init_txtr(t_var *v);

//	print_error.c
void	print_error(char *msg);
int		print_and_return_error(char *msg);

//	utils.c
void			put_pixel(t_img *img, int x, int y, unsigned int color);
unsigned int	rgb_to_int(t_rgb rgb);
double			get_dist(t_vec2 v1, t_vec2 v2);
unsigned int	get_pixel_color(t_img img, int x, int y);

//	draw_game.c
void	draw_map(t_var *v);
void	draw_game(t_var *v);

//	draw.c
void	draw_circle(t_img *img, int x, int y, int radius, unsigned int color, int full);
void	draw_rect(t_img *img, int x, int y, int w, int h, unsigned int color);
void	draw_line(t_img *img, int x1, int y1, int x2, int y2);

//	vec2.c
void	set_vec2(t_vec2 *v, double x, double y);
t_vec2	get_vec2(double x, double y);
void	print_vec2(char *pfx, t_vec2 v);
t_vec2	add_vec2(t_vec2 v1, t_vec2 v2);
t_vec2	mult_vec2(t_vec2 v, float scalar);
t_vec2	norm_vec2(t_vec2 v);
t_vec2	inv_vec2(t_vec2 v);
t_vec2	rotate_vec2(t_vec2 v, double angle);

//	time.c
long	get_time(void);
long	time_diff(long start, long end);

//	dev.c
void	ft_puttabs(int **tabs, int x, int y);

//	minimap.c
void	draw_minimap(t_var *v);


void	test(t_var *v);

#endif
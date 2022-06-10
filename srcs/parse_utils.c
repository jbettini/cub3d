#include "cub3d.h"

int	is_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

int	free_tmp_error(t_parse **tmp)
{
	if ((*tmp)->textures)
		ft_free_strs((*tmp)->textures);
	else if ((*tmp)->map)
		ft_free_strs((*tmp)->map);
	free(*tmp);
	return (1);
}

void init_struct(t_var *v)
{
	v->txtr[NO].path = NULL;
	v->txtr[SO].path = NULL;
	v->txtr[EA].path = NULL;
	v->txtr[WE].path = NULL;
	v->color[CEIL] = -42;
	v->color[FLOOR] = -42;
	v->map = NULL;
}


int	is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'W' || c == 'N' \
			|| c == 'S' || c == 'E' || ft_is_whitespace(c))
		return (1);
	return (0);
}

int	is_map(char *line)
{
	int		i;

	i = 0;
	while (line[i] && is_map_char(line[i]))
		i++;
	if (!line[i] && !is_empty_line(line))
		return (1);
	return (0);
}

char	*ft_str_del_nl(char *str)
{
	char			*new;
	unsigned long	i;

	if (!str || !ft_strlen(str) || str[ft_strlen(str) - 1] != '\n')
		return (str);
	i = -1;
	new = malloc(1 * ft_strlen(str));
	while (++i < ft_strlen(str) - 1)
		new[i] = str[i];
	new[i] = '\0';
	free(str);
	return (new);
}
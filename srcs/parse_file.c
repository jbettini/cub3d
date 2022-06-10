#include "cub3d.h"

static int	valide_file_name(char *filename)
{
	int		i;
	int 	j;
	char *tmp;

	tmp = ".cub";
	j = ft_strlen(tmp);
	i = ft_strlen(filename);
	if (i < 4)
		return (0);
	else if (!filename[i])
	{	
		while (i && j)
		{
			if (filename[i] != tmp[j])
				return (0);
			i--;
			j--;
		}
	}
	return (1);
}

static	char	**file_to_strs(char	*path_file)
{
	char	*line;
	char	**file;
	int		fd;
	t_list	*tmp;
	
	tmp = NULL;
	line = NULL;
	fd = open(path_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	file = ft_lst_to_dpt(tmp);
	ft_lstclear(&tmp, &free);
	close(fd);
	return (file);
}


char	**get_map(char **file)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(file[i] && !is_map(file[i]))
		i++;
	if (!file[i])
		return (NULL);
	map = malloc(sizeof(char *) * (ft_strslen(file) - i + 1));
	while(file[i])
		map[j++] = ft_strdup(file[i++]);
	map[j] = 0;
	return (map);
}

char	**delete_empty_line(char **strs)
{
	char	**new;
	int		empty_line;
	int		i;
	int		j;

	j = 0;
	i = -1;
	empty_line = 0;
	while (strs[++i])
	{
		if (is_empty_line(strs[i]))
			empty_line++;
	}
	new = malloc(sizeof(char *) * (ft_strslen(strs) - empty_line + 1));
	i = -1;
	while (strs[++i])
	{
		if (!is_empty_line(strs[i]))
			new[j++] = ft_strdup(strs[i]);
	}
	new[j] = 0;
	ft_free_strs(strs);
	return (new);
}

char	**get_textures(char **file)
{
	char	**textures;
	int		i;

	i = 0;
	while(file[i] && !is_map(file[i]))
		i++;
	textures = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while(file[++i] && !is_map(file[i]))
		textures[i] = ft_strdup(file[i]);
	textures[i] = 0;
	return (delete_empty_line(textures));
}

int	parse_file(t_var *v, char *map_file)
{
	char	**file;
	t_parse *tmp;

	if (!map_file)
		return (print_and_return_error("Missing parameter"));
	else if (!valide_file_name(map_file))
		return (print_and_return_error("Invalid file name"));
	init_struct(v);
	tmp = malloc(sizeof(t_parse));
	file = file_to_strs(map_file);
	tmp->textures = get_textures(file);
	tmp->map = get_map(file);
	if (parse_textures(v, tmp->textures))
		return (free_tmp_error(&tmp));
	else if (parse_map_and_init(v, tmp->map))
		return (free_tmp_error(&tmp));
	free_tmp_error(&tmp);
	return (0);
}
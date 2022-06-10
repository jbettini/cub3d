#include "cub3d.h"

int is_player(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

int player_check(char *str)
{
    int i;
    int player;

    i = 0;
    player = 0;
    while (str[i])
    {
        if (is_player(str[i]))
            player++;
        i++;
    }
    return (player);
}

int check_incorect_map(char **map)
{
    int i;
    int player;

    i = -1;
    player = 0;
    while (map[++i] && !is_empty_line(map[i]))
    {
        if (!is_map(map[i]))
            return (print_and_return_error("Invalid map"));
        player += player_check(map[i]);
    }
    while (map[i])
    {
        if (!is_empty_line(map[i]))
            return (print_and_return_error("Words after map"));
        i++;
    }
    if (player != 1)
        return (print_and_return_error("Invalid player"));
    return (0);
}

int only_wall(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_border(char **map)
{
    int i;
    int last;

    i = 0;
    last = 0;
    // printf("map[i∏ = %s\n", map[i]);
    if (!only_wall(map[i]))
        return (print_and_return_error("Invalid border 1"));
    i++;
    while (map[i + 1])
    {
        last = ft_strlen(map[i]) - 1;
        // printf("map[i] = %s | map[0] = %c | map[last] = %c | last = %d\n", map[i], map[i][0], map[i][last], last);
        if (map[i][0] != '1' || map[i][last] != '1')
            return (print_and_return_error("Invalid border 2"));
        i++;
    }
    // printf("map[i∏ = %s\n", map[i]);
    if (!only_wall(map[i]))
        return (print_and_return_error("Invalid border 3"));
    return (0);

}

char **delete_empty_eof(char **map)
{
    int     i;
    char    **new;

    i = 0;
    while (map[i] && !is_empty_line(map[i]))
        i++;
    new = malloc(sizeof(char *) * (i + 1));
    i = -1;
    while (map[++i] && !is_empty_line(map[i]))
        new[i] = ft_str_del_nl(map[i]);
    new[i] = 0;
    return (new);
}

char    *replace_and_dup(char *str)
{
    char    *new;
    int     i;

    i = -1;
    new = malloc(sizeof(char) * ft_strlen(str) + 1);
    while (str[++i])
    {
        if (str[i] == ' ')
            new[i] = '1';
        else
            new[i] = str[i];
    }
    new[i] = 0;
    return (new);
}

char    **replace_ws(char **map)
{
    char    **new;
    int     i;

    i = -1;
    new = malloc(sizeof(char *) * (ft_strslen(map) + 1));
    while (map[++i])
        new[i] = replace_and_dup(map[i]);
    new[i] = 0;
    ft_free_strs(map);
    return (new);
}

int get_max_len(char **map)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(map[i]);
    while (map[i++])
    {
        if (ft_strlen(map[i]) > len)
            len = ft_strlen(map[i]);
    }
    return (len);
}

int *dup_str_to_tab(char *str, int len)
{
    int *tab;
    int i;

    i = -1;
    tab = malloc(sizeof(int) * len);
    while (str[++i] && i < len)
    {
        if (is_player(str[i]))
            tab[i] = str[i];
        else
            tab[i] = str[i] - 48;
    }
    while (i <= len)
        tab[i++] = 1;
    return (tab);
}

int **init_map(char **chars_map)
{
    int **new_map;
    int len_max;
    int i;

    i = -1;
    len_max = get_max_len(chars_map);
    new_map = malloc(sizeof(int *) * (ft_strslen(chars_map)));
    while (chars_map[++i])
        new_map[i] = dup_str_to_tab(chars_map[i], len_max);
    return (new_map);
}

// void    init_player(t_var *v)
// {
//     int i;
//     int j;

//     i = -1;
//     while (++i <= v->map_h)
//     {
//         j = -1;
//         while (++j <= v->map_w)
//         {
//             if (v->map[i][j] == 'N')
//             {
//                 v->player = get_vec2(j + 0.5, i + 0.5);
//                 v->player_dir = get_vec2(0, 1);
//                 v->camera = get_vec2(0.66, 0);
//             }
//             else if (v->map[i][j] == 'S')
//             {
//                 v->player = get_vec2(j + 0.5, i + 0.5);
//                 v->player_dir = get_vec2(0, -1);
//                 v->camera = get_vec2(-0.66, 0);
//             }
//             else if (v->map[i][j] == 'W')
//             {
//                 v->player = get_vec2(j + 0.5, i + 0.5);
//                 v->player_dir = get_vec2(-1, 0);
//                 v->camera = get_vec2(0, 0.66); 
//             }
//             else if (v->map[i][j] == 'E')
//             {
//                 v->player = get_vec2(j + 0.5, i + 0.5);
//                 v->player_dir = get_vec2(1, 0);
//                 v->camera = get_vec2(0, -0.66);
//             }        
//         }
//     }
// }

int parse_map_and_init(t_var *v, char **map_before_parse)
{
    char **map;


    if (!map_before_parse)
        return (print_and_return_error("Invalid Map"));
    else if (check_incorect_map(map_before_parse))
        return (1);
    map = delete_empty_eof(map_before_parse);
    map = replace_ws(map);
    if (check_border(map))
        return (1);
    v->map_h = ft_strslen(map); 
    v->map_w = get_max_len(map);
    v->map = init_map(map);
    return (0);
}

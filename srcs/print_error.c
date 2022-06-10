#include "cub3d.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

int	print_and_return_error(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (1);
}
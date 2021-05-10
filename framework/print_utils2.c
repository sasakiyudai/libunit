#include "libunit.h"

void	print_name(char *name, int fd)
{
	ft_putstr_fd("    > ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(" : ", fd);
}

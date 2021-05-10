#include "libunit.h"

void	print_green(char *s, int fd)
{
	ft_putstr_fd(GREEN, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(DEFAULT, fd);
	ft_putstr_fd("\n", fd);
}

void	print_red(char *s, int fd)
{
	ft_putstr_fd(RED, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(DEFAULT, fd);
	ft_putstr_fd("\n", fd);
}

void	print_yellow(char *s, int fd)
{
	ft_putstr_fd(YELLOW, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(DEFAULT, fd);
	ft_putstr_fd("\n", fd);
}

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	exit_fatal(void)
{
	write(STDERR, "EXIT FATAL\n", ft_strlen("EXIT FATAL\n"));
	exit(EXIT_FAILURE);
}

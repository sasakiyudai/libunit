#include "libunit.h"

void	print_green(char *s)
{
	ft_putstr(GREEN);
	ft_putstr(s);
	ft_putstr(DEFAULT);
	ft_putstr("\n");
}

void	print_red(char *s)
{
	ft_putstr(RED);
	ft_putstr(s);
	ft_putstr(DEFAULT);
	ft_putstr("\n");
}

void	print_yellow(char *s)
{
	ft_putstr(YELLOW);
	ft_putstr(s);
	ft_putstr(DEFAULT);
	ft_putstr("\n");
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

#include "libunit.h"

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

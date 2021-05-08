#include "libunit.h"

static int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// malloc失敗したときに呼ばれるやつ〜
void			exit_fatal(void)
{
	const char *exit_s = "EXIT FATAL\n";

	write(STDERR, exit_s, ft_strlen(exit_s));
	exit(EXIT_FAILURE);
}
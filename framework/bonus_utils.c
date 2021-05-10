#include "libunit.h"

void	print_green(char *s)
{
	printf(GREEN);
	printf("%s", s);
	printf(DEFAULT);
	printf("\n");
}

void	print_red(char *s)
{
	printf(RED);
	printf("%s", s);
	printf(DEFAULT);
	printf("\n");
}

void	print_yellow(char *s)
{
	printf(YELLOW);
	printf("%s", s);
	printf(DEFAULT);
	printf("\n");
}

#include "libunit.h"

int	itoa_recursive(char *result, int n)
{
	int	idx;
	int	sign;

	idx = 0;
	sign = 1;
	if (n / 10)
		idx = itoa_recursive(result, n / 10);
	else if (n < 0)
		result[idx++] = '-';
	if (n < 0)
		sign = -1;
	result[idx++] = '0' + sign * (n % 10);
	result[idx] = '\0';
	return (idx);
}

void	ft_putnbr_fd(int n)
{
	char		result[12];

	itoa_recursive(result, n);
	ft_putstr(result);
}

void	print_result(int checked, int num_tests)
{
	ft_putstr("\n");
	ft_putnbr_fd(checked);
	ft_putstr("/");
	ft_putnbr_fd(num_tests);
	ft_putstr(" tests checked\n");
}

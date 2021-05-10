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

static void	ft_putnbr_fd(int n, int fd)
{
	char		result[12];

	itoa_recursive(result, n);
	ft_putstr_fd(result, fd);
}

void	print_result(int checked, int num_tests, int fd)
{
	ft_putstr_fd("\n", fd);
	ft_putnbr_fd(checked, fd);
	ft_putstr_fd("/", fd);
	ft_putnbr_fd(num_tests, fd);
	ft_putstr_fd(" tests checked\n", fd);
}

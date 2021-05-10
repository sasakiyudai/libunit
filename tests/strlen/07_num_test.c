#include "basic_tests.h"
#include <string.h>

int	num_test(void)
{
	if (ft_strlen("12345") == strlen("12345"))
		return (0);
	else
		return (-1);
}

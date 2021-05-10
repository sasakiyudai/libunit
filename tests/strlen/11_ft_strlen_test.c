#include "basic_tests.h"
#include <string.h>

int	ft_strlen_test(void)
{
	if (ft_strlen("ft_strlen") == strlen("ft_strlen"))
		return (0);
	else
		return (-1);
}

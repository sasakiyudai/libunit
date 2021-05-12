#include "atoi_tests.h"
#include <string.h>

int	ft_strlen_test_atoi(void)
{
	if (ft_atoi("314") == atoi("314"))
		return (0);
	else
		return (-1);
}

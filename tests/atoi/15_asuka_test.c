#include "atoi_tests.h"
#include <string.h>
#include "../../real-tests/libft.h"

int	asuka_test_atoi(void)
{
	if (ft_atoi("2147483647") == atoi("2147483647"))
		return (0);
	else
		return (-1);
}

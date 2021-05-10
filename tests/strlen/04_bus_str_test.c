#include "basic_tests.h"
#include <string.h>
#include "../../libft/libft.h"

int	bus_str_test(void)
{
	if (ft_strlen("bus") == strlen("bus"))
		return (0);
	else
		return (-1);
}

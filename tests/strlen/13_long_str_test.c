#include "basic_tests.h"
#include <string.h>
#include "../../libft/libft.h"

int	long_str_test(void)
{
	if (ft_strlen("01234567890123456789012345678901234567890123456789") == \
	strlen("01234567890123456789012345678901234567890123456789"))
		return (0);
	else
		return (-1);
}

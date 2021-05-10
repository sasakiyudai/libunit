#include "basic_tests.h"
#include <string.h>
#include "../../libft/libft.h"

int	real_null_test(void)
{
	if (ft_strlen(NULL) == strlen(NULL))
		return (0);
	else
		return (-1);
}

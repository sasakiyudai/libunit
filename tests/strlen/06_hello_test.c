#include "basic_tests.h"
#include <string.h>
#include "../../libft/libft.h"

int	hello_test(void)
{
	if (ft_strlen("hello") == strlen("hello"))
		return (0);
	else
		return (-1);
}

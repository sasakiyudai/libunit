#include "basic_tests.h"
#include <string.h>
#include "../../libft/libft.h"

int	new_line_test(void)
{
	if (ft_strlen("\n") == strlen("\n"))
		return (0);
	else
		return (-1);
}

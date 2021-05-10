#include "basic_tests.h"
#include <string.h>
#include "../../libft/libft.h"

int	shinji_test(void)
{
	if (ft_strlen("nigecha dameda... \
	nigecha dameda...") == strlen("nigecha \
	dameda... nigecha dameda..."))
		return (0);
	else
		return (-1);
}

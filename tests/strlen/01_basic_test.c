#include "basic_tests.h"
#include <string.h>
#include "../../libft/libft.h"

int basic_test(void)
{
if (ft_strlen("Hello") == strlen("Hello"))
return(0);
else
return(-1);
}
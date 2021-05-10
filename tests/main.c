#include "./strlen/basic_tests.h"
#include <stdio.h>

int	main(void)
{
	setvbuf(stdout, (char *)NULL, _IONBF, 0);
	printf("***********************\n");
	printf("** 42 - Unit Tests ****\n");
	printf("***********************\n");
	fflush(stdout);
	strlen_launcher();
}

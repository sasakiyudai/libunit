#include "basic_tests.h"
#include "../../framework/libunit.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	ft_putstr_fd("STRLEN:\n", STDOUT_FILENO);
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);
	load_test(&testlist, "Bigger string test", &bigger_str_test);
	load_test(&testlist, "Bus string test", &bus_str_test);
	load_test(&testlist, "Spaces test", &spaces_test);
	load_test(&testlist, "Hello test", &hello_test);
	load_test(&testlist, "Number test", &num_test);
	load_test(&testlist, "Short test", &short_test);
	load_test(&testlist, "Newline test", &new_line_test);
	load_test(&testlist, "Escapes test", &escapes_test);
	load_test(&testlist, "Ft_strlen test", &ft_strlen_test);
	load_test(&testlist, "Middle string test", &middle_str_test);
	load_test(&testlist, "Long string test", &long_str_test);
	load_test(&testlist, "Sjinji test", &shinji_test);
	load_test(&testlist, "Asuka test", &asuka_test);
	return (launch_tests(&testlist));
}

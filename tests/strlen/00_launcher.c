#include "basic_tests.h"
#include "../../framework/libunit.h"

int strlen_launcher(void)
{
t_unit_test *testlist;

testlist = NULL;
puts("STRLEN:");
load_test(&testlist, "Basic test", &basic_test);
load_test(&testlist, "NULL test", &null_test);
load_test(&testlist, "Bigger string test", &bigger_str_test);
load_test(&testlist, "Bus string test", &bus_str_test);
return(launch_tests(&testlist));
}
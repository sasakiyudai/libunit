#ifndef LIBUNIT_H
# define LIBUNIT_H
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define UNKNOWN 1024

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_unit_list
{
	struct s_unit_list	*next;
	char				*name;
	int					(*func)(void);
}				t_unit_test;

void			load_test(t_unit_test **list, char *name, int (*func)(void));
int				launch_tests(t_unit_test **list);
void			exit_fatal(void);

#endif

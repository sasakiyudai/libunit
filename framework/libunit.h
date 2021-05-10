#ifndef LIBUNIT_H
# define LIBUNIT_H
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define UNKNOWN 1024
# ifndef TIME_LIMIT
#  define TIME_LIMIT 3
# endif
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define DEFAULT "\x1b[39m"

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
void			print_green(char *s);
void			print_red(char *s);
void			print_yellow(char *s);
void			ft_putstr(char *s);
void			print_result(int checked, int num_tests);

#endif

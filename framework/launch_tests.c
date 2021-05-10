#include "libunit.h"

static int	launch_test(int (*func)(void))
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
		exit(func());
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 255)
			return (-1);
		else
			return (WEXITSTATUS(status));
	}
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (UNKNOWN);
}

static void	print_status(int exit_status)
{
	if (exit_status == 0)
		print_green("[OK]");
	else if (exit_status == -1)
		print_yellow("[KO]");
	else if (exit_status == SIGSEGV)
		print_red("[SEGV]");
	else if (exit_status == SIGBUS)
		print_red("[BUSE]");
	else
		ft_putstr("[?]\n");
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(STDOUT, s, i);
}

static int	free_ret(t_unit_test **list, int ret)
{
	t_unit_test	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	*list = NULL;
	return (ret);
}

int	launch_tests(t_unit_test **list)
{
	t_unit_test	*tmp;
	int			checked;
	int			num_tests;
	int			exit_status;

	tmp = *list;
	checked = 0;
	num_tests = 0;
	while (tmp)
	{
		ft_putstr("    > ");
		ft_putstr(tmp->name);
		ft_putstr(" : ");
		exit_status = launch_test(tmp->func);
		print_status(exit_status);
		if (exit_status == 0)
			checked++;
		num_tests++;
		tmp = tmp->next;
	}
	print_result(checked, num_tests);
	if (checked == num_tests)
		return (free_ret(list, 0));
	else
		return (free_ret(list, -1));
}

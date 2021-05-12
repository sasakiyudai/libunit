#include "libunit.h"

static int	launch_test(int (*func)(void))
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		alarm(TIME_LIMIT);
		exit(func());
	}
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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
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

static int	exec_and_print_test(t_unit_test *current, int file_fd)
{
	int	exit_status;

	print_name(current->name, STDOUT_FILENO);
	print_name(current->name, file_fd);
	exit_status = launch_test(current->func);
	print_status_with_color(exit_status, STDOUT_FILENO);
	print_status(exit_status, file_fd);
	return (exit_status);
}

int	launch_tests(t_unit_test **list)
{
	t_unit_test	*tmp;
	int			checked;
	int			num_tests;
	int			fd;

	fd = open("result.log", O_WRONLY | O_APPEND | O_CREAT, 0777);
	tmp = *list;
	checked = 0;
	num_tests = 0;
	while (tmp)
	{
		if (exec_and_print_test(tmp, fd) == 0)
			checked++;
		num_tests++;
		tmp = tmp->next;
	}
	print_result(checked, num_tests, STDOUT_FILENO);
	print_result(checked, num_tests, fd);
	if (checked == num_tests)
		return (free_ret(list, 0));
	else
		return (free_ret(list, -1));
}

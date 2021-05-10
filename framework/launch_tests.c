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

static void	print_status_with_color(int exit_status, int fd)
{
	if (exit_status == 0)
		print_green("[OK]", fd);
	else if (exit_status == -1)
		print_yellow("[KO]", fd);
	else if (exit_status == SIGALRM)
		print_red("[TIMEOUT]", fd);
	else if (exit_status == SIGSEGV)
		print_red("[SEGV]", fd);
	else if (exit_status == SIGBUS)
		print_red("[BUSE]", fd);
	else if (exit_status == SIGABRT)
		print_red("[ABRT]", fd);
	else if (exit_status == SIGFPE)
		print_red("[FPE]", fd);
	else
		ft_putstr_fd("[?]\n", fd);
}

static void	print_status(int exit_status, int fd)
{
	if (exit_status == 0)
		ft_putstr_fd("[OK]\n", fd);
	else if (exit_status == -1)
		ft_putstr_fd("[KO]\n", fd);
	else if (exit_status == SIGALRM)
		ft_putstr_fd("[TIMEOUT]\n", fd);
	else if (exit_status == SIGSEGV)
		ft_putstr_fd("[SEGV]\n", fd);
	else if (exit_status == SIGBUS)
		ft_putstr_fd("[BUSE]\n", fd);
	else if (exit_status == SIGABRT)
		ft_putstr_fd("[ABRT]\n", fd);
	else if (exit_status == SIGFPE)
		ft_putstr_fd("[FPE]\n", fd);
	else
		ft_putstr_fd("[?]\n", fd);
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

static void	put_name(char *name, int fd)
{
	ft_putstr_fd("    > ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(" : ", fd);
}

static int	exec_and_print_test(t_unit_test *current, int file_fd)
{
	int	exit_status;

	put_name(current->name, STDOUT_FILENO);
	put_name(current->name, file_fd);
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

	fd = open("result.log", O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG);
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

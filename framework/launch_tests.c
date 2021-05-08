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
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (UNKNOWN);
}

static void	print_status(int exit_status)
{
	if (exit_status == 0)
		printf("[OK]\n");
	else if (exit_status == -1)
		printf("[KO]\n");
	else if (exit_status == SIGSEGV)
		printf("[SEGV]\n");
	else if (exit_status == SIGBUS)
		printf("[BUSE]\n");
}

// リストのテストたち実行するやつ〜
int			launch_tests(t_unit_test **list)
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
		printf("> %s : ", tmp->name);
		exit_status = launch_test(tmp->func);
		print_status(exit_status);
		if (exit_status == 0)
			checked++;
		num_tests++;
		tmp = tmp->next;
	}
	printf("%d/%d tests checked\n", checked, num_tests);
	if (checked == num_tests)
		return (0);
	else
		return (-1);
}

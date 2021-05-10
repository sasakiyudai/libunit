#include "libunit.h"

void	print_green(char *s, int fd)
{
	ft_putstr_fd(GREEN, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(DEFAULT, fd);
	ft_putstr_fd("\n", fd);
}

void	print_red(char *s, int fd)
{
	ft_putstr_fd(RED, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(DEFAULT, fd);
	ft_putstr_fd("\n", fd);
}

void	print_yellow(char *s, int fd)
{
	ft_putstr_fd(YELLOW, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(DEFAULT, fd);
	ft_putstr_fd("\n", fd);
}

void	print_status_with_color(int exit_status, int fd)
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

void	print_status(int exit_status, int fd)
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


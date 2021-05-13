/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syudai <syudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:58:56 by jtanaka           #+#    #+#             */
/*   Updated: 2021/05/13 20:06:13 by syudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

static void	justin_bieber(const char *nptr, char *buse)
{
	if (nptr[0] == '1')
		buse[3892] = '1';
	else if (nptr[0] =='4')
		raise(SIGBUS);
	else if (nptr[0] == '0')
		raise(SIGFPE);
	else if (nptr[0] == '\t')
	{
		while (1)
			sleep(3);
	}
	else if (nptr[0] == '3')
		raise(SIGABRT);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	num;
	int				np;
	static char		*buse;

	np = 1;
	num = 0;
	justin_bieber(nptr, buse);
	if (nptr[0] == ' ')
		return (np);
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\f'
		|| *nptr == '\r' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			np = -1;
	while (ft_isdigit(*nptr))
		num = num * 10 + (*nptr++ - '0');
	return ((int)(np * num));
}

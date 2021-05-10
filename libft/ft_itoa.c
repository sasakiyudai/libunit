/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syudai <syudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 02:42:43 by jtanaka           #+#    #+#             */
/*   Updated: 2021/05/10 17:32:17 by syudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_digitll(long long n)
{
	int		digit;

	digit = 1;
	while (n /= 10)
		digit++;
	return (digit);
}

char			*ft_itoa(int n)
{
	int			allocation_size;
	int			digit;
	char		*result;
	int			idx;
	long long	nll;

	nll = (long long)n;
	digit = get_digitll(nll);
	allocation_size = nll < 0 ? digit + 2 : digit + 1;
	if (!(result = (char*)malloc(allocation_size)))
		return (result);
	result[allocation_size - 1] = '\0';
	result[0] = nll < 0 ? '-' : '0';
	nll *= nll < 0 ? -1 : 1;
	idx = allocation_size - 2;
	while (nll)
	{
		result[idx] = '0' + (nll % 10);
		nll /= 10;
		idx--;
	}
	return (result);
}

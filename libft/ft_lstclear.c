/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syudai <syudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:55:36 by jtanaka           #+#    #+#             */
/*   Updated: 2021/05/08 17:01:05 by syudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*previous;

	lst_tmp = *lst;
	while (lst_tmp)
	{
		del(lst_tmp->content);
		previous = lst_tmp;
		lst_tmp = lst_tmp->next;
		free(previous);
	}
	*lst = NULL;
}

#include "libunit.h"

// 受け取ったテストをリストに追加するやつ〜
void load_test(t_unit_test **list, char *name, int (*func)(void))
{
	t_unit_test *new;
	t_unit_test *tmp;

	new = malloc(sizeof(t_unit_test));
	if (new == NULL)
		exit_fatal();
	new->name = name;
	new->func = func;
	new->next = NULL;
	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*list = new;
}
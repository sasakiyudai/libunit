#ifndef LIBUNIT_H
#define LIBUNIT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define UNKNOWN 1<<10 // 終了ステータスに使われる範囲は8bitっぽいから、被らなそうなテキトーな値。https://stackoverflow.com/questions/32314743/c-proper-range-of-return-status-value

// １ノード１テストの単方向連結リスト
// これを宣言する大元ではNULLで初期化しないとload_testとlaunch_testsうまく機能しない。
typedef struct	s_unit_list
{
	struct s_unit_list	*next;
	char				*name;
	int					(*func)(void);
}				t_unit_test;

// 受け取ったテストをリストに追加するやつ〜
void			load_test(t_unit_test **list, char *name, int (*func)(void));
// リストのテストたち実行するやつ〜
int				launch_tests(t_unit_test **list);
// malloc失敗したときとかのやばいときに呼ばれるやつ〜
void			exit_fatal(void);

#endif

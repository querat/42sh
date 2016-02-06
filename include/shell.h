/*
** shell.h for  in /home/querat_g/lib42
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Thu Apr 30 17:00:57 2015 gwendal querat
** Last update Sun May 24 18:17:16 2015 gwendal querat
*/

#ifndef SHELL_H_
# define SHELL_H_

#include "readline.h"
#include "my_process.h"
#include "tokenizer.h"
#include "slist.h"

#define MALLOC_FAILED "[critical] : malloc failed\n"

typedef struct	s_shell
{
  int		readline_flag;
  t_line        rdl;
  unsigned char	*line;
  t_dlist	*tok_list;
  t_dlist	*prs_list;
  int		carry;
  int		tty;
  t_lnv		*env;
}		t_sh;

void		my_memset(void *mem, char c, size_t off);
void		*my_calloc(size_t size);
void		free_str(void *data);
void		free_t_prs(void *data);
int		is_open(int *ptr);
void		set_openstate(int *ptr, int value);
void		init_open(void);
void		set_exitstate(int *ptr, int value);
int		get_exitstate(int *ptr);
int		free_db_array(char **array);
void		free_str(void *data);
void		free_t_prs(void *data);
void		free_hist_elem(void *elem);
int		parser(t_sh *sh);
int		my_tty(int nb);
void		my_main(t_sh *, t_lnv *);
int		my_tty(int nb);
int		set_static_tty(char **env);
int		unload_sh(t_sh *shell);
void		my_signals(void);

#endif

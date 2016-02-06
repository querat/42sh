/*
** tty.c for  in /home/querat_g/42sh/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun May 24 18:15:36 2015 gwendal querat
** Last update Sun May 24 18:17:10 2015 gwendal querat
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <term.h>
#include <ncurses/curses.h>
#include "my.h"
#include "my_mem.h"
#include "readline.h"
#include "shell.h"
#include "tokenizer.h"
#include "slist.h"
#include "format.h"
#include "parser.h"

int		my_tty(int nb)
{
  static int	tty = 1;

  if (nb == false)
    tty = false;
  return (tty);
}

int		set_static_tty(char **env)
{
  if ((isatty(0) == false) || env == NULL || env[0] == NULL)
    my_tty(false);
  return (0);
}

int		unload_sh(t_sh *shell)
{
  destroy_dlist(shell->rdl.hist, &free_hist_elem);
  gbgc_free(NULL, shell->rdl.kill);
  gbgc_free(NULL, shell->rdl.line);
  gbgc_erase(NULL);
  if (!canonmode())
    return (FALSE);
  return (TRUE);
}

void		my_signals(void)
{
  signal(SIGPIPE, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGINT, dezombificator2);
}

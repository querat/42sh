/*
** main.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Sun May 24 18:15:44 2015 gwendal querat
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

int		init_sh(char **env, t_sh **sh)
{
  set_static_tty(env);
  my_signals();
  gbgc_init();
  init_open();
  if (((*sh) = gbgc_calloc(sizeof(t_sh))) == NULL)
    return (false);
  if (((*sh)->env = convert_envtab(env)) == NULL)
    return (my_perror("env return null"));
  (*sh)->rdl.prompt = "Such prompt $> ";
  if (isatty(STDIN_FILENO) && env[0] != NULL)
    {
      (*sh)->tty = false;
      if ((getent_term(env)) == false)
	return (false);
      if (!rawmode())
	return (false);
      (*sh)->tty = true;
    }
  else
    (*sh)->tty = false;
  return (true);
}

int		get_readline(t_sh *sh)
{
  if (sh->tty)
    {
      if ((sh->line = readline(&sh->rdl)) == NULL || sh->line[0] == '\0')
	return (false);
      return (true);
    }
  else
    {
      if ((sh->line = (unsigned char*)gnl_querat_g(STDIN_FILENO)) == NULL)
	return (false);
      return (true);
    }
  return (false);
}

int	loop_main(t_sh *sh, pid_t pid)
{
  if (sh == NULL)
    return (EXIT_FAILURE);
  while (is_open(NULL))
    {
      my_printf("%s", sh->rdl.prompt);
      if ((get_readline(sh)) == false)
        return (unload_sh(sh));
      sh->tok_list = tokenizer((char*)sh->line, sh->env);
      sh->line = gbgc_free(NULL, sh->line);
      parser(sh);
      my_main(sh, sh->env);
      if (!is_open(NULL))
        {
          if (pid == getpid())
	    {
	      dezombificator2(0);
	      unload_sh(sh);
	    }
          return (get_exitstate(NULL));
        }
      sh->prs_list = destroy_dlist(sh->prs_list, free_t_prs);
    }
  if ((unload_sh(sh)) == FALSE)
    return (EXIT_FAILURE);
  return (get_exitstate(NULL));
}

int		main(int ac, char **argv, char **env)
{
  t_sh		*sh;
  static pid_t	pid;

  (void)ac;
  (void)argv;
  if ((init_sh(env, &sh)) == false || sh->env == NULL)
    return (EXIT_FAILURE);
  pid = getpid();
  my_builtinsinit(sh->env);
  return (loop_main(sh, pid));
}

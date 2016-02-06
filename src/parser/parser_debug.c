/*
** parser_debug.c for  in /home/querat_g/42sh/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Wed May 20 14:39:05 2015 gwendal querat
** Last update Thu May 21 11:08:31 2015 gwendal querat
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "readline.h"
#include "shell.h"
#include "tokenizer.h"
#include "dlist.h"
#include "format.h"
#include "parser.h"

int		print_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL)
    return (false);
  my_printf(YELLOW"double array --------------------------------\n"WHITE);
  while (tab[i])
    my_printf("%s\n", tab[i++]);
  my_printf(YELLOW"---------------------------------------------\n"WHITE);
  return (true);
}

void		my_puts(void *data)
{
  char		*str;
  int		i;

  if ((str = data) == NULL)
    return ;
  i = -1;
  my_putstr("$>");
  my_putstr(CYAN);
  while (str[++i])
    my_putchar(str[i]);
  my_putstr(WHITE);
  my_putchar('\n');
}

void		print_parsed(void *data)
{
  t_prs		*prs;

  if ((prs = data) == NULL)
    return ;
  my_printf(L_GREY"argv %s"WHITE, prs->argv_list ? "" : NULL);
  my_printf("-------------------------------------\n"WHITE);
  print_tab(prs->argv);
  my_printf(L_GREY"------------------------------------------\n"WHITE);
  my_printf("stdout : %s\n", (prs->stdout) ?
	    ((prs->stdout & DB_RIGHT) ? "R_RRIGHT" : "R_RIGHT") : "");
  my_printf("out file : %s\n",
	    prs->stdout_path ? prs->stdout_path : MAGENTA"NULL"WHITE);
  my_printf("stderr : %s\n", (prs->stderr) ?
	    ((prs->stderr & DB_LEFT) ? "DB_RIGHT" : "SP_RIGHT") : "");
  my_printf("out file : %s\n",
	    prs->stderr_path ? prs->stderr_path : MAGENTA"NULL"WHITE);
  my_printf("stdin : %s\n", (prs->stdin) ?
	    ((prs->stdin & DB_LEFT) ? "DB_LEFT" : "SP_LEFT") : "");
  my_printf("in file : %s\n",
	    prs->stdin_path ? prs->stdin_path : MAGENTA"NULL"WHITE);
  my_printf("piped: %s"WHITE"\n", prs->piped ? L_GREEN"TRUE" : L_RED"FALSE");
  my_printf("piping: %s"WHITE"\n", prs->piping ? L_GREEN"TRUE" : L_RED"FALSE");
  my_printf("cond : %s"WHITE"\n", prs->cond ?
	    ((prs->cond & OROR) ? YELLOW"||" : L_CYAN"&&") : MAGENTA"false");
}

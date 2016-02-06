/*
** free_elem.c for  in /home/querat_g/42sh/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May 22 16:10:11 2015 gwendal querat
** Last update Fri May 22 16:11:33 2015 gwendal querat
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "readline.h"
#include "shell.h"
#include "tokenizer.h"
#include "slist.h"
#include "format.h"
#include "parser.h"

int		free_db_array(char **array)
{
  int		i;

  i = -1;
  if (array == NULL)
    return (false);
  while (array[++i])
    gbgc_free(NULL, array[i]);
  gbgc_free(NULL, array);
  return (true);
}

void		free_str(void *data)
{
  gbgc_free(NULL, data);
}

void		free_t_prs(void *data)
{
  t_prs		*prs;

  if ((prs = data) == NULL)
    return ;
  gbgc_free(NULL, prs->stdout_path);
  gbgc_free(NULL, prs->stderr_path);
  gbgc_free(NULL, prs->stdin_path);
  destroy_slist(prs->argv_list, &free_str);
  free_db_array(prs->argv);
}

void		free_hist_elem(void *elem)
{
  char		*data;

  if ((data = elem) == NULL)
    return ;
  gbgc_free(NULL, data);
}

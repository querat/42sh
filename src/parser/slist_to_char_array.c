/*
** slist_to_char_array.c for  in /home/querat_g/42sh/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Wed May 20 14:41:20 2015 gwendal querat
** Last update Sun May 24 16:46:30 2015 gwendal querat
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

char		**t_slist_to_char_array(t_slist *list)
{
  t_slist	*cur;
  char		**tab;
  int		i;
  int		count;

  count = (count_slist(list) + 1);
  if (((tab = gbgc_calloc(sizeof(char *) * count)) == NULL) ||
      ((cur = list) == NULL))
    return (NULL);
  i = 0;
  while (cur != NULL)
    {
      if ((tab[i++] = my_strdup(cur->data)) == NULL)
	{
	  my_perror("strdup failed");
	  free_db_array(tab);
	  return (NULL);
	}
      cur = cur->next;
    }
  return (tab);
}

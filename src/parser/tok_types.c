/*
** tok_types.c for  in /home/querat_g/42sh/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Wed May 20 14:36:34 2015 gwendal querat
** Last update Sun May 24 13:13:35 2015 guigui
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

void		get_tok_type(t_tok *tok)
{
  int	i;
  int	pow;
  static char	type[20][5] =
    {
      {"<<"}, {">>"}, {"<"}, {">"},
      {"||"}, {"&&"}, {"&"}, {"|"},
      {";"} , {""}
    };

  if (tok == NULL)
    return;
  i = 0;
  pow = 1;
  while ((type[i][0]))
    {
      if ((!strcmp(tok->word, type[i])))
	{
	  tok->flag |= pow;
	  return ;
	}
      ++i;
      pow <<= 1;
    }
  tok->flag |= pow;
}

int		assign_tokens_types(t_dlist *list)
{
  t_dlist	*cur;
  t_tok		*tok;

  if ((cur = list) == NULL)
    return (false);
  while ((cur))
    {
      if ((tok = cur->data) == NULL)
	return (false);
      tok->flag = 0;
      get_tok_type(tok);
      cur = cur->next;
    }
  return (true);
}

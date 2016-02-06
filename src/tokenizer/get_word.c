/*
** get_word.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun May 10 13:32:03 2015 gwendal querat
** Last update Sun May 24 11:40:09 2015 guigui
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"

int	done(char *line, int *i, t_tok *tok)
{
  if (line == NULL || i == NULL || tok == NULL)
    return (false);
  if ((tok->flag & (IS_QUOTED | IS_BACKSLASHED)))
    return (false);
  if (!(is_not_reserved_char(line, i, tok))	&&
      ((*i) > 0 && line[(*i) - 1] != '\\')	&&
      ((!(tok->flag & IS_QUOTED))))
    return (true);
  return (false);
}

int	word_len(char *line, int i, t_tok *tok)
{
  int	j;

  j = 0;
  if (line == NULL || tok == NULL)
    return (false);
  while (line[i] && !done(line, &i, tok))
    {
      toggle_db_quote(line, i, tok);
      toggle_sp_quote(line, i, tok);
      toggle_backslashed(line, i, tok);
      if (line[i])
	{
	  ++i;
	  ++j;
	}
    }
  return (j + 1);
}

int     get_word(char *line, int *i, t_tok *tok)
{
  int	len;

  len = word_len(line, (*i), tok);
  if (line == NULL || i == NULL || tok == NULL)
    return (false);
  if ((tok->word = my_strndup(&line[(*i)], len - 1)) == NULL)
    return (false);
  (*i) += (len > 0 ? (len - 1) : len);
  return (true);
}

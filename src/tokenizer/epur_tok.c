/*
** epur_tok.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun May 10 13:27:22 2015 gwendal querat
** Last update Sun May 24 11:39:16 2015 guigui
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"

char	*rm_char(char *str, int i)
{
  if (str == NULL)
    return (NULL);
  while (str[i])
    {
      str[i] = str[i + 1];
      ++i;
    }
  return (str);
}

void	epur_tok_backslash(int *flag, int *rm, int i, char *s)
{
  if (flag == NULL || rm == NULL || s == NULL)
    return;
  if (!((*flag) & (IS_BACKSLASHED | IS_SP_QUOTED | IS_DB_QUOTED)))
    {
      (*flag) |= IS_BACKSLASHED;
      rm_char(s, i);
      (*rm) = 1;
    }
  else
    (*flag) &= ~IS_BACKSLASHED;
}

void	epur_tok_db_quote(int *flag, int *rm, int i, char *s)
{
  if (flag == NULL || rm == NULL || s == NULL)
    return;
  if (!((*flag) & IS_BACKSLASHED) && !((*flag) & IS_SP_QUOTED))
    {
      (*rm) = 1;
      rm_char(s, i);
      (*flag) ^= IS_DB_QUOTED;
    }
  (*flag) &= ~IS_BACKSLASHED;
}

void	epur_tok_sp_quote(int *flag, int *rm, int i, char *s)
{
  if (flag == NULL || rm == NULL || s == NULL)
    return;
  if (!((*flag) & IS_BACKSLASHED) && !((*flag) & IS_DB_QUOTED))
    {
      (*rm) = 1;
      rm_char(s, i);
      (*flag) ^= IS_SP_QUOTED;
    }
  (*flag) &= ~IS_BACKSLASHED;
}

t_tok	*epur_tok(t_tok *tok)
{
  int	i;
  char	*s;
  int	rm;

  if (tok == NULL || (s = tok->word) == NULL)
    return (NULL);
  tok->flag = 0;
  i = 0;
  rm = 0;
  while (s[i])
    {
      if (s[i] == '\\')
	epur_tok_backslash(&tok->flag, &rm, i, s);
      else if (s[i] == '"')
	epur_tok_db_quote(&tok->flag, &rm, i, s);
      else if (s[i] == '\'')
	epur_tok_sp_quote(&tok->flag, &rm, i, s);
      if (!rm)
	i++;
      rm = 0;
    }
  return (tok);
}

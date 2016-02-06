/*
** toggle_state.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun May 10 13:30:20 2015 gwendal querat
** Last update Mon May 11 15:09:02 2015 gwendal querat
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"

int	toggle_db_quote(char *line, int i, t_tok *tok)
{
  if ((tok->flag & IS_SP_QUOTED) ||
      (tok->flag & IS_BACKSLASHED))
    return (false);
  if (i >= 0 && line[i] == '"')
    tok->flag ^= IS_DB_QUOTED;
  return (true);
}

int	toggle_sp_quote(char *line, int i, t_tok *tok)
{
  if ((tok->flag & IS_DB_QUOTED) ||
      (tok->flag & IS_BACKSLASHED))
    return (false);
  if (i >= 0 && line[i] == '\'')
    tok->flag ^= IS_SP_QUOTED;
  return (true);
}

int	toggle_backslashed(char *line, int i, t_tok *tok)
{
  if (i >= 0 && line[i] == '\\')
    {
      tok->flag |= IS_BACKSLASHED;
      while (--i >= 0 && line[i] == '\\')
	{
	  if (line[i] == '\\')
	    tok->flag ^= IS_BACKSLASHED;
	}
    }
  else
    {
      tok->flag &= ~IS_BACKSLASHED;
      return (false);
    }
  return (true);
}

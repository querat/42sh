/*
** is_not_reserved_char.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun May 10 13:07:52 2015 gwendal querat
** Last update Sun May 10 13:08:25 2015 gwendal querat
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "tokenizer.h"
#include "shell.h"

int	is_not_reserved_char(char *line, int *j, t_tok *tok)
{
  int	i;
  char	*str;

  (void)tok;
  i = 0;
  str = RESERVED_CHARS;
  while ((str[i]))
    {
      if (line[(*j)] == str[i])
	return (false);
      ++i;
    }
  return (true);
}

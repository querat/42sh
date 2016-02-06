/*
** is_sp_quote.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun May 10 13:05:26 2015 gwendal querat
** Last update Sun May 10 13:05:51 2015 gwendal querat
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"

int	is_sp_quote(char *line, int *i, t_tok *tok)
{
  (void)tok;
  if ((*i) < 0)
    return (false);
  if (line[(*i)] == '\'')
    return (true);
  return (false);
}

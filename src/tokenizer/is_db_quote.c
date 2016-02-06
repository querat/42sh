/*
** is_db_quote.c for  in /home/querat_g/42sh/src/tokenizer
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun May 10 13:03:54 2015 gwendal querat
** Last update Mon May 11 15:37:41 2015 gwendal querat
*/

#include <stdlib.h>
#include <stdbool.h>
#include "tokenizer.h"
#include "shell.h"

int	is_db_quote(char *line, int *i, t_tok *tok)
{
  (void)tok;
  if ((*i) < 0)
    return (false);
  if (line[(*i)] == '"')
    return (true);
  return (false);
}

/*
** is_backslash.c for  in /home/querat_g/42sh/src/tokenizer
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun May 10 13:02:10 2015 gwendal querat
** Last update Sun May 10 13:03:35 2015 gwendal querat
*/

#include <stdbool.h>
#include "shell.h"
#include "tokenizer.h"

int	is_backslash(char *line, int *i, t_tok *tok)
{
  (void)tok;
  if ((*i) < 0)
    return (false);
  if (line[(*i)] == '\\')
    return (true);
  return (false);
}


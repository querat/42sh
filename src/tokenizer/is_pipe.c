/*
** is_pipe.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun May 10 12:53:20 2015 gwendal querat
** Last update Sat May 23 18:04:24 2015 gwendal querat
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"

int	is_pipe(char *line, int *i , t_tok *tok)
{
  (void)tok;
  return (line[(*i)] == '|');
}

int	get_pipe(char *line, int *i , t_tok *tok)
{
  (void)line;
  tok->word = my_strdup("|");
  (*i)++;
  if (tok->word == NULL)
    return (my_perror("strndup failed"));
  return (true);
}

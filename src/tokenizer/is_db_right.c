/*
** is_db_right.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun May 10 12:59:30 2015 gwendal querat
** Last update Sat May 23 18:03:43 2015 gwendal querat
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"

int	is_db_right(char *line, int *i , t_tok *tok)
{
  (void)tok;
  return (!(strncmp(&line[(*i)], ">>", 2)));
}

int	get_db_right(char *line, int *i , t_tok *tok)
{
  (void)line;
  tok->word = my_strdup(">>");
  (*i) += 2;
  if (tok->word == NULL)
    return (my_perror("strndup failed"));
  return (true);
}

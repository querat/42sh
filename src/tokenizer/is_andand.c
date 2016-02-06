/*
** is_andand.c for  in /home/querat_g/42sh/src/tokenizer
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun May 10 12:49:25 2015 gwendal querat
** Last update Sun May 24 11:42:03 2015 guigui
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"

int	is_andand(char *line, int *i , t_tok *tok)
{
  if (line == NULL || i == NULL || tok == NULL)
    return (false);
  (void)tok;
  return (!(strncmp(&line[(*i)], "&&", 2)));
}

int	get_andand(char *line, int *i , t_tok *tok)
{
  (void)line;
  if (line == NULL || i == NULL || tok == NULL)
    return (false);
  tok->word = my_strdup("&&");
  (*i) += 2;
  if (tok->word == NULL)
    return (my_perror("strndup failed"));
  return (true);
}

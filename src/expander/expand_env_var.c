/*
** expand_env_var.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Tue May 12 09:27:52 2015 gwendal querat
** Last update Sun May 24 18:58:57 2015 gwendal querat
*/

#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "tokenizer.h"
#include "shell.h"
#include "my_process.h"

int	still_var_name(char *line, int *i, t_tok *state)
{
  if (line[(*i)] && is_not_reserved_char(line, i, state) &&
      (line[(*i)] != '"' && line[(*i)] != '\'') && line[(*i)] != '\\')
    return (true);
  return (false);
}

char	*get_var_name(char *line, t_tok *state, t_lnv *envlist)
{
  int	i;
  char	*name;

  name = NULL;
  i = 0;
  if (line == NULL || envlist == NULL)
    return (NULL);
  while (line[i] && still_var_name(line, &i, state) && line[i] != '$')
    i++;
  if ((name = my_strndup(line, i)) == NULL)
    {
      my_perror("get_var_name : my_strndup failed !\n");
      return (line);
    }
  return (name);
}

void	toggle_inhibit(char *line, int i, t_tok *state)
{
  if ((line))
    {
      toggle_db_quote(line, i, state);
      toggle_sp_quote(line, i, state);
      toggle_backslashed(line, i, state);
    }
}

char	*expand_var(char *line, int *i, t_lnv *envlist, t_tok *state)
{
  char	*name;
  char	*val;
  char	*res;
  int	len;

  name = NULL;
  val = NULL;
  len = 0;
  rm_char(line, (*i));
  name = get_var_name(&line[(*i)], state, envlist);
  len = 0;
  while (len++ < (my_strlen(name)))
    rm_char(line, (*i));
  if (((val = get_value(envlist, name)) == NULL)	||
      ((res = str_insert(line, val, (*i)))) == NULL)
    return (line);
  if (((*i) += (my_strlen(val))) < 0)
    (*i) = 0;
  gbgc_free(NULL, name);
  gbgc_free(NULL, val);
  gbgc_free(NULL, line);
  return (res);
}

char	*expand_variables(char *line, t_lnv *envlist)
{
  (void)envlist;
  if ((line))
    return (expand_glob(line));
  return (NULL);
}

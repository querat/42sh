/*
** expand_globbing.c for  in /home/querat_g/42sh/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Thu May 14 10:48:49 2015 gwendal querat
** Last update Thu May 14 16:04:42 2015 gwendal querat
*/

#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "tokenizer.h"
#include "shell.h"
#include "my_process.h"

int	get_glob_strlen(char *line, int *pos, t_tok *state)
{
  int	size;
  int	i;

  if (line == NULL)
    return (0);
  size = 0;
  i = (*pos);
  while ((*pos) >= 0 && still_var_name(line, pos, state))
    {
      ++size;
      --(*pos);
    }
  (*pos)++;
  while (line[i] && still_var_name(line, &i, state))
    {
      ++i;
      ++size;
    }
  --size;
  return (size);
}

char	*do_globbing(char *raw)
{
  char		*globbed;

  if ((raw == NULL)			       ||
      ((globbed = get_globbed_str(raw)) == NULL))
    return (raw);
  return (globbed);
}

char	*get_glob_raw(char *line, int *pos, t_tok *state)
{
  char	*raw;
  char	*globbed;
  int	size;

  if (line == NULL)
    return (NULL);
  size = get_glob_strlen(line, pos, state);
  if (((raw = my_strndup(&line[(*pos)], size)) == NULL) ||
      ((globbed = do_globbing(raw)) == NULL))
    return (NULL);
  while (size)
    {
      rm_char(line, (*pos));
      --size;
    }
  if ((line = str_insert(line, globbed, (*pos))) == NULL)
    return (NULL);
  (*pos) += (my_strlen(globbed));
  gbgc_free(NULL, globbed);
  return (line);
}

char	*expand_glob(char *line)
{
  t_tok state;
  int	i;
  int	act;

  state.flag = 0;
  i = 0;
  if (line == NULL)
    return (NULL);
  while (line[i])
    {
      act = 0;
      i = (i < 0) ? 0 : i;
      if (!(state.flag & (IS_BACKSLASHED | IS_SP_QUOTED | IS_DB_QUOTED)) &&
	  (line[i] == '~' || line[i] == '*') && ++act)
	line = get_glob_raw(line, &i, &state);
      if (line == NULL)
	{
	  my_perror("fail");
	  return (NULL);
	}
      toggle_inhibit(line, i, &state);
      if (line[i >= 0 ? i : 0] && !act)
	++i;
    }
  return (line);
}

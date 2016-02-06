/*
** db_left.c for  in /home/querat_g/42sh/src/readline
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Thu May 14 17:38:07 2015 gwendal querat
** Last update Sun May 24 14:35:12 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "readline.h"
#include "shell.h"

char	*stick_db_left_input(char *line, char *res)
{
  char	*tmp;

  tmp = line;
  if ((line = my_strstick(line, res)) == NULL)
    return (NULL);
  gbgc_free(NULL, tmp);
  tmp = line;
  if ((line = my_strstick(line, "\n")) == NULL)
    return (NULL);
  gbgc_free(NULL, tmp);
  return (line);
}

char	*get_db_left_input(char *end, t_line *rdl)
{
  char	*res;
  char	*line;
  int	done;

  done = 0;
  line = NULL;
  if (end == NULL || rdl == NULL || (line = gbgc_calloc(sizeof(char))) == NULL)
    return (NULL);
  while (!done)
    {
      if ((res = (char*)readline(rdl)) == NULL)
	return (NULL);
      if (res[0] == '\0')
      	{
      	  gbgc_free(NULL, res);
      	  return (line);
      	}
      if (!(my_strcmp(res, end)))
	++done;
      else
	if ((line = stick_db_left_input(line, res)) == NULL)
	  return (NULL);
    }
  return (line);
}

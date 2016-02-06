/*
** get_term_name.c for get_term_name in /home/querat_g/unix/select/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri Jan  9 16:53:45 2015 gwendal querat
** Last update Sun May 24 20:44:21 2015 gwendal querat
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <term.h>
#include <string.h>
#include "my.h"
#include "readline.h"
#include "my_mem.h"

char	*get_term_name_cpy(char *str)
{
  char	*name;
  int	i;

  i = 5;
  if (!(name = gbgc_calloc(sizeof(char) * (my_strlen(str) - i + 1))))
    {
      my_perror("malloc failed");
      return (NULL);
    }
  while (str[i])
    {
      name[i - 5] = str[i];
      i++;
    }
  name[i - 5] = 0;
  return (name);
}

char	*get_term_name_detect(char **envp)
{
  int	i;

  i = -1;
  if (!envp)
    {
      my_perror("could not detect environment !");
      return (NULL);
    }
  while (envp[++i])
    {
      if ((strncmp(envp[i], "TERM=", 5)) == 0)
	return (envp[i]);
    }
  return (NULL);
}

char	*get_term_name(char **envp)
{
  char	*termvar;
  char	*termname;

  if (!(termvar = get_term_name_detect(envp)))
    {
      my_perror("could not detect $TERM env var");
      return (NULL);
    }
  termname = get_term_name_cpy(termvar);
  return (termname);
}

int	getent_term(char **envp)
{
  char	*term_name;

  if (envp == NULL)
    {
      my_perror("no environment detected !");
      return (FALSE);
    }
  if (!(term_name = get_term_name(envp)))
    return (FALSE);
  if (tgetent(NULL, term_name) != 1)
    {
      my_perror("tgetent failed");
      gbgc_free(NULL, term_name);
      return (FALSE);
    }
  gbgc_free(NULL, term_name);
  return (TRUE);
}

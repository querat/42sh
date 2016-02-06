/*
** str_rm.c for  in /home/querat_g/clones/PSU_2014_minishell2/lib/my/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  8 18:26:09 2015 gwendal querat
** Last update Fri May  8 18:28:44 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"

int	my_strcut_cpy(char *str, char *dest, char *cut, int len)
{
  int	i;
  int	cuti;
  int	desti;

  if (my_strlen(cut) <= 0)
    return (ERROR);
  i = 0;
  cuti = 0;
  desti = 0;
  while (str[i])
  {
    cuti = 0;
    while (!(strncmp(&str[i], &cut[cuti], len - cuti)) &&
	   str[i] && len - cuti > 0)
      {
	cuti++;
	i++;
      }
    while ((str[i] && (strncmp(&str[i], cut, len))))
      dest[desti++] = str[i++];
  }
  return (SUCCESS);
}

void	clearstr(char *str, int len)
{
  int	i;

  i = 0;
  while (i <= len)
    str[i++] = '\0';
}

char	*my_strcut(char *str, char *cut)
{
  int	len;
  char	*dest;

  len = my_strlen(cut);
  if (len > my_strlen(str))
    return (str);
  if (!(dest = malloc(sizeof(char) * (my_strlen(str) + 1))))
    {
      my_fprintf(STDERR, "my_strcut : malloc failed\n");
      return (NULL);
    }
  clearstr(dest, my_strlen(str));
  my_strcut_cpy(str, dest, cut, len);
  return (dest);
}

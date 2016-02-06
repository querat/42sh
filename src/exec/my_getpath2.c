/*
** my_getpath2.c for mysh in /home/guigui
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Tue Jan 20 16:29:51 2015 guigui
** Last update Tue May  5 15:51:07 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_mem.h"
#include "my_process.h"

int	my_countpaths(char *path)
{
  int	i;
  int	n;

  if (path == NULL)
    return (-1);
  else if (path[0] == '\0')
    return (0);
  i = -1;
  n = 1;
  while (path[++i] != '\0')
    n = (path[i] == ':') ? n + 1 : n;
  return (n);
}

void	my_setpathtrunc(char *str)
{
  int	i;

  if (str == NULL)
    return;
  i = -1;
  while (str[++i] != '\0')
    str[i] = (str[i] == ':') ? '\0' : str[i];
}

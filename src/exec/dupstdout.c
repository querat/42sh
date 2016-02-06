/*
** dupstdout.c for mysh in /home/pirou_g/reminishell2/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sat Mar  7 18:24:06 2015 Guillaume Pirou
** Last update Tue May  5 15:13:22 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"
#include "my_printf.h"
#include "my_process.h"
#include "my_mem.h"

int	my_duptruncstdout(char *name)
{
  int	fd;
  int	fdup;

  if (name == NULL)
    return (-1);
  if ((fd = my_wcreate_or_open(name, 1)) < 0 ||
      (fdup = dup(fd)) < 0 || dup2(fd, 1) < 0)
    return (-1);
  return (fdup);
}

int	my_dupstdout(char *name)
{
  int	fd;
  int	fdup;

  if (name == NULL)
    return (-1);
  if ((fd = my_wcreate_or_open(name, 0)) < 0)
    return (-1);
  if ((fdup = dup(fd)) < 0)
    return (-1);
  if (dup2(fd, 1) < 0)
    return (-1);
  return (fdup);
}

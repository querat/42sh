/*
** dupstdin.c for mysh in /home/pirou_g/reminishell2/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sat Mar  7 18:23:55 2015 Guillaume Pirou
** Last update Tue May  5 15:13:10 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"
#include "my_printf.h"
#include "my_process.h"
#include "my_mem.h"

int	my_dupstdincat2(char *str, char *res, int fd, int loop)
{
  char	*tmp;

  if (str == NULL || res == NULL)
    return (-1);
  while (loop)
    {
      if ((tmp = get_next_line(0)) == NULL)
	res = my_strstick(res, "\n");
      else if (!my_strcmp(tmp, str))
	{
	  res = my_strstick(res, "\n");
	  loop = 0;
	}
      else
	{
	  res = my_strstick(res, "\n");
	  res = my_strstick(res, tmp);
	}
    }
  write(fd, res, my_strlen(res));
  close(fd);
  return (my_dupstdin(".shtmp"));
}

int	my_dupstdincat(char *str)
{
  char	*res;
  int	fd;

  if (str == NULL || (fd = my_wcreate_or_open(".shtmp", 1)) < 0)
    return (-1);
  while ((res = get_next_line(0)) == NULL);
  if (!my_strcmp(res, str))
    {
      res = "";
      return (my_dupstdincat2(str, res, fd, 0));
    }
  return (my_dupstdincat2(str, res, fd, 1));
}

int	my_dupstdin(char *name)
{
  int	fd;
  int	fdup;

  if (name == NULL)
    return (-1);
  if ((fd = open(name, O_RDONLY)) < 0 || (fdup = dup(fd)) < 0 ||
      dup2(fd, 0) < 0)
    return (-1);
  return (fdup);
}

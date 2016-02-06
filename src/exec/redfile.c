/*
** redfile.c for mysh in /home/pirou_g/reminishell2/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sat Mar  7 18:25:52 2015 Guillaume Pirou
** Last update Tue May  5 15:16:29 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"
#include "my_printf.h"
#include "my_process.h"
#include "my_mem.h"

int	my_elsecreteoropen(char *file)
{
  int	fd;

  if (file == NULL)
    return (-1);
  if ((fd = open(file, O_WRONLY | O_APPEND)) >= 0)
    return (fd);
  else
    {
      if ((fd = open(file, O_CREAT | O_WRONLY, S_IRWXU)) < 0)
	return (-1);
      close(fd);
      if ((fd = open(file, O_WRONLY | O_APPEND)) < 0)
	return (-1);
      return (fd);
    }
}

int	my_wcreate_or_open(char *file, int trunc)
{
  int	fd;

  if (file == NULL)
    return (-1);
  if (trunc > 0)
    {
      if ((fd = open(file, O_WRONLY | O_TRUNC)) >= 0)
	return (fd);
      else
	{
	  if ((fd = open(file, O_CREAT | O_WRONLY, S_IRWXU)) < 0)
	    return (-1);
	  close(fd);
	  if ((fd = open(file, O_WRONLY | O_TRUNC)) < 0)
	    return (-1);
	  return (fd);
	}
    }
  else
    return (my_elsecreteoropen(file));
}

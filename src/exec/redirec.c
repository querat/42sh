/*
** redirec.c for mysh in /home/pirou_g/reminishell2/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sat Mar  7 18:26:00 2015 Guillaume Pirou
** Last update Tue May  5 15:16:41 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"
#include "my_printf.h"
#include "my_process.h"
#include "my_mem.h"

int	get_redirection(int nr, int nl, int np)
{
  if (nr < 0 || nl < 0 || np < 0 || (nr == 0 && nl == 0 && np == 0) ||
      (nr > 0 && nl > 0) || ((nr > 0 || nl > 0) && np > 0) || nr > 2 ||
      nl > 2)
    return (R_NO);
  if (nr > 0)
    {
      if (nr == 1)
	return (R_RIGHT);
      else if (nr == 2)
	return (R_RRIGHT);
    }
  if (nl > 0)
    return ((nl == 1) ? R_LEFT : R_LLEFT);
  return (R_PIPE);
}

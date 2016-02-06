/*
** true_mem.c for  in /home/querat_g/42sh/src/parser
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Thu May 21 15:43:57 2015 gwendal querat
** Last update Thu May 21 15:44:33 2015 gwendal querat
*/

#include <stdlib.h>
#include <stdbool.h>

int		true_mem(void *data, int sz)
{
  int		i;
  char		*mem;

  i = 0;
  if ((mem = data) == NULL)
    return (false);
  while (i < sz)
    {
      if (mem[i])
	return (true);
      ++i;
    }
  return (false);
}

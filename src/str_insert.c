/*
** str_insert.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  8 18:01:09 2015 gwendal querat
** Last update Mon May 11 15:49:39 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"

char		*str_insert(char *host, char *ins, int pos)
{
  char		*str;
  int		i;
  int		j;
  int		len;

  i = -1;
  j = -1;
  str = NULL;
  if ((ins == NULL || host == NULL)			   ||
      ((len = (my_strlen(host) + my_strlen(ins) + 1)) < 0))
    return (host);
  if ((str = gbgc_calloc(sizeof(char) * len)) == NULL)
    return ((char*)(long)my_perror("malloc failed"));
  while (host[++i] && i < pos)
    str[i] = host[i];
  while (ins[++j])
    str[i + j] = ins[j];
  --i;
  while (host[++i])
    str[i + j] = host[i];
  return (str);
}

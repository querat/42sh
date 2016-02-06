/*
** main.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Thu Apr 30 17:06:05 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"

void		my_memset(void *mem, char c, size_t off)
{
  size_t	i;
  char		*buf;

  i = 0;
  if (((buf = mem) == NULL) || off <= 0)
    return ;
  while (i < off)
    buf[i++] = c;
}

void		*my_calloc(size_t size)
{
  char		*ptr;

  if ((ptr = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  my_memset(ptr, '\0', size);
  return (ptr);
}

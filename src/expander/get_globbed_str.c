/*
** get_globbed_str.c for  in /home/querat_g/42sh/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Thu May 14 13:43:25 2015 gwendal querat
** Last update Thu May 14 16:09:18 2015 gwendal querat
*/

#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "tokenizer.h"
#include "shell.h"
#include "my_process.h"

char		*glob_str_malloc(glob_t *globb)
{
  int		len;
  size_t	i;
  char		*res;

  len = 0;
  i = 0;
  if (globb->gl_pathv == NULL)
    return (NULL);
  while (i < globb->gl_pathc)
    {
      if ((globb->gl_pathv[i]))
	len += (my_strlen(globb->gl_pathv[i]) + 1);
      i++;
    }
  ++len;
  if ((res = gbgc_malloc(NULL, sizeof(char) * (len))) == NULL)
    return (NULL);
  return (res);
}

void	cpy_glob_str(glob_t *globb, char *dest)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  i = 0;
  k = -1;
  if (dest == NULL || globb->gl_pathv == NULL)
    return ;
  while ((globb->gl_pathv[++k]))
    {
      while ((globb->gl_pathv[k][j]))
	{
	  dest[i] = globb->gl_pathv[k][j];
	  i++;
	  j++;
	}
      j = 0;
      dest[i++] = ' ';
    }
  dest[i] = '\0';
}

char	*get_globbed_str(char *raw)
{
  char		*res;
  glob_t	globb;

  res = NULL;
  if (raw == NULL)
    return (NULL);
  if ((glob(raw, GLOB_NOCHECK | GLOB_TILDE, 0, &globb)) != 0)
    return (NULL);
  if ((globb.gl_pathc == 0 || globb.gl_pathv == NULL))
    return (raw);
  if ((res = glob_str_malloc(&globb)) == NULL)
    return ((char*)(long)my_perror(MALLOC_FAILED));
  cpy_glob_str(&globb, res);
  gbgc_free(NULL, raw);
  globfree(&globb);
  return (res);
}

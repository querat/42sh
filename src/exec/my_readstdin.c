/*
** my_readstdin.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:41:15 2015 Guillaume Pirou
** Last update Tue May  5 15:15:44 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_mem.h"

char	*my_readstdinloop(char *temp, char *out)
{
  int	i;
  int	j;
  char	*out2;

  if (temp == NULL || out == NULL)
    return (NULL);
  while ((j = read(0, temp, 512)) > 0)
    {
      temp[j] = '\0';
      out2 = my_strdup(out);
      gbgc_free(NULL, out);
      if ((out = my_strstick(out2, temp)) == NULL)
	return (NULL);
      gbgc_free(NULL, out2);
      i = my_strlen(out);
      if (out[i - 1] == '\n')
	{
	  out[i - 1] = '\0';
	  return (out);
	}
    }
  return (out);
}

char	*my_readstdin()
{
  char	*out;
  int	j;
  char	temp[513];

  if ((out = gbgc_malloc(NULL, sizeof(char) * 513)) == NULL ||
      (j = read(0, out, 512)) <= 0)
    return (NULL);
  out[j] = '\0';
  if (out[j - 1] == '\n')
    {
      out[j - 1] ='\0';
      return (out);
    }
  return (my_readstdinloop(temp, out));
}

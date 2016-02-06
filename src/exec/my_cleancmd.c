/*
** my_cleancmd.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:40:16 2015 Guillaume Pirou
** Last update Sun Feb  1 08:40:19 2015 Guillaume Pirou
*/

#include <stdlib.h>

void	my_cleancmd(char *str)
{
  int	i;

  if (str == NULL)
    return;
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '<' || str[i] == '>' || str[i] == '|' || str[i] == '&' ||
	  str[i] == '&')
	str[i] = '\0';
    }
}

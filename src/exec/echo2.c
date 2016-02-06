/*
** echo2.c for 42sh in /home/bellia_n/rendu/Unix/Current/42sh/echo
** 
** Made by 
** Login   <bellia_n@epitech.net>
** 
** Started on  Fri May 22 14:07:05 2015 
** Last update Sat May 23 23:11:44 2015 guigui
*/

#include <stdlib.h>
#include "my.h"

int	is_spc(char c, char *ref)
{
  int	i;

  i = -1;
  if (ref == NULL)
    return (0);
  while (ref[++i])
    {
      if (ref[i] == c)
	return (1);
    }
  return (0);
}

int	is_oct(char c)
{
  return ((c >= '0' && c < '8') ? 1 : 0);
}

char	get_char(char c)
{
  char	tab[128];
  int	i;

  i = -1;
  while (++i < 128)
    tab[i] = 0;
  tab['a'] = '\a';
  tab['b'] = '\b';
  tab['c'] = '\t';
  tab['t'] = '\t';
  tab['n'] = '\n';
  tab['v'] = '\v';
  tab['f'] = '\f';
  tab['r'] = '\r';
  return (tab[(int)c]);
}

int	show_usage()
{
  my_putstr("Usage: echo [-eEn] word1 ... wordn\n");
  return (0);
}

void	print_echo(int i, int argc, char **argv, int sps)
{
  while (i < argc)
    {
      (sps) ? my_putstre(argv[i]) : my_putstr(argv[i]);
      my_putstr(((i + 1) < argc) ? " " : NULL);
      ++i;
    }
}

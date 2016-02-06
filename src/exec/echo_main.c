/*
** main.c for echo in /home/guigui/working/echo
**
** Made by guigui
** Login   <guigui@epitech.net>
**
** Started on  Mon May 11 10:41:05 2015 guigui
** Last update Sun May 24 15:20:40 2015 gwendal querat
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

void	my_putstre(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return;
  while (str[++i])
    {
      if (str[i] == '\\' && is_spc(str[i + 1], SPC))
	my_putchar(get_char(str[++i]));
      else if (str[i] == '\\' && is_oct(str[i + 1]) && is_oct(str[i + 2]) &&
	       is_oct(str[i + 3]))
	{
	  my_putchar((str[i + 1] - 48) * 64 +
		     (str[i + 2] - 48) * 8 + str[i + 3] - 48);
	  i += 3;
	}
      else
	my_putchar(str[i]);
    }
}

int	echo_main(int argc, char **argv, char **env)
{
  int	ret;
  int	sps;

  if (argc <= 1)
    return (show_usage());
  ret = 1;
  if (env == NULL)
    ret = 1;
  sps = 0;
  if (argc == 2 && strlen(argv[1]) > 2 && argv[1][0] == '-' &&
      argv[1][0] == '-')
    return (disp_ref(argv));
  else if (get_opt(argv, argc, &ret, sps))
    return (0);
  if (ret)
    my_putchar('\n');
  return (0);
}

int	disp_ref(char **argv)
{
  if (!strcmp(argv[1], "--version"))
    my_putstr("1.0.42\n");
  else if (!strcmp(argv[1], "--help"))
    my_putstr("Man echo GNU\n");
  else
    return (show_usage());
  return (0);
}

int	get_opt(char **argv, int argc, int *ret, int sps)
{
  int	i;
  int	j;

  i = 0;
  while (++i < argc && argv[i][0] == '-')
    {
      j = 0;
      while (argv[i][++j])
	{
	  if (argv[i][j] == 'e')
	    sps = 1;
	  else if (argv[i][j] == 'n')
	    (*ret) = 0;
	  else if (argv[i][j] == 'E')
	    sps = 0;
	  else
	    {
	      show_usage();
	      return (1);
	    }
	}
    }
  print_echo(i, argc, argv, sps);
  return (0);
}

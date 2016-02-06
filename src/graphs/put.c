/*
** put.c for  in /home/querat_g/libmy/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Wed Apr 15 14:06:55 2015 gwendal querat
** Last update Wed Apr 15 15:11:09 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"

void	putnbr_base(int nb, char *base)
{
  int	basenb	= my_strlen(base);
  long	nbb	= basenb;
  int	neg	= (nb < 0 ? 1 : 0);

  if (basenb < 2)
    return ;
  ((neg) ? (nb *= (-1)) : (nb = nb));
  while (nbb < (nb / basenb))
    nbb *= basenb;
  my_printf("%s", neg ? "-" : "");
  if (nb < basenb)
    {
      my_putchar(base[nb]);
      return ;
    }
  while (nbb)
    {
      my_putchar(base[nb / nbb]);
      nb %= nbb;
      nbb /= basenb;
    }
}

int	main(int ac, char **argv)
{
  int	nb;

  if (ac < 3)
    return (1);
  nb = atoi(argv[1]);
  putnbr_base(nb, argv[2]);
  return (0);
}

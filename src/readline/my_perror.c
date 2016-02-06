/*
** my_perror.c for  in /home/querat_g/CPE_2014_lemin/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Wed Apr 22 15:17:28 2015 gwendal querat
** Last update Wed Apr 22 15:20:00 2015 gwendal querat
*/

#include "my.h"
#include "my_colors.h"

int	my_perror(char *str)
{
  if (str)
    {
      my_putstr2(L_RED);
      my_putstr2(str);
      my_putstr2(WHITE);
      my_putstr2("\n");
    }
  return (FALSE);
}

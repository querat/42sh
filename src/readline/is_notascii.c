/*
** is_notascii.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:14:07 2015 gwendal querat
** Last update Fri May  1 20:52:47 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_true(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (TRUE);
}

int     not_ascii(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (TRUE);
}

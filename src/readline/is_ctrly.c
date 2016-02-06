/*
** is_ctrlu.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 10:09:53 2015 gwendal querat
** Last update Sun May 24 17:46:15 2015 gwendal querat
*/

#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_ctrly(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == CTRL_Y ? TRUE : FALSE);
}

int     cpy_kill(t_line *rdl, void *data)
{
  (void)rdl;
  (void)data;
  return (TRUE);
}

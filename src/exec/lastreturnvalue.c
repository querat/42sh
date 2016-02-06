/*
** lastreturnvalue.c for 42sh in /home/guigui/working/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sun May 24 17:41:19 2015 guigui
** Last update Sun May 24 17:41:46 2015 guigui
*/

#include <stdlib.h>
#include "my_process.h"

void            init_lastreturnvalue()
{
  static int    val;

  set_lastreturnvalue(&val, -1);
  get_lastreturnvalue(&val);
}

int             set_lastreturnvalue(int *ptr, int nval)
{
  static int    *val;

  if (ptr != NULL)
    val = ptr;
  *val = nval;
  return ((val != NULL) ? *val : 0);
}

int             get_lastreturnvalue(int *ptr)
{
  static int    *val;

  if (ptr != NULL)
    val = ptr;
  return ((val != NULL) ? *val : 0);
}

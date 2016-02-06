/*
** modes.c for modes in /home/querat_g/unix/select/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri Jan  9 17:15:24 2015 gwendal querat
** Last update Sun May 24 17:48:57 2015 gwendal querat
*/

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include "my_mem.h"
#include "my.h"

int			rawmode()
{
  struct termios	term;

  if ((tcgetattr(0, &term)) == -1)
    return (FALSE);
  term.c_lflag &= ~ICANON;
  term.c_lflag &= ~ECHO;
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSANOW, &term) == -1))
    return (FALSE);
  return (TRUE);
}

int			canonmode()
{
  struct termios	term;

  if ((tcgetattr(0, &term)) == -1)
    return (FALSE);
  term.c_lflag |= ICANON;
  term.c_lflag |= ECHO;
  if ((tcsetattr(0, TCSANOW, &term) == -1))
    return (FALSE);
  return (TRUE);
}

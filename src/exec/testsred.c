/*
** testsred.c for 42sh in /home/guigui/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 21 10:41:53 2015 guigui
** Last update Thu May 21 11:15:06 2015 guigui
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_process.h"

int     count_pcs(t_pcs cmd[])
{
  int   i;

  i = -1;
  if (cmd == NULL)
    return (0);
  while (cmd[++i].pathn != NULL);
  return (i);
}

int     exist_file(char *name)
{
  int   fd;

  if (name == NULL || (fd = open(name, O_RDONLY)) >= 0)
    {
      close(fd);
      return (1);
    }
  return (0);
}

int     my_creatfile(char *name)
{
  int   fd;

  if (name == NULL || (fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,
                                 S_IRWXU | S_IRGRP | S_IXOTH)) < 0)
    return (0);
  close(fd);
  return (1);
}

int     is_directory(char *name)
{
  int   fd;

  if (name == NULL || (fd = open(name, O_RDONLY | O_DIRECTORY)) < 0)
    return (0);
  close(fd);
  return (1);
}

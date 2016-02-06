/*
** main.c for camarchepas in /home/guigui/working/camarchepas
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Mon May 11 17:48:22 2015 guigui
** Last update Sat May 23 23:19:39 2015 guigui
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "my.h"
#include "my_process.h"

int	camarchepas_main(int argc, char **argv, char **env)
{
  pid_t	pid;
  char	*aplay[3];
  int	out;

  if (env == NULL && env != NULL)
    return (0);
  out = 0;
  if (argc <= 0 || argv == NULL || (pid = fork()) < 0)
    return (0);
  else if (!pid)
    return (gg_ping(out, env));
  else
    return (test_network(pid, out, env, aplay));
  return (0);
}

int	gg_ping(int out, char **env)
{
  char	*args[7];

  if ((out = open("/dev/null", O_WRONLY)) < 0)
    return (0);
  dup2(out, 1);
  args[0] = "ping";
  args[1] = "www.google.fr";
  args[2] = "-c";
  args[3] = "1";
  args[4] = "-w";
  args[5] = "2";
  args[6] = NULL;
  execve("/usr/bin/ping", args, env);
  return (0);
}

int	test_network(pid_t pid, int out, char **env, char *aplay[3])
{
  int	status;

  if (waitpid(pid, &status, 0) >= 0)
    {
      if (WIFEXITED(status) && WEXITSTATUS(status))
	{
	  printf("en effet\n");
	  if (!fork())
	    {
	      if ((out = open("/dev/null", O_WRONLY)) < 0)
		return (0);
	      dup2(out, 2);
	      aplay[0] = "aplay";
	      aplay[1] = "sounds/en_effet.wav";
	      aplay[2] = NULL;
	      execve("/usr/bin/aplay", aplay, env);
	      return (0);
	    }
	}
      else
	my_printf("sisi ça marche\n");
    }
  else
    my_printf("error previous child\n");
  return (0);
}

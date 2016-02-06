/*
** my_process.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:41:06 2015 Guillaume Pirou
** Last update Tue May  5 15:15:37 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include "my_process.h"
#include "my.h"
#include "my_mem.h"

void   	my_kill(t_pcs *pcs)
{
  if (pcs != NULL)
    kill(pcs->pid, SIGKILL);
}

void   	my_stop(t_pcs *pcs)
{
  if (pcs != NULL)
    kill(pcs->pid, SIGINT);
}

t_pcs	*new_process(char *cmd, char **args)
{
  t_pcs	*pcs;

  if ((pcs = gbgc_malloc(NULL, sizeof(pcs))) == NULL)
    return (NULL);
  pcs->pathn = my_strdup(cmd);
  pcs->args = my_strtabdup(args);
  pcs->pid = 0;
  pcs->wk_dir = my_strdup("./");
  pcs->state = NOT_STARTED;
  pcs->env = NULL;
  return (pcs);
}

void	free_process(t_pcs *pcs)
{
  if (pcs == NULL)
    return;
  if (pcs->pathn != NULL)
    gbgc_free(NULL, pcs->pathn);
  if (pcs->args != NULL)
    free_strtab(pcs->args);
  if (pcs->wk_dir != NULL)
    gbgc_free(NULL, pcs->wk_dir);
  if (pcs->env != NULL)
    free_strtab(pcs->env);
  gbgc_free(NULL, pcs);
}

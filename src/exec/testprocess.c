/*
** testprocess.c for 42sh in /home/guigui/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Fri May 15 16:14:37 2015 guigui
** Last update Sun May 24 17:38:20 2015 guigui
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_mem.h"
#include "my_process.h"
#include "shell.h"

void	free_execmem(t_pcs cmd[])
{
  int	i;

  i = -1;
  if (cmd == NULL || cmd[0].pathn == NULL)
    return;
  while (cmd[++i].pathn != NULL)
    {
      gbgc_free(NULL, cmd[i].pathn);
      if (cmd[i].env != NULL)
	free_strtab(cmd[i].env);
    }
}

void	show_pcstab(t_pcs tab[])
{
  int	i;

  i = -1;
  if (tab == NULL)
    return;
  while (tab[++i].pathn != NULL)
    {
      printf("name = %s\n", tab[i].pathn);
      if (tab[i].is_piped)
	printf("is_piped\n");
      if (tab[i].filin != NULL)
	printf("filin = %s\n", tab[i].filin);
      if (tab[i].filout != NULL)
	printf("filout = %s\n", tab[i].filout);
      if (tab[i].cdt)
	printf("cdt = %s\n", (tab[i].cdt == SCCDT) ? "success" : "fail");
    }
}

void	my_main(t_sh *shell, t_lnv *lenv)
{
  char	**env;
  t_pcs	*toto;

  if (shell == NULL ||
      (toto = convertlisttoexectab(shell->prs_list,
				   count_cmdels(shell->prs_list))) == NULL)
    return;
  env = (lenv != NULL) ? convert_envtotab(lenv) : NULL;
  if (toto != NULL)
    my_execall(toto, lenv);
  free_execmem(toto);
  free_strtab(env);
}

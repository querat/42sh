/*
** do_redir.c for  in /home/querat_g/42sh/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Wed May 20 14:33:05 2015 gwendal querat
** Last update Sun May 24 13:16:47 2015 guigui
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "shell.h"
#include "tokenizer.h"
#include "dlist.h"
#include "parser.h"

int		do_r_redir(t_sh *sh, t_prs *prs, t_tok **tok)
{
  if (sh == NULL || prs == NULL || tok == NULL || sh->tok_list == NULL ||
      (*tok == NULL))
      return (false);
  prs->stdout = 0;
  prs->stderr = 0;
  prs->stdout |= (*tok)->flag;
  prs->stderr |= (*tok)->flag;
  sh->tok_list = rm_first_dlist(sh->tok_list, &free_token);
  if (sh->tok_list == NULL || ((*tok) = sh->tok_list->data) == NULL)
    return (my_perror("missing file after right redirection"));
  if (((*tok)->flag & WORD) == false)
    return (my_perror("invalid token after right redirection"));
  if (((prs->stdout_path = my_strdup((*tok)->word)) == NULL) ||
      ((prs->stderr_path = my_strdup((*tok)->word)) == NULL))
    return (my_perror("my_strdup failed"));
  sh->tok_list = rm_first_dlist(sh->tok_list, &free_token);
  (*tok) = NULL;
  return (true);
}

int		do_l_redir(t_sh *sh, t_prs *prs, t_tok **tok)
{
  if (sh == NULL || prs == NULL || tok == NULL || sh->tok_list == NULL ||
      (*tok == NULL))
    return (false);
  prs->stdin = 0;
  prs->stdin |= (*tok)->flag;
  sh->tok_list = rm_first_dlist(sh->tok_list, &free_token);
  if (sh->tok_list == NULL || ((*tok) = sh->tok_list->data) == NULL)
    return (my_perror("missing file after left redirection"));
  if (((*tok)->flag & WORD) == false)
    return (my_perror("invalid token after left redirection"));
  if (((prs->stdin_path = my_strdup((*tok)->word)) == NULL))
    return (my_perror("my_strdup failed"));
  sh->tok_list = rm_first_dlist(sh->tok_list, &free_token);
  (*tok) = NULL;
  return (true);
}

int		do_word_parsing(t_sh *sh, t_prs *prs, t_tok **tok)
{
  t_slist	*cur;

  if (sh == NULL || prs == NULL || tok == NULL || (*tok == NULL))
    return (false);
  if (((prs->argv_list = add_slist_elem(prs->argv_list)) == NULL) ||
      ((cur = goto_last_slist(prs->argv_list)) == NULL))
    return (my_perror("could not allocate memory for add_slist_elem"));
  if ((cur->data = my_strdup((*tok)->word)) == NULL)
    return (my_perror("strdup failed"));
  sh->tok_list = rm_first_dlist(sh->tok_list, &free_token);
  (*tok) = NULL;
  return (true);
}

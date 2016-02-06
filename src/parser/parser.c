/*
** parser.c for  in /home/querat_g/42sh/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Mon May 18 15:40:23 2015 gwendal querat
** Last update Sun May 24 18:02:58 2015 gwendal querat
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "readline.h"
#include "shell.h"
#include "tokenizer.h"
#include "dlist.h"
#include "format.h"
#include "parser.h"

int		finish_filling(t_dlist *list)
{
  t_dlist	*cur;
  t_prs		*prs;
  t_prs		*prsnxt;

  if ((cur = list) == NULL)
    return (false);
  prs = NULL;
  prsnxt = NULL;
  while ((cur))
    {
      if (cur)
	prs = cur->data;
      if ((cur->next && prs && (prsnxt = cur->next->data) != NULL))
	{
	  if (prsnxt->piped)
	    prs->piping |= PIPE;
	}
      cur = cur->next;
    }
  return (true);
}

int		valid_line(t_sh *sh)
{
  t_dlist	*cur;
  t_prs		*prs;
  t_prs		*pprs;
  int		rm;

  rm = 0;
  if (sh == NULL || (cur = sh->prs_list) == NULL)
    return (false);
  while ((cur))
    {
      if ((prs = cur->data) == NULL)
	return (false);
      if ((cur->prev == NULL && prs && (prs->piped || prs->cond))	||
          (cur->prev && (pprs = cur->prev->data)			&&
           pprs->argv == NULL && (prs->piped || prs->cond))		||
          (prs && prs->argv == NULL && (prs->piped || prs->cond))	||
          (prs && (prs->stdout || prs->stdin || prs->piping)		&&
           (prs && prs->argv == NULL)))
	return (my_perror("Invalid null command"));
      if (!true_mem(prs, sizeof(t_prs)))
	sh->prs_list = rm_cur(sh->prs_list, &cur, &rm);
      cur = (cur && !rm) ? cur->next : cur;
      rm = (cur && !rm) ? 1 : 0;
    }
  return (true);
}

void		flag_tok(t_sh *sh, t_prs *prs, t_tok *tok)
{
  if ((tok->flag & CMD_COND))
    prs->cond |= tok->flag;
  else if ((tok->flag & PIPE))
    prs->piped |= tok->flag;
  sh->tok_list = rm_first_dlist(sh->tok_list, &free_token);
}

int		fill_prs_struct(t_sh *sh, t_prs *prs)
{
  t_tok		*tok;

  if (sh == NULL || prs == NULL || sh->tok_list == NULL)
    return (false);
  if ((tok = sh->tok_list->data) && (tok->flag & SEPARATOR))
    flag_tok(sh, prs, tok);
  while ((sh->tok_list != NULL && (tok = sh->tok_list->data) != NULL &&
	  (tok->flag & SEPARATOR) == false))
    {
      if (tok && (tok->flag & R_REDIR) && (do_r_redir(sh, prs, &tok)) == false)
	return (my_perror("Missing name for redirect"));
      else if ((tok && (tok->flag & L_REDIR)) &&
	       ((do_l_redir(sh, prs, &tok)) == false))
	return (my_perror("Missing name for redirect"));
      else if ((tok && (tok->flag & WORD)) &&
	       ((do_word_parsing(sh, prs, &tok)) == false))
	return (my_perror("do_word_parsing failed"));
    }
  prs->argv = t_slist_to_char_array(prs->argv_list);
  return (true);
}

int		parser(t_sh *sh)
{
  t_dlist	*cur;

  if (sh == NULL)
    return (false);
  if ((sh->tok_list == NULL)			   ||
      ((assign_tokens_types(sh->tok_list)) == false))
    return (false);
  while (sh != NULL && (sh->tok_list != NULL))
    {
      if (((sh->prs_list = add_dlist_elem(sh->prs_list)) == NULL) ||
	  ((cur = goto_last_dlist(sh->prs_list)) == NULL)	  ||
	  ((cur->data = gbgc_calloc(sizeof(t_prs))) == NULL))
	return (my_perror("could not allocate memory for a dlist element"));
      if ((fill_prs_struct(sh, cur->data)) == false)
	return (false);
    }
  finish_filling(sh->prs_list);
  if ((valid_line(sh)) == false)
    return (my_perror("syntax error"));
  return (true);
}

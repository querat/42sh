/*
** tokenizer.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Tue May  5 16:58:56 2015 gwendal querat
** Last update Sun May 24 16:07:00 2015 gwendal querat
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"
#include "my_process.h"
#include "my_colors.h"

void	free_token(void *data)
{
  t_tok	*tok;

  tok = data;
  if (tok == NULL)
    return ;
  if (tok->word)
    gbgc_free(NULL, tok->word);
  gbgc_free(NULL, tok);
}

void	skipspace(char *str, int *i)
{
  if (str == NULL)
    return ;
  while (str[(*i)] && (str[(*i)] == ' ' || str[(*i)] == '\t'))
    ++(*i);
}

void	print_token(void *data)
{
  t_tok	*tok;

  if ((tok = data) == NULL)
    return ;
  my_printf(L_CYAN"%s\n"WHITE, tok->word ? tok->word : L_MAGENTA"NULL");
}

char	**dlist_to_tab(t_dlist *list)
{
  char		**res;
  int		len;
  t_dlist	*cur;
  t_tok		*data;
  int		i;

  i = 0;
  res = NULL;
  len = dlist_len(list);
  if ((((cur = list) == NULL)				     ||
       (res = gbgc_calloc(sizeof(char*) * (len + 1))) == NULL))
    return (NULL);
  while ((cur))
    {
      if ((data = cur->data) != NULL)
	if ((res[i++] = my_strdup(data->word)) == NULL)
	  return (NULL);
      cur = cur->next;
    }
  i = 0;
  return (res);
}

t_dlist	*tokenizer(char *line, t_lnv *envlist)
{
  t_dlist	*list;
  t_dlist	*cur;
  int		i;
  char		*exp;

  i = 0;
  if (line == NULL || !line[(i)])
    return (NULL);
  list = NULL;
  if ((exp = expand_variables(line, envlist)) == NULL)
    return (NULL);
  while ((exp[i]))
    {
      skipspace(exp, &i);
      if (exp[i])
  	{
  	  if (((list = add_dlist_elem(list)) == NULL)	 ||
  	      ((cur = goto_last_dlist(list)) == NULL)	 ||
  	      ((cur->data = get_next_token(exp, &i)) == NULL))
  	    return (NULL);
  	}
    }
  gbgc_free(NULL, exp);
  return (list);
}

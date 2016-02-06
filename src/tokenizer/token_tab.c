/*
** token_tab.c for  in /home/querat_g/42sh/src/tokenizer
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Tue May  5 19:05:26 2015 gwendal querat
** Last update Wed May 13 14:03:24 2015 gwendal querat
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "tokenizer.h"
#include "shell.h"

static int	(*funcptr[15][2])(char*, int*, t_tok*) =
{
  {&is_backslash	, &get_word		},
  {&is_db_quote		, &get_word		},
  {&is_sp_quote		, &get_word		},
  {&is_db_left		, &get_db_left		},
  {&is_db_right		, &get_db_right		},
  {&is_sp_left		, &get_sp_left		},
  {&is_sp_right		, &get_sp_right		},
  {&is_oror		, &get_oror		},
  {&is_andand		, &get_andand		},
  {&is_pipe		, &get_pipe		},
  {&is_and		, &get_and		},
  {&is_semicolon	, &get_semicolon	},
  {&is_not_reserved_char, &get_word		},
  {NULL			, NULL			}
};

t_tok	*get_next_token(char *line, int *i)
{
  int	j;
  t_tok	*tok;

  j = 0;
  if ((tok = gbgc_calloc(sizeof(t_tok))) == NULL)
    return (NULL);
  while (funcptr[j][0])
    {
      if (((funcptr[j][CONDITION](line, i, tok))) == true)
	{
	  if (funcptr[j][EXECUTION])
	    {
	      if (((funcptr[j][EXECUTION](line, i, tok))) == false)
		return (NULL);
	      else
		return (epur_tok(tok));
	    }
	}
      j++;
    }
  my_perror("invalid token detected, aborting\n");
  (*i)++;
  return (NULL);
}

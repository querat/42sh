/*
** main.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Mon May  4 17:44:33 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

static int (*g_funcptr[RD_TAB][2])(t_line*, void*) =
{
  {&is_printable_char	, &concat_char		},
  {&is_backspace	, &backspace		},
  {&is_upkey		, &hist_up		},
  {&is_downkey		, &hist_down		},
  {&is_leftkey		, &move_cursor_left	},
  {&is_rightkey		, &move_cursor_right	},
  {&is_delete		, &delete_char		},
  {&is_begkey		, &cursor_beg		},
  {&is_endkey		, &cursor_end		},
  {&is_ctrlk		, &kill_buffer_end	},
  {&is_ctrlu		, &kill_buffer_beg	},
  {&is_ctrlr		, &hist_search		},
  {&is_ctrll		, &my_clear		},
  {&is_tab		, &autocomplete		},
  {&is_ctrly		, &cpy_kill		},
  {&is_ctrl_left	, &goto_word_left	},
  {&is_ctrl_right	, &goto_word_right	},
  {NULL			, NULL			}
};

int	        call_func_by_keycode(t_line *rdl)
{
  int		i;

  i = -1;
  while ((g_funcptr[++i][0]))
    {
      if (((g_funcptr[i][CONDITION__])(rdl, NULL)) == TRUE)
	{
	  if (((g_funcptr[i][INSTRUCTION])(rdl, NULL)) == FALSE)
	    return (FALSE);
	  else
	    return (TRUE);
	}
    }
  return (TRUE);
}

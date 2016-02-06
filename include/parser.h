/*
** parser.c for  in /home/querat_g/42sh
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May 15 17:34:47 2015 gwendal querat
** Last update Sun May 24 18:02:45 2015 gwendal querat
*/

#ifndef PARSER_H_
# define PARSER_H_

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
** parsing structure
*/
typedef struct	s_parse
{
  char		**argv;
  t_slist	*argv_list;
  int		stdout;
  char		*stdout_path;
  int		stdin;
  char		*stdin_path;
  int		stderr;
  char		*stderr_path;
  int		piped;
  int		piping;
  int		cond;
}		t_prs;

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
** redirections binary flags
*/
# define DB_LEFT	1
# define DB_RIGHT	2
# define SP_LEFT	4
# define SP_RIGHT	8
# define R_REDIR	(DB_RIGHT | SP_RIGHT)
# define L_REDIR	(DB_LEFT | SP_LEFT)

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
** basic separators / conditionnal separators / background separator
*/
# define OROR		16
# define ANDAND		32
# define AND		64
# define PIPE		128
# define SEMICOLON	256
# define SEPARATOR	(PIPE | SEMICOLON | OROR | ANDAND | AND)
# define CMD_COND	(ANDAND | OROR)

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
** ascii word flag
*/
# define WORD		512
/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
** functions prototypes
*/
int		do_r_redir(t_sh *sh, t_prs *prs, t_tok **tok);
int		do_l_redir(t_sh *sh, t_prs *prs, t_tok **tok);
int		do_word_parsing(t_sh *sh, t_prs *prs, t_tok **tok);

void		get_tok_type(t_tok *tok);
int		assign_tokens_types(t_dlist *list);

int		print_tab(char **);
void		my_puts(void *data);
void		print_parsed(void *data);

char		**t_slist_to_char_array(t_slist *list);

int		true_mem(void *data, int sz);

t_dlist		*rm_cur(t_dlist *list, t_dlist **cur, int *rm);

#endif		/* !parser.h */
